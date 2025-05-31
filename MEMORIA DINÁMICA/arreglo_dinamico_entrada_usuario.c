#include <stdio.h>
#include <stdlib.h>

int main()
{

    int valores, activar = 1;
    int *Arreglo = (int *)calloc(2, sizeof(int));

    if (Arreglo == NULL)
    {
        printf("No se inicializó la memoria\n");
        exit(1);
    }
    else
    {
        printf("Se inicializó la memoria\n");
        int j = 0;
        int i;
        while (activar)
        {
            printf("Ingrese los valores: ");
            scanf("%d", &valores);
            if (valores == -1)
            {
                activar = 0;
                free(Arreglo);
                printf("Se ha terminado el programa.\n");
            }
            else
            {
                Arreglo[j] = valores;

                for (i = 0; i <= j; i++)
                {
                    printf("%d ", Arreglo[i]);
                }
                printf("\n");

                j++;
                Arreglo = realloc(Arreglo, j * sizeof(int));
            }
        }
    }

    return 0;
}