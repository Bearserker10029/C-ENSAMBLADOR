#include <stdio.h>

 int main() { 
    int a, b, a_es_mayor_que_b;
    printf("Ingrese dos valores (a b): "); 
    scanf("%d %d", &a, &b); 
    a_es_mayor_que_b = a > b;
    printf("a es mayor que b (1:Verdadero, 0:Falso): %d\n", a_es_mayor_que_b); 
    return 0;
}