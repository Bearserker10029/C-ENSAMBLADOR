#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int global_var = 42;

int main()
{
    int local_var = 24;
    void *heap_var = malloc(100);
    printf("Direccion de codigo: %p\n", (void *)main);
    printf("Direccion de global: %p\n", (void *)&global_var);
    printf("Direccion de local: %p\n", (void *)&local_var);
    printf("Direccion de heap: %p\n", (void *)heap_var);

    sleep(30);
    free(heap_var);

    return 0;
}
