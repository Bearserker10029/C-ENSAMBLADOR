#include <stdio.h>

int calcularFibonacciPosicion(int );
int buscarPosFibonacciCercana(int );
int encontrarMostrarSeriesFibonacci(int );
void imprimirSeries(int ,int ,int );

int main(){
    int inicio,fin,i=1,fibo,cantSumas,cantNumerosZeck=0;
    printf("Ingrese el rango:");
    scanf(" %d %d",&inicio,&fin);
    if (inicio>0 && inicio<fin){
        for (i=inicio;i<=fin;i++){
            cantSumas=encontrarMostrarSeriesFibonacci(i);
            if (cantSumas>0)
                cantNumerosZeck++;
            if (cantSumas==0)
                printf("No se encuentran series de sumas para el numero %d\n",i);
            else
                printf("Se encontraron %d series de sumas para el numero %d\n",cantSumas,i);
        }
        printf("-------------------\n");
        if (fin-inicio+1==cantNumerosZeck)
            printf("En el rango [ %d, %d] se cumple el Teorema de Zeckendorf\n",inicio,fin);
        else
            printf("En el rango [ %d, %d] no se cumple el Teorema de Zeckendorf\n",inicio,fin);
    }
    else
        printf("Rango incorrecto\n");
    return 0;
}

int calcularFibonacciPosicion(int posicion){
    int pos=2,i,fn_2=0,fn_1=1,fn=1;
    if (posicion==1)
        return fn_2;
    else
        if (posicion==2)
            return fn_1;
        else{
            while(pos<posicion){
                fn=fn_1+fn_2;
                fn_2=fn_1;
                fn_1=fn;
                pos++;
            }
            return fn;
        }
}

int buscarPosFibonacciCercana(int numero){
    int posicion=0,fibo;
    while(1){
        posicion++;
        fibo=calcularFibonacciPosicion(posicion);
        if (fibo>=numero) break;
    }
    if (numero==1)
        return posicion+1;
    else
        if (fibo==numero)
            return posicion;
        else
            return posicion-1;
}

int encontrarMostrarSeriesFibonacci(int numero){
    int i,suma=0,cantSumas=0,fiboSumar,fiboSumarIni;
    int posicion=1,posInicio=1,maxI;
    maxI=buscarPosFibonacciCercana(numero);
    printf("Numero %d\n",numero);
    printf("----------\n");
    while(1){
        suma=0;
        fiboSumarIni=calcularFibonacciPosicion(posInicio);
        posicion=posInicio;
        if (fiboSumarIni>=numero) break;
        for (i=2;i<=maxI;i++){
            fiboSumar=fiboSumarIni;
            suma=0;
            posicion=posInicio;
            while(fiboSumar<=numero && suma<numero){
                suma+=fiboSumar;
                posicion+=i;
                fiboSumar=calcularFibonacciPosicion(posicion);
            }
            if (suma==numero){
                cantSumas++;
                imprimirSeries(numero,posInicio,i);
            }
        }
        posInicio++;
    }
    return cantSumas;
}

void imprimirSeries(int numero,int posicion,int separacion){
    int fibo,suma=0,i=0;
    printf(" %d = ",numero);
    while(suma<numero){
        fibo=calcularFibonacciPosicion(posicion);
        if (i>0)
            printf(" + ");
        printf(" f( %d) %d ",posicion,fibo); 
        suma+=fibo;
        posicion+=separacion;
        i++;
    }
    printf("\n");
}
