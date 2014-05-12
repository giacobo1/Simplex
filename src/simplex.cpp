#include "include/simplex.h"


bool find_entry_var(float** matrix,int lines,int columns, int* leaving)
{
	bool _ret = false;

	int min = std::numeric_limits<int>::min();

	for (int i = 0; i < columns; i++)
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
			if ((matrix[i][columns]/matrix[i][*leaving]) < min )
			{
				min  = (matrix[i][*leaving]/matrix[i][columns]);
				_ret = i;
			}	
		}
		
	}

	return _ret;
}
void erase_pivot_column(float** matrix,int lines,int columns,int piv ,int* leaving)
{
	
	int j = piv++;

	while (j != piv)
	{
		if (matrix[j][*leaving] != 0)
		{
			if ( (matrix[j][*leaving] - matrix[piv][*leaving]) == 0 )
			{
				for(int i = *leaving; i < lines; i++)
				{
					matrix[j][i] = matrix[j][i] - matrix[piv][i];
				}
			}
			else
			{
				float factor = matrix[j][*leaving]/matrix[piv][*leaving];
				for(int i = *leaving; i < lines; i++)
				{
					matrix[j][i] = matrix[j][i] +  (factor * matrix[piv][i]);
				}
			}	
		}			

		j= (j+1) % lines;
	}

		// pivot line  put 1
	for (int i = *leaving; i < lines; i++)
	{
		matrix[piv][i] = matrix[piv][i]/matrix[piv][*leaving]; 
	}
}





int* calc_simplex(float **matrix, int lines, int columns)
{
	bool _continue = true;

	int leaving_var_colum = 0;

	int pivot = 0;

	int* solution_position = (int*)malloc(sizeof(int) * lines);

	solution_position[0] = 0; // solution to Z 

	while (_continue)
	{
		_continue = find_entry_var(matrix, lines, columns, &leaving_var_colum);
		
		if (_continue)
		{				
			pivot 	  =	find_leaving_var(matrix, lines, columns,&leaving_var_colum);
			solution_position[leaving_var_colum] = pivot;

			erase_pivot_column(matrix, lines, columns,pivot ,&leaving_var_colum);
		}

	}

	// ou printar a solução
	return solution_position;
}












// ta uma bosta
/* refazer este parser falho :(
std::vector< std::vector<float> > readInput(const char *argv)
{
	using namespace std;

	std::vector< std::vector<float> > __ret;

	std::vector<float> B;

	ifstream fp(argv);

	string tmp;

	unsigned int numOfbasics = 0;

	if (fp.is_open())
	{
		while (!fp.eof())
		{			
			getline(fp,tmp);

			if (tmp == "Objective")
			{

				__ret.push_back(std::vector<float>());

				std::vector< std::vector<float> >::iterator line = __ret.begin();

				while (tmp != "Restriction")
				{
					getline(fp, tmp, ' ');
					
					(*line).push_back(atof(tmp.c_str()));
					if(tmp == "Restriction")break;
				}
				cout << tmp << endl;				

				bool readEqual = false;
				while (tmp != "end")
				{	
					__ret.push_back(std::vector<float>());
					line++;
					if (!readEqual)
					{
						while (getline(fp, tmp, '='))
						{
							if (tmp != " ")
							{
								(*line).push_back(atof(tmp.c_str()));
							}
						}
						readEqual = true;
						
					}

					if (tmp == "=")
					{
						readEqual = true;
					}

					if(readEqual)
					{
						getline(fp, tmp);

						if ( tmp != "end")
						{							
							B.push_back(atof(tmp.c_str()));
							readEqual = false;	
						}
					}
				}
				
						
				 
			}
			
			

			//cout << tmp << endl;
		}
	}

	fp.close();

	return __ret;
}
*/