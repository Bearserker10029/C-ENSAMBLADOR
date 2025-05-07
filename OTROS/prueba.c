#include <stdio.h>
#include <math.h>

void escanear(double *);
void calculo (double *, double );
double calculoz(double ,double );

int main(){

    double x,y,z;
    printf("ingrese un valor: ");
    escanear(&x);
    printf("%.2lf\n",x);
    calculo (&y,x);
    printf("%.2lf\n", y);
    z=calculoz(x,y);
    printf("%.2lf",z);
    return 0;
}
void escanear(double *x){
    scanf(" %lf",x);
}
void calculo (double *y, double x){
    *y=x+1;
}
double calculoz(double x,double y){
    return x+y;
}