#include <stdio.h>
#include <stdlib.h>


void calcula_resta_total(int N, int z, int *arreglox, int *arregloy){

    for (int i = 0;i<N;i++)
    {
        arreglox[i] = (int)rand();
    }
    for(int i = 0;i<N;i++)
    {
        if(i%2==0){
            arregloy[i] = arreglox[i]-z;
        }

    }

}


int main(){
    int N=9;
    int z=1;
    int *arreglox= (int*) malloc(N*sizeof(int));
    int *arregloy= (int*) calloc(N,sizeof(int));
    calcula_resta_total(N,z,arreglox,arregloy);
    return 0;
}
