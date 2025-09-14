#include <stdio.h>
#include <math.h>

int validarNumero(int numero,int base);
int calcularExponenteK(int base,int nuevaBase);
int cambiarBase(int numero,int exponenteK,int base);
int calcularCantidadDigitos(int numero);

int main(){
    int base, numero, esValido, nuevaBase, exponenteK, nuevoNum;
    printf("Ingrese la base: ");
    scanf(" %d",&base);
    if (base>1 && base<10){
        printf("Ingrese el numero en la base ingresada: ");
        scanf(" %d",&numero);
        if (numero>0){
            esValido = validarNumero(numero,base);
            if (esValido){
                printf("Ingrese la nueva base a donde desea pasar el numero: ");
                scanf(" %d",&nuevaBase);
                if (nuevaBase<base && nuevaBase>1){
                    exponenteK = calcularExponenteK(nuevaBase,base);
                    if (exponenteK==0){
                        printf("No se pudo determinar un exponente k entero de la forma base^k = nuevaBase");
                    }
                    else{
                        nuevoNum = cambiarBase(numero,exponenteK,nuevaBase);
                        printf("El numero %d en base %d es igual al numero %d en base %d",numero,base,nuevoNum,nuevaBase);
                    }
                }
                else {
                    if (nuevaBase>=base){
                        printf("La nueva base no puede ser mayor o igual que la base original");
                    }
                    else{
                        printf("La nueva base no puede ser menor o igual que 0");
                    }
                }
            }
            else {
                printf("El numero ingresado no corresponde a la base ingresada");
            }
        }
        else{
            printf("El numero debe ser mayor que 0");
        }
    }
    else{
        printf("La base ingresada no es correcta");
    }
    return 0;
}

int validarNumero(int numero,int base){
    int esValido=1, digito;
    while (numero!=0){
        digito = numero %10;
        numero = numero/10;
        if (digito>=base){
            esValido=0;
            break;
        }
    }
    return esValido;
}

int calcularExponenteK(int base,int nuevaBase){
    int exponente, producto;
    exponente = 0;
    producto = 1;
    while (producto<nuevaBase){
        producto = producto*base;
        exponente++;
    }
    if (producto!=nuevaBase){
        exponente = 0;
    }
    return exponente;
}

int cambiarBase(int numero,int exponenteK,int base){
    int cantDigitos, nuevoNum, digito, nuevo, exponente, cifra;
    cantDigitos = calcularCantidadDigitos(numero);
    nuevoNum = 0;
    while (numero>0){
        digito = numero/(int)pow(10,cantDigitos-1);
        numero = numero %(int)pow(10,cantDigitos-1);
        cantDigitos--;
        nuevo = 0;
        exponente = 0;
        while (digito>0){
            cifra = digito %base;
            digito = digito/base;
            nuevo = nuevo + cifra*(int)pow(10,exponente);
            exponente++;
        }
        nuevoNum = nuevoNum*(int)pow(10,exponenteK) + nuevo;
    }
    return nuevoNum;
}

int calcularCantidadDigitos(int numero){
    int cantCifras;
    cantCifras = 0;
    while (numero>0){
        numero = numero/10;
        cantCifras++;
    }
    return cantCifras;
}
