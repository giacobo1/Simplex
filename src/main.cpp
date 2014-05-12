#include "include/simplex.h"

int main(int argc, char const *argv[])
{

	float matriz[4][6];

	matriz[0][0] = -3.0;
	matriz[0][1] = -3.0;
	matriz[0][2] = -3.0;
	matriz[0][3] = -3.0;
	matriz[0][4] = -3.0;
	matriz[0][5] = -3.0;
	
	matriz[1][0] = -3.0;
	matriz[1][1] = -3.0;
	matriz[1][2] = -3.0;
	matriz[1][3] = -3.0;
	matriz[1][4] = -3.0;
	matriz[1][5] = -3.0;

	matriz[2][0] = -3.0;
	matriz[2][1] = -3.0;
	matriz[2][2] = -3.0;
	matriz[2][3] = -3.0;
	matriz[2][4] = -3.0;
	matriz[2][5] = -3.0;

	matriz[3][0] = -3.0;
	matriz[3][1] = -3.0;
	matriz[3][2] = -3.0;
	matriz[3][3] = -3.0;
	matriz[3][4] = -3.0;
	matriz[3][5] = -3.0;





	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 6; k++)
		{
			printf("%d ",matriz[i][k]);
		}
			
		putchar('\n');
	}
		
	return 0;	
}