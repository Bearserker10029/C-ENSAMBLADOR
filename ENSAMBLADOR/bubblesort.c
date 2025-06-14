#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función que implementa el algoritmo Bubble Sort
void bubbleSort(int input[], int n, int output[]) {
    // Copiar el arreglo original al arreglo de salida
    for (int i = 0; i < n; i++) {
        output[i] = input[i];
    }

    // Aplicar Bubble Sort sobre el arreglo de salida
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            
            printf("\n");
            if (output[j] > output[j + 1]) {
                // Intercambio de elementos
                int temp = output[j];
                output[j] = output[j + 1];
                output[j + 1] = temp;
            }
            for(int k = 0; k < n; k++){

                printf("%d ", output[k]);
            }
            
        }
    }
}

int main(){

    int n=4096;
    int input[n];
    int output[n];
    struct timespec ti, tf;
    double elapsed;
    clock_gettime(CLOCK_REALTIME, &ti);
    for(int i = 0; i < n; i++){
        input[i]= (int)rand();

    }
    printf("Desordenado: ");
    for(int i = 0; i < n; i++){
        printf("%d ",input[i]);
    }
    printf("\nOrdenamiento");
    printf("\n");

    bubbleSort(input,n,output);
    printf("\n");
    printf("\nOrdenado: ");

    for(int i = 0; i < n; i++){
        printf("%d ",output[i]);
    }
    clock_gettime(CLOCK_REALTIME, &tf);
    elapsed = (tf.tv_sec - ti.tv_sec) * 1e9 + (tf.tv_nsec - ti.tv_nsec);
    printf("\nTiempo de ejecución %lf ns\n",elapsed);
    return 0;
}
