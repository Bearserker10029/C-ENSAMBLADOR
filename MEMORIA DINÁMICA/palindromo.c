#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char cadena[100];
    while (1)
    {
        printf("Ingrese una cadena de caracteres: ");
        scanf("%s", cadena);
        int longitud = strlen(cadena);
        printf("La longitud de la cadena es: %d\n", longitud);
        char *cadena_invertida = (char *)malloc((longitud+1) * sizeof(char));
        int i;
        for (i = 0; i < longitud; i++)
        {
            cadena_invertida[i] = cadena[longitud - 1 - i];
        }
        cadena_invertida[longitud] = '\0';
        printf("La cadena invertida es: %s\n", cadena_invertida);
        if (cadena == cadena_invertida)
        {
            printf("La cadena es un palindromo.\n");
        }
        else
        {
            printf("La cadena no es un palindromo.\n");
        }
        free(cadena_invertida);
    }
    return 0;
}