#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *tamano[])
{
    int tam = atoi(tamano[1]);

    // printf("%d",tam);
    int *Arreglo = (int *)malloc(tam * sizeof(int));

    if (Arreglo == NULL)
    {
        printf("No se inicializó la memoria\n");
        exit(1);
    }
    else
    {
        printf("Se inicializó la memoria\n");
        int i;

        for (i = 0; i < tam; i++)
        {
            Arreglo[i] = rand() % (1000) + 1;
            printf("%d ", Arreglo[i]);
        }
        printf("\n");

        free(Arreglo);
    }

    return 0;
}
