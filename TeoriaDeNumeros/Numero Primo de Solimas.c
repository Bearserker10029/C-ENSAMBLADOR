#include <stdio.h>
#include <math.h>

void evaluarPrimoSolinas(int,int );
int calcularMostrarPrimos(int ,int );
void verificarImprimirPrimo(int ,int ,char ,char ,int *,int *);
int calcularOperacion(int ,int ,char ,char );
void imprimirOperacion(int ,int , char ,char ,int );
int verificarPrimo(int );

int main(){
    int inicio,fin;
    do{
        printf("----------------------\n");
        printf("Ingrese el rango para los exponentes, 2<=rango<=20, ingrese 0 en ambos para terminar: ");
        scanf(" %d %d",&inicio,&fin);
        if (inicio>=2 && fin>inicio && fin<=20)
            evaluarPrimoSolinas(inicio,fin);
        else
            if (inicio==0 && fin==0){
                printf("Fin de la evaluacion\n");
                break;
            }
            else
                printf("Rango incorrecto\n");
    }while(1);
}

void evaluarPrimoSolinas(int inicio,int fin){
    int esPrimo,i,j,primo,cant,suma=0;
    char signo1,signo2;
    for (i=inicio;i<=fin;i++)
        for (j=inicio;j<=fin;j++)
            if (i>j){
                printf("Evaluacion de los exponentes %d y %d\n",i,j);
                cant=calcularMostrarPrimos(i,j);
                if (cant==4)
                    printf("Las cuatro combinaciones de operaciones con los exponentes %d y %d dan como resultado numeros primos de Solimas\n",i,j);
                else
                    if (cant>1)
                        printf("Solo %d combinaciones de operaciones con los exponentes %d y %d dan como resultado numeros primos de Solimas\n",cant,i,j);
                    else
                        if (cant==1)
                            printf("Solo una combinacion de operaciones con los exponentes %d y %d da como resultado un numero primo de Solimas\n",i,j);
                        else
                            printf("Ninguna combinacion de operaciones con los exponentes %d y %d da como resultado un numero primo de Solimas\n",i,j);
                suma+=cant;
            }
    printf("----------------------\n");
    printf("Se encontraron %d operaciones para hallar numeros primos de Solimas con exponentes en el rango [ %d, %d]\n",suma,

inicio,fin);
}

int calcularMostrarPrimos(int a,int b){
    int num1,num2,num3,num4,esPrimoCalc1,esPrimoCalc2,esPrimoCalc3,esPrimoCalc4;
    int calculo1,calculo2,calculo3,calculo4;
    verificarImprimirPrimo(a,b,'+','+',&esPrimoCalc1,&calculo1);
    verificarImprimirPrimo(a,b,'+','-',&esPrimoCalc2,&calculo2);
    verificarImprimirPrimo(a,b,'-','+',&esPrimoCalc3,&calculo3);
    verificarImprimirPrimo(a,b,'-','-',&esPrimoCalc4,&calculo4);
    if (esPrimoCalc1)
        imprimirOperacion(a,b,'+','+',calculo1);
    if (esPrimoCalc2)
        imprimirOperacion(a,b,'+','-',calculo2);
    if (esPrimoCalc3)
        imprimirOperacion(a,b,'-','+',calculo3);
    if (esPrimoCalc4)
        imprimirOperacion(a,b,'-','-',calculo4);
    return esPrimoCalc1+esPrimoCalc2+esPrimoCalc3+esPrimoCalc4;
}

void verificarImprimirPrimo(int a,int b,char signo1,char signo2,int *esPrimo,int *calculo){
    *calculo=calcularOperacion(a,b,signo1,signo2);
    *esPrimo=verificarPrimo(*calculo);
}

int calcularOperacion(int a,int b,char signo1,char signo2){
    int num,calc;
    calc=pow(2,a);
    if (signo1=='+')
        calc+=pow(2,b);
    else
        calc-=pow(2,b);
    if (signo2=='+')
        calc+=1;
    else
        calc-=1;
    return calc;
}

void imprimirOperacion(int a,int b, char signo1,char signo2,int calculo){
    printf(" %d = 2^%d %c 2^%d %c 1\n",calculo,a,signo1,b,signo2);
}

int verificarPrimo(int numero){
    int cantDivisores=0,i=1;
    while (i<=numero){
        if (numero %i==0)
            cantDivisores++;
        i++;
    }
    return cantDivisores==2;
}
