#include <stdio.h>
#include <math.h>

int main()
{
    double a1, b1, c1, a2, b2, c2;
    double diagonal1, diagonal2, area1, area2, volumen1, volumen2;
    int menor_ortoedro1, menor_ortoedro2;

    printf("Ingrese los lados a, b y c del ortoedro 1: ");
    scanf(" %lf %lf %lf", &a1, &b1, &c1);
    printf("Ingrese los lados a, b y c del ortoedro 2: ");
    scanf(" %lf %lf %lf", &a2, &b2, &c2);

    diagonal1 = sqrt(pow(a1, 2) + pow(b1, 2) + pow(c1, 2));
    diagonal2 = sqrt(pow(a2, 2) + pow(b2, 2) + pow(c2, 2));
    area1 = 2 * (a1 * b1 + a1 * c1 + b1 * c1);
    area2 = 2 * (a2 * b2 + a2 * c2 + b2 * c2);
    volumen1 = a1 * b1 * c1;
    volumen2 = a2 * b2 * c2;

    menor_ortoedro1 = diagonal1 <= diagonal2;
    menor_ortoedro2 = diagonal2 < diagonal1;

    printf("Resultados del Ortoedro 1 : \n");
    printf("Diagonal : %.2lf\n", diagonal1);
    printf("Área : %.2lf\n", area1);
    printf("Volumen : %.2lf\n\n", volumen1);
    printf("Resultados del Ortoedro 2 : \n");
    printf("Diagonal : %.2lf\n", diagonal2);
    printf("Área : %.2lf\n", area2);
    printf("Volumen : %.2lf\n\n", volumen2);
    printf("El ortoedro %d tiene menor diagonal", 1 * menor_ortoedro1 + 2 * menor_ortoedro2);
    return 0;
}