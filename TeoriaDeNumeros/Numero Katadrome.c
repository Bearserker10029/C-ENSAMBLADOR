#include <stdio.h>
#include <math.h>
void evaluarSiEsKatadrome(int num, int cantDig, int *resp, int *nnum);

void mostrarMensaje(int esKatadromes);
int CalcularCantidadDigitos(int num);

int main()
{
    char evaluacion;
    int num, cantDig, esKatadromes, nnum;
    printf("Ingrese el número a evaluar: ");
    scanf(" %d", &num);
    cantDig = log10(num) + 1;
    evaluarSiEsKatadrome(num, cantDig, &esKatadromes, &nnum);
    mostrarMensaje(esKatadromes);
    printf("\nSe cumple el decremento en el número %d", nnum);
    return 0;
}

void mostrarMensaje(int esKatadromes)
{
    if (esKatadromes)
    {
        printf("\nEl número es Katadrome ");
    }
    else
    {
        printf("\nEl número no es Katadrome ");
    }
}

int evaluarSiEspalindome(int num, int cantDig)
{
    int dig, norig = num, digant = num / pow(10, cantDig - 1), continua = 1, resp = 1;
    num = digant;
    num = num % (int)pow(10, cantDig - 1);
    cantDig--;
    while (cantDig > 0)
    {
        dig = num / (int)pow(10, cantDig - 1);
        num = num % (int)pow(10, cantDig - 1);
        if (dig > digant)
        {
            resp = resp && 1;
        }
        else
        {
            resp = resp && 0;
        }
        cantDig--;
    }
    return resp;
}
void evaluarSiEsKatadrome(int num, int cantDig, int *resp, int *nnum)
{
    int dig, norig = num, digant = num / pow(10, cantDig - 1), continua = 1;
    *nnum = digant;
    num = num % (int)pow(10, cantDig - 1);
    cantDig--;
    while (cantDig > 0)
    {
        dig = num / (int)pow(10, cantDig - 1);
        num = num % (int)pow(10, cantDig - 1);
        if (dig < digant && continua)
        {
            *nnum = (*nnum) * 10 + dig;
        }
        else
        {
            continua = 0;
        }
        digant = dig;
        cantDig--;
    }
    if (*nnum == norig)
    {
        *resp = 1;
    }
    else
    {
        *resp = 0;
    }
}