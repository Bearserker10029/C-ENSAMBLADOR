#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main()
{
    srand(time(NULL));
    char a = 10;
    char b = 20;
    unsigned long long N = (unsigned long long)pow(2,10)-1;
    char *datos = (char*)malloc(N*sizeof(char));

    for (int i = 0;i<N;i++)
    {
        datos[i] = rand() % (b-a+1)+a;
    }

    for (int i = 0;i<N;i++)
    {
        printf( "%d ",datos[i]);
    }
    printf("\n");

    unsigned long long *histograma = (unsigned long long*)calloc(b-a+1,sizeof(unsigned long long));

    for (int i = 0; i < N; i++)
    {
        histograma[datos[i]-a] = histograma[datos[i]-a]+1;
    }
    
    for (int i = 0;i<b-a+1;i++)
    {
        printf( "%lld ",histograma[i]);
    }
    printf("\n");

}