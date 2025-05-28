#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N = 128;
    double *arr = (double*)malloc( N*sizeof(double));

    for (int i = 0;i<N;i++)
    {
        arr[i] = ((double)i)/3.5;
    }

    for (int i = 0;i < N;i++)
    {
        printf("%lf ",arr[N-i-1]);
    }
    printf("\n");

    free(arr);
}