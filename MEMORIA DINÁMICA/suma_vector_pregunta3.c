#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i;
    srand(time(NULL));
    int tam = 16;
    int vectorA[tam];

    for (i = 0; i < tam; i++)
    {
        vectorA[i] = rand() % 100;
    }

    int *vectorB = (int *)malloc(tam * sizeof(int));

    if (vectorB == NULL)
    {
        printf("No se inicializo la memoria para vectorB\n");
        exit(1);
    }
    else
    {
        printf("Se inicializo la memoria para vectorB\n");
    }

    for (i = 0; i < tam; i++)
    {
        vectorB[i] = rand() % 100;
    }

    int *vectorsuma = (int *)malloc(tam * sizeof(int));

    if (vectorsuma == NULL)
    {
        printf("No se inicializo la memoria para vectorsuma\n");
        exit(1);
    }
    else
    {
        printf("Se inicializo la memoria para vectorsuma\n");
    }

    for (i = 0; i < tam; i++)
    {
        vectorsuma[i] = vectorA[i] + vectorB[i];
    }
    printf("Vector A: ");
    for (i = 0; i < tam; i++)
    {
        printf("%d ", vectorA[i]);
    }
    printf("\nVector B: ");
    for (i = 0; i < tam; i++)
    {
        printf("%d ", vectorB[i]);
    }
    printf("\nVector Suma: ");
    for (i = 0; i < tam; i++)
    {
        printf("%d ", vectorsuma[i]);
    }
    printf("\nVector A Direcciones:\n");

    for (i = 0; i < tam; i++)
    {
        printf("%d %p\n", i, (void *)&vectorA[i]);
    }

    printf("\nVector B Direcciones:\n");

    for (i = 0; i < tam; i++)
    {
        printf("%d %p\n", i, (void *)&vectorB[i]);
    }

    printf("\nVector Suma Direcciones:\n");

    for (i = 0; i < tam; i++)
    {
        printf("%d %p\n", i, (void *)&vectorsuma[i]);
    }

    free(vectorB);
    free(vectorsuma);
    return 0;
}
