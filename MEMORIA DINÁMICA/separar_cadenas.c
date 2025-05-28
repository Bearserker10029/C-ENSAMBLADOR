#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void separar_cadenas(char cadenaoriginal[], int longitud, char *cadena1, char *cadena2)
{
    int i = 0;
    for (i; i < longitud; i++)
    {
        if (cadenaoriginal[i] == ' ')
        {
            break;
        }
        cadena1[i] = cadenaoriginal[i];
    }
    int k = i + 1;
    int j = 0;

    for (k; k < longitud; k++)
    {
        cadena2[j] = cadenaoriginal[k];
        j++;
    }
}

int main()
{
    char cadenaoriginal[100];
    printf("Ingrese la cadena de palabras: ");
    scanf("%[^\n]", cadenaoriginal);
    int longitud = strlen(cadenaoriginal);
    char *cadena1 = (char *)calloc((longitud), sizeof(char));
    char *cadena2 = (char *)calloc((longitud), sizeof(char));
    separar_cadenas(cadenaoriginal, longitud, cadena1, cadena2);

    printf("Cadena original: %s\n", cadenaoriginal);
    printf("Cadena 1: %s\n", cadena1);
    printf("Cadena 2: %s\n", cadena2);

    free(cadena1);
    free(cadena2);
    return 0;
}