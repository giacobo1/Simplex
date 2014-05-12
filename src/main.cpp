#include "include/simplex.h"

int main(int argc, char const *argv[])
{

	float **matriz = (float **)malloc(sizeof(float**)*4);

	for (int i = 0; i < 5; i++)
		matriz[i] = (float*)malloc(sizeof(float*)*6);

	matriz[0][0] = -3.00;
	matriz[0][1] = -5.00;
	matriz[0][2] = 0.00;
	matriz[0][3] = 0.00;
	matriz[0][4] = 0.00;
	matriz[0][5] = 0.00;
	
	matriz[1][0] = 1.00;
	matriz[1][1] = 0.00;
	matriz[1][2] = 1.00;
	matriz[1][3] = 0.00;
	matriz[1][4] = 0.00;
	matriz[1][5] = 4.00;

	matriz[2][0] = 0.00;
	matriz[2][1] = 2.00;
	matriz[2][2] = 0.00;
	matriz[2][3] = 1.00;
	matriz[2][4] = 0.00;
	matriz[2][5] = 12.00;

	matriz[3][0] = 3.00;
	matriz[3][1] = 2.00;
	matriz[3][2] = 0.00;
	matriz[3][3] = 0.00;
	matriz[3][4] = 1.00;
	matriz[3][5] = 18.00;

	int *pos_result = calc_simplex(matriz, 4, 6);

	for (int i = 0; i < 4; i++)
	{
		if (pos_result[i])
			printf("X_%i = S_%d\n",i+1,pos_result[i]);
	}

	free(pos_result);
		
	return 0;	
}