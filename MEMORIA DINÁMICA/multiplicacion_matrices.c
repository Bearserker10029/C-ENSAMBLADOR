#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    // printf("%d",N);
    // printf("%d",M);
    int *matrizN = (int *)malloc(N * sizeof(int));
    int *matrizM = (int *)malloc(M * sizeof(int));

    if (matrizN == NULL)
    {
        printf("No se inicializó la memoria matriz N\n");
        exit(1);
    }
    else
    {
        printf("Se inicializó la memoria matriz N\n");
    }

    if (matrizM == NULL)
    {
        printf("No se inicializó la memoria matriz M\n");
        exit(1);
    }
    else
    {
        printf("Se inicializó la memoria matriz M\n");
        int i;
        printf("La matriz N es:\n");
        for (i = 0; i < N; i++)
        {
            matrizN[i] = rand() % 10;
            printf("%d ", matrizN[i]);
        }
        printf("\n");
        printf("La matriz M es:\n");

        for (i = 0; i < M; i++)
        {
            matrizM[i] = rand() % 10;
            printf("%d ", matrizM[i]);
        }

        printf("\nLa matriz NxM es:\n");
        int *MatrizNxM = (int *)malloc((N * M) * sizeof(int));

        if (MatrizNxM == NULL)
        {
            printf("No se inicializó la memoria matriz NxM\n");
            exit(1);
        }
        else
        {
            printf("Se inicializó la memoria matriz NxM\n");
        }
        int j;

        for (i = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
            {
                MatrizNxM[j] = matrizN[i] * matrizM[j];
                printf("%d ", MatrizNxM[j]);
            }
            printf("\n");
        }

        free(matrizM);
        free(matrizN);
        free(MatrizNxM);
    }

    return 0;
}