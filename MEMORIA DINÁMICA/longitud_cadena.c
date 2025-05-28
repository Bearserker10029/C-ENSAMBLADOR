#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N = 100;
    char cadena[N];
    printf("Ingrese una cadena de caracteres: ");
    int resultado = scanf("%s", cadena);
    int longitud = strlen(cadena);
    printf("La longitud de la cadena es: %d\n", longitud);
    return 0;
}