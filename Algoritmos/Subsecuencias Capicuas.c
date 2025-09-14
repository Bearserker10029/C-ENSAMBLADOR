#include <stdio.h>
#include <math.h>

int validarNumeroEnBase(int numero, int base);
int calcularCantDigitos(int numero);
int calcularCantidadSecuenciasCapicuas(int numero,int cantDigitos);
int verificarCapicua(int numero);

int main(){
    int numero, esValido, cantDigitos, cantSecuenciasCapicuas, base;
    printf("Ingrese la base: ");
    scanf(" %d",&base);
    if (base>=2 && base<=10){
        printf("Ingrese el numero en la base indicada: ");
        scanf(" %d",&numero);
        if (numero>0){
            esValido = validarNumeroEnBase(numero,base);
            if (esValido){
                cantDigitos = calcularCantDigitos(numero);
                if (cantDigitos>=2){
                    cantSecuenciasCapicuas = calcularCantidadSecuenciasCapicuas(numero,cantDigitos);
                    printf("El numero %d tiene %d subsecuencias capicuas",numero,cantSecuenciasCapicuas);
                }
                else {
                    printf("El numero no se puede evaluar porque tiene menos de 2 cifras\n");
                }
            }
            else {
                printf("El numero ingresado no corresponde a la base ingresada");
            }
        }
        else {
            printf("El numero debe ser mayor que 0");
        }
    }
    else {
        printf("La base ingresada no es correcta");
    }
    return 0;
}

int calcularCantDigitos(int numero){
    int cantDigitos;
    cantDigitos = 0;
    while (numero>0){
        numero = numero/10;
        cantDigitos++;
    }
    return cantDigitos;
}

int calcularCantidadSecuenciasCapicuas(int numero,int cantDigitos){
    int total, i, j, subSecuencia, esCapicua, cantidad;
    cantidad = 0;
    total = cantDigitos;
    for (i=1; i<cantDigitos; i++){
        for (j=2; j<=total; j++){
            subSecuencia = numero %(int)pow(10,j);
            esCapicua = verificarCapicua(subSecuencia);
            if (esCapicua){
                printf(" %d\n",subSecuencia);
                cantidad++;
            }
        }
        total--;
        numero = numero/10;
    }
    return cantidad;
}

int validarNumeroEnBase(int numero, int base){
    int esCorrecto = 1, digito;
    while (numero>0){
        digito = numero %10;
        numero = numero/10;
        if (digito>=base){
            esCorrecto=0;
            break;
        }
    }
    return esCorrecto;
}

int verificarCapicua(int numero){
    int invertido, copiaNumero, digito, esCapicua;
    invertido = 0;
    copiaNumero = numero;
    while (numero>0){
        digito = numero %10;
        numero = numero/10;
        invertido = invertido*10 + digito;
    }
    if (invertido==copiaNumero){
        esCapicua = 1;
    }
    else {
        esCapicua = 0;
    }
    return esCapicua;
}
