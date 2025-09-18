#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
    int numero= atoi(argv[1]);
    int lim_inf= atoi(argv[2]);
    int lim_sup= atoi(argv[3]);
    int multiplo=0;
    if(lim_inf==0 || lim_sup%numero==0){
        multiplo=1;
    }
    while (numero<=lim_sup){

        if(lim_sup-numero>=lim_inf){
            multiplo=multiplo+1;
            lim_sup=lim_sup-numero;
        }else break;
    }
    printf("Hay %d múltiplos de %d en este rango\n", multiplo, numero);
}