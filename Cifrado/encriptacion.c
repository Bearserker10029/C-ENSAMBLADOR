#include <stdio.h>
#include <math.h> // Necesario para fmod() y floor()

// --- Prototipos de Módulos Especificados ---

// Módulo 1: Verifica si el modo y el identificador cumplen las condiciones.
int verificar_modo_identificador(char modo, double id);

// Módulo 2: Valida si las iniciales (como códigos ASCII) son válidas.
int verificar_iniciales(int ascii_n, int ascii_p, int ascii_m);

// Módulo 3: Extrae los códigos ASCII y el DNI del identificador.
void extraer_datos(double id, int* ascii_n, int* ascii_p, int* ascii_m, double* dni);

// Función adicional para la lógica de encriptación.
void encriptar_y_mostrar(char modo, double id);


// --- Módulo Principal ---
int main() {
    double identificador;
    char modo;
    
    int ascii_n, ascii_p, ascii_m;
    double dni;

    // 1. Leer datos del usuario
    printf("Ingrese el identificador del participante: ");
    scanf("%lf", &identificador);
    printf("Identificador leido:%.0f\n", identificador);

    printf("Ingrese el modo de encriptación: ");
    scanf(" %c", &modo);

    // 2. Usar los módulos para validar y procesar
    if (verificar_modo_identificador(modo, identificador)) {
        // Extraer datos primero
        extraer_datos(identificador, &ascii_n, &ascii_p, &ascii_m, &dni);

        // Imprimir la información decodificada
        printf("Inicial nombre:%c\n", (char)ascii_n);
        printf("Inicial apellido paterno:%c\n", (char)ascii_p);
        printf("Inicial apellido materno:%c\n", (char)ascii_m);
        printf("DNI:%.0f\n", dni);
        printf("Usando el modo de encriptación %c\n", modo);

        // Ahora, validar las iniciales extraídas
        if (verificar_iniciales(ascii_n, ascii_p, ascii_m)) {
            // Si son válidas, proceder a la encriptación
            encriptar_y_mostrar(modo, identificador);
        } else {
            // Si no son válidas, imprimir el mensaje de error exacto
            printf("Iniciales inválidas");
        }
    }

    return 0;
}


// --- Implementación de Módulos ---

int verificar_modo_identificador(char modo, double id) {
    if (id < 1e13 || id >= 1e14) {
        printf("El identificador no cumple con los requerimientos\n");
        return 0;
    }
    if (modo != 'A' && modo != 'B' && modo != 'C') {
        printf("Modo inválido\n");
        return 0;
    }
    return 1;
}

void extraer_datos(double id, int* ascii_n, int* ascii_p, int* ascii_m, double* dni) {
    double divisor_dni = 1e8;
    double first_part = floor(id / divisor_dni);

    *dni = fmod(id, divisor_dni);
    *ascii_m = (int)fmod(first_part, 100);
    *ascii_p = (int)fmod(floor(first_part / 100), 100);
    *ascii_n = (int)floor(first_part / 10000);
}

// Este módulo ahora solo devuelve 1 o 0, no imprime nada.
int verificar_iniciales(int ascii_n, int ascii_p, int ascii_m) {
    if (!(ascii_n >= 65 && ascii_n <= 90 &&
          ascii_p >= 65 && ascii_p <= 90 &&
          ascii_m >= 65 && ascii_m <= 90)) {
        return 0; // No válidas
    }
    return 1; // Válidas
}

void encriptar_y_mostrar(char modo, double id) {
    double divisor_dni = 1e8;
    double dni = fmod(id, divisor_dni);
    double first_part = floor(id / divisor_dni);
    
    int p3 = (int)fmod(first_part, 100);
    int p2 = (int)fmod(floor(first_part / 100), 100);
    int p1 = (int)floor(first_part / 10000);

    printf("El identificador encriptado es:");

    switch (modo) {
        case 'A':
            printf("%.0f%02d%02d%02d\n", dni, p3, p2, p1);
            break;
        case 'B':
            printf("%02d%02d%02d%.0f\n", p3, p2, p1, dni);
            break;
        case 'C':
            printf("%02d%.0f%02d%02d\n", p1, dni, p3, p2);
            break;
    }
}
