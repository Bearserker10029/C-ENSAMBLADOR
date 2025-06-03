#include <stdio.h>
#include <stdlib.h>

void matriz_lineal(int *matriz, int filas, int columnas);
void matriz_doble(int **matriz, int filas, int columnas);
int main()
{
    int filas = 3, columnas = 4;
    int *matriz_lineal_array = (int *)malloc(filas * columnas * sizeof(int));

    int **matriz_doble_array = (int **)malloc(filas * sizeof(int *));
    for (int i = 0; i < filas; i++)
    {
        matriz_doble_array[i] = malloc(columnas * sizeof(int));
    }

    // Impresión de matriz lineal
    matriz_lineal(matriz_lineal_array, filas, columnas);
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("%d ", matriz_lineal_array[i * columnas + j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("%p ", &matriz_lineal_array[i * columnas + j]);
        }
        printf("\n");
    }

    // Impresion de matriz doble
    matriz_doble(matriz_doble_array, filas, columnas);
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("%d ", matriz_doble_array[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("%p ", &matriz_doble_array[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < filas; i++)
    {
        printf("%p ", &matriz_doble_array[i]);
    }
    printf("\n");

    printf("%ld \n", sizeof(int *));

    return 0;
}

void matriz_lineal(int *matriz, int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz[i * columnas + j] = i * columnas + j;
        }
    }
}

void matriz_doble(int **matriz, int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz[i][j] = i * columnas + j;
        }
    }
}