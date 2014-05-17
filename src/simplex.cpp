#include "include/simplex.h"

// definir melhor o input file... mas ta no caminho


// essa função precisa retornar lina/coluna tb..
float ** parse_input_build_matrix(const char *argv, int *l, int *c)
{
	
	float ** matrix;

	int columns, lines;

	bool max  = false;
	bool rest = false;
	bool eq   = false;

    float coef  = 0.0;
    
    int index_column	= 0; 
    int index_line  	= 0;
    int s_index_offset 	= 0;
    
    char input_line[256];
    
    FILE *fp;

    if ((fp = fopen(argv, "r")) == NULL)
    {
    	printf("Erro ao abrir o arquivo.\n");
    	exit(2);
    }

    while ( fscanf(fp,"%s\n",input_line) > 0)
    {

    	if (input_line[0] == '[') 
    	{
    		sscanf(input_line,"[%dx%d]",&lines,&columns);
    		matrix = new float*[lines];
    		for (int i = 0; i < lines; ++i)matrix[i] = new float[columns];
    	}
    	else if (!strcmp(input_line,"Restrictions"))
    	{
    		rest = true;
    		index_line++;
    	}
    	else if (!strcmp(input_line,"maximize"))
    	{
    		max = true;
    	}
    	else if (!rest)
    	{
    		if (strcmp(input_line,"+") > 0 || strcmp(input_line,"-") > 0)
    		{
    			if (max)
	    		{
	    			sscanf(input_line,"%f*X_%d",&coef, &index_column);
	    			// assumindo que se passe de X_1 para cima..
	    			matrix[index_line][index_column-1] = -1 * coef;
	    			s_index_offset++;
	    		}
	    		else
	    		{
	    			sscanf(input_line,"%f*X_%d",&coef, &index_column);
	    			matrix[index_line][index_column-1] = coef;
	    			s_index_offset++;
	    		}
    		}    		
    	}
    	else if (!strcmp(input_line, "<=") || !strcmp(input_line, "=<") || !strcmp(input_line, "<")|| !strcmp(input_line, ">") || !strcmp(input_line, "=") )
    	{
    		eq = true;
    	}
    	else
    	{
    		if (strcmp(input_line,"+") > 0 || strcmp(input_line,"-") > 0 )
    		{
    			if (!eq)
	    		{
	    			sscanf(input_line,"%f*X_%d",&coef, &index_column);
	    			// assumindo que se passe de X_1 para cima..
	    			matrix[index_line][index_column-1] = coef;
	    		
	    		}
	    		else
	    		{
	    			sscanf(input_line,"%f",&coef); // pode dar merda
	    			matrix[index_line][columns-1] = coef;
	    			matrix[index_line][s_index_offset] = 1.0;
	    			eq = false;
	    			index_line++;
	    			s_index_offset++;
	    		}
    		}
    	}
    	
    }

    /*
    for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
			printf("%.1f\t",matrix[i][j]);
		putchar('\n');
	}*/

    *l = lines;
    *c = columns;

	fclose(fp);

	return matrix;

}


// aprovads :)
bool find_entry_var(float** matrix,int lines,int columns, int* leaving)
{
	bool _ret = false;

	int min = std::numeric_limits<float>::min();

	int i = 0;
	for (i; i < columns; i++)
	{
		if (matrix[0][i] < 0)
		{
			float entry_var = abs(matrix[0][i]);

			if (entry_var > min)
			{				
				min = entry_var;
				*leaving = i;
			}

			_ret = true;
		}		 
	}

	return _ret;
}

int find_leaving_var(float** matrix,int lines,int columns, int* leaving)
{
	int _ret = 0;

	float min = std::numeric_limits<float>::max();
	
	for (int i = 1; i < lines; i++)
	{		
		if (matrix[i][*leaving] != 0)
		{
			if (abs((float)(matrix[i][columns-1]/matrix[i][*leaving]) )< min )
			{
				min  = abs((float)(matrix[i][columns-1]/matrix[i][*leaving]) );
				_ret = i;				
			}	
		}	
	}
	

	return _ret;
}
void erase_pivot_column(float** matrix,int lines,int columns,int piv ,int* leaving)
{
	
	int j = piv;
	j = (j+1) % lines;

	float pivot_value = matrix[piv][*leaving];

	while (j != piv)
	{
		if (matrix[j][*leaving] != 0)
		{
			if ( (matrix[j][*leaving] - pivot_value) == 0 )
			{
				
				for(int i = *leaving; i <= columns; i++)
				{
					matrix[j][i] = matrix[j][i] - matrix[piv][i];
				}
			}
			else if (matrix[j][*leaving] < 0)
			{	
				float factor = (float)((abs(matrix[j][*leaving]))/pivot_value);			
				
				int i = *leaving;
				i = (i + 1) % columns;

				for(int i = *leaving; i <=columns; i++)
				{
					matrix[j][i] = matrix[j][i] + (factor * matrix[piv][i]);
				}
			}
			else if (matrix[j][*leaving] > 0)
			{
				float factor = (float)((abs(matrix[j][*leaving]))/pivot_value);			
				
				int i = *leaving;
				i = (i + 1) % columns;
			
				for(int i = *leaving; i <=columns; i++)
				{
					matrix[j][i] = matrix[j][i] - (factor * matrix[piv][i]);
				}
			}	
		}			

		j= (j+1) % lines;
	}	

	for (int i = *leaving; i <= columns; i++)
	{
		matrix[piv][i] = (float) matrix[piv][i]/pivot_value; 
	}		
	

	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			printf("%.1f\t",matrix[i][j] );
		}
		putchar('\n');
	}
	printf("\n\n\n");
}


void calc_simplex(float **matrix, int lines, int columns)
{

	bool _continue = true;

	int leaving_var_colum = 0;

	int pivot = 0;

	int step = 1;

	int* solution_position = (int*)malloc(sizeof(int) * lines);
	
	// nao sei por que o malloc/new nao estao zerando...
	for (int i = 0; i < lines; i++)solution_position[i] = 0;	
	
	while (_continue)
	{		
		_continue = find_entry_var(matrix, lines, columns, &leaving_var_colum);

		if (_continue)
		{				
			pivot 	  =	find_leaving_var(matrix, lines, columns,&leaving_var_colum);
			solution_position[leaving_var_colum] = pivot;

			printf("Passo: %d\n",step++);	

			erase_pivot_column(matrix, lines, columns,pivot ,&leaving_var_colum);

		}
		
	}

	printf("\tTotal: %.2f\n", matrix[0][columns-1]);

	for (int i = 0; i < lines; i++)
	{
		
		if (solution_position[i])
		{
			printf(" X_%d --> S_%d and X_%d = %.1f\n", i+1, solution_position[i],i+1, matrix[solution_position[i]][columns-1]);
		}
	}


	free(solution_position);

	//delete solution_position;

}