#include <stdio.h>
#include <math.h>
#define PI 3.141592

int main()
{
    double altura1, altura2, area1, area2, radio1, radio2, volumen1, volumen2;
    int mayor_cilindro1, mayor_cilindro2;

    printf("Ingrese la altura del cilindro 1: ");
    scanf(" %lf", &altura1);
    printf("Ingrese la altura del cilindro 2: ");
    scanf(" %lf", &altura2);

    radio1 = altura1 / (2 * PI);
    radio2 = altura2 / (2 * PI);
    area1 = 2 * PI * radio1 * (altura1 + radio1);
    area2 = 2 * PI * radio2 * (altura2 + radio2);
    volumen1 = PI * pow(radio1, 2) * altura1;
    volumen2 = PI * pow(radio2, 2) * altura2;

    mayor_cilindro1 = volumen1 >= volumen2;
    mayor_cilindro2 = volumen2 > volumen1;

    printf("Resultados del Cilindro 1: \n");
    printf("Área: %.2lf\n", area1);
    printf("Volumen: %.2lf\n\n", volumen1);
    printf("Resultados del Cilindro 2: \n");
    printf("Área: %.2lf\n", area2);
    printf("Volumen: %.2lf\n\n", volumen2);
    printf("El cilindro %d tiene mayor volumen", 1 * mayor_cilindro1 + 2 * mayor_cilindro2);
    return 0;
}