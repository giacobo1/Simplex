#include "include/simplex.h"

int main(int argc, char const *argv[])
{

	if (argc == 2)
	{
		int linha, coluna;	
			
		float **matriz = parse_input_build_matrix(argv[1],&linha,&coluna);

		calc_simplex(matriz, linha, coluna);
		


		// nao limpei a memoria por que:
		// http://stackoverflow.com/questions/6199729/how-to-solve-munmap-chunk-invalid-pointer-error-in-c
		//for (int i = 0; i < linha; i++)free( matriz[i]);

		//delete[] matriz;
	}
	else
	{
		printf("Erro na passagem de argumentos.\n");
		exit(1);
	}

	return 0;	
}