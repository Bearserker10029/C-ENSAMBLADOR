#include <stdio.h>
#include <math.h>
#define PI 3.141592

int main()
{
    double altura1, altura2, area1, area2, radio1, radio2, volumen1, volumen2, diametro1, diametro2;
    double generatriz1, generatriz2, areaLateral1, areaLateral2, areaCirculo1, areaCirculo2;
    int mayor_cono1, mayor_cono2;

    printf("Ingrese el diámetro y la generatriz del cono 1: ");
    scanf(" %lf %lf", &diametro1, &generatriz1);
    printf("Ingrese el diámetro y la generatriz del cono 2: ");
    scanf(" %lf %lf", &diametro2, &generatriz2);

    radio1 = diametro1 / 2;
    radio2 = diametro2 / 2;
    areaLateral1 = PI * radio1 * generatriz1;
    areaLateral2 = PI * radio2 * generatriz2;
    areaCirculo1 = PI * pow(radio1, 2);
    areaCirculo2 = PI * pow(radio2, 2);
    area1 = areaLateral1 + areaCirculo1;
    area2 = areaLateral2 + areaCirculo2;
    altura1 = sqrt(pow(generatriz1, 2) - pow(radio1, 2));
    altura2 = sqrt(pow(generatriz2, 2) - pow(radio2, 2));
    volumen1 = (PI * pow(radio1, 2) * altura1) / 3;
    volumen2 = (PI * pow(radio2, 2) * altura2) / 3;

    mayor_cono1 = altura1 >= altura2;
    mayor_cono2 = altura2 > altura1;

    printf("Resultados del Cono 1: \n");
    printf("Altura: %.2lf\n", altura1);
    printf("Área Total: %.2lf\n", area1);
    printf("Volumen: %.2lf\n\n", volumen1);
    printf("Resultados del Cono 2: \n");
    printf("Altura: %.2lf\n", altura2);
    printf("Área: %.2lf\n", area2);
    printf("Volumen: %.2lf\n\n", volumen2);
    printf("El cono %d tiene mayor altura", 1 * mayor_cono1 + 2 * mayor_cono2);
    return 0;
}