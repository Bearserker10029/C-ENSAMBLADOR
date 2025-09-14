#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ELEMENTOS 100

// Prototipos de funciones
void bubbleSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
int particionQuick(int arr[], int low, int high);
void mergeSort(int arr[], int left, int right);
void mezclaMerge(int arr[], int left, int mid, int right);
void imprimirArray(int arr[], int size);
void copiarArray(int origen[], int destino[], int n);

int main() {
    int n, numeros[MAX_ELEMENTOS], copia[MAX_ELEMENTOS];
    int opcion;
    clock_t inicio, fin;
    double tiempo;
    char buffer[1024];

    // Entrada de datos
    printf("Ingrese la cantidad de numeros a ordenar (1-100): ");
    scanf("%d", &n);
    
    // Limpiar buffer de entrada
    int c;
    while((c = getchar()) != '\n' && c != EOF);

    if(n < 1 || n > MAX_ELEMENTOS) {
        printf("Cantidad invalida! Debe ser entre 1 y 100\n");
        return 1;
    }

    // Leer todos los números en una línea
    printf("\nIngrese los %d numeros separados por espacios: ", n);
    fgets(buffer, sizeof(buffer), stdin);

    // Convertir la entrada a números
    int i = 0;
    char *token = strtok(buffer, " \n");
    while(token != NULL && i < n) {
        numeros[i++] = atoi(token);
        token = strtok(NULL, " \n");
    }

    // Validar cantidad de números ingresados
    if(i != n) {
        printf("Error: Se ingresaron %d numeros en lugar de %d\n", i, n);
        return 1;
    }

    // Menú de selección
    printf("\nSeleccione el algoritmo de ordenamiento:\n");
    printf("1. Bubble Sort\n");
    printf("2. QuickSort\n");
    printf("3. Merge Sort\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    // Hacer una copia para preservar los originales
    copiarArray(numeros, copia, n);

    // Ejecutar el algoritmo seleccionado
    switch(opcion) {
        case 1:
            inicio = clock();
            bubbleSort(copia, n);
            fin = clock();
            break;
        case 2:
            inicio = clock();
            quickSort(copia, 0, n-1);
            fin = clock();
            break;
        case 3:
            inicio = clock();
            mergeSort(copia, 0, n-1);
            fin = clock();
            break;
        default:
            printf("Opcion invalida!\n");
            return 1;
    }

    // Calcular tiempo transcurrido
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    // Mostrar resultados
    printf("\nArray ordenado:\n");
    imprimirArray(copia, n);
    printf("\nTiempo de ordenamiento: %.6f segundos\n", tiempo);

    return 0;
}

// Implementaciones de los algoritmos y funciones auxiliares (igual que antes)
// ... (mantener las mismas implementaciones de bubbleSort, quickSort, mergeSort, etc)
