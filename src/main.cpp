#include "include/simplex.h"

int main(int argc, char const *argv[])
{

	/*
	float **matriz = (float **)malloc(sizeof(float**)*5);

	for (int i = 0; i < 5; i++)
		matriz[i] = (float*)malloc(sizeof(float*)*8);

	
	matriz[0][0] = -20.00;
	matriz[0][1] = -10.00;
	matriz[0][2] = -30.00;
	matriz[0][3] = 0.00;
	matriz[0][4] = 0.00;
	matriz[0][5] = 0.00;
	matriz[0][6] = 0.00;
	matriz[0][7] = 0.00;


	matriz[1][0] = 1.00;
	matriz[1][1] = 1.00;
	matriz[1][2] = 1.00;
	matriz[1][3] = 1.00;
	matriz[1][4] = 0.00;
	matriz[1][5] = 0.00;
	matriz[1][6] = 0.00;
	matriz[1][7] = 800.00;


	matriz[2][0] = 1.00;
	matriz[2][1] = 0.00;
	matriz[2][2] = 0.00;
	matriz[2][3] = 0.00;
	matriz[2][4] = 1.00;
	matriz[2][5] = 0.00;
	matriz[2][6] = 0.00;
	matriz[2][7] = 200.00;


	matriz[3][0] = 0.00;
	matriz[3][1] = 1.00;
	matriz[3][2] = 0.00;
	matriz[3][3] = 0.00;
	matriz[3][4] = 0.00;
	matriz[3][5] = 1.00;
	matriz[3][6] = 0.00;
	matriz[3][7] = 100.00;


	matriz[4][0] = 0.00;
	matriz[4][1] = 0.00;
	matriz[4][2] = 1.00;
	matriz[4][3] = 0.00;
	matriz[4][4] = 0.00;
	matriz[4][5] = 0.00;
	matriz[4][6] = 1.00;
	matriz[4][7] = 200.00;

	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%.1f\t",matriz[i][j] );
		}
		putchar('\n');
	}


	int *pos_result = calc_simplex(matriz, 5, 8);

	for (int i = 0; i < 5; i++)
	{
		if (pos_result[i])
			printf("X_%i = S_%d\n",i+1,pos_result[i]);
	}

	free(pos_result);
	
	for (int i = 0; i < 5; i++)free(matriz[i]);

	free(matriz);*/


	int linha, coluna;	
		
	float **matriz = parse_input_build_matrix(argv[1],&linha,&coluna);

	/*
	for (int i = 0; i < linha; i++)
	{
		for (int j = 0; j < coluna; j++)
			printf("%.1f\t",matriz[i][j]);
		putchar('\n');
	}*/

	int *pos_result = calc_simplex(matriz, linha, coluna);
	
	free(pos_result);
	

	// nao limpei a memoria por que:
	// http://stackoverflow.com/questions/6199729/how-to-solve-munmap-chunk-invalid-pointer-error-in-c
	//for (int i = 0; i < linha; i++)free( matriz[i]);

	//delete[] matriz;	

	
	return 0;	
}