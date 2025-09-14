#include <stdio.h>

int main() {
    int numero, numeroVolteado = 0;

    // Pedir al usuario que ingrese un número
    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    // Voltear el número
    while (numero != 0) {
        int digito = numero % 10;
        numeroVolteado = numeroVolteado * 10 + digito;
        numero /= 10;
    }

    // Imprimir el número volteado
    printf("El numero volteado es: %d\n", numeroVolteado);

    return 0;
}

