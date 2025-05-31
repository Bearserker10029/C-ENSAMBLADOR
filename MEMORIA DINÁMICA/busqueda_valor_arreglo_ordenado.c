#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N = 20;
    int valor;
    printf("Ingrese el valor:");
    scanf("%d", &valor);

    int *Arreglo = (int *)malloc(N * sizeof(int));

    if (Arreglo == NULL)
    {
        printf("No se inicializó la memoria\n");
        exit(1);
    }
    else
    {
        printf("Se inicializó la memoria\n");
    }

    int i;

    for (i = 0; i < N; i++)
    {
        Arreglo[i] = rand() % (1000) + 1;
        printf("%d ", Arreglo[i]);
    }

    printf("\n");
    int j, temp;
    for (i = 0; i < N - 1; i++)
    {
        for (j = 0; j < N - i - 1; j++)
        {
            if (Arreglo[j] > Arreglo[j + 1])
            {
                temp = Arreglo[j];
                Arreglo[j] = Arreglo[j + 1];
                Arreglo[j + 1] = temp;
            }
        }
    }
    printf("Arreglo ordenado\n");
    for (i = 0; i < N; i++)
    {
        printf("%d ", Arreglo[i]);
    }
    printf("\n");
    for (i = 0; i < N; i++)
    {
        if (valor == Arreglo[i])
        {
            printf("Se ha encontrado el valor %d en el arreglo %d.\n", valor, i);
        }
        else
        {
            printf("No se encontró el valor de %d en el arreglo %d.\n", valor, i);
        }
    }
    free(Arreglo);
    return 0;
}