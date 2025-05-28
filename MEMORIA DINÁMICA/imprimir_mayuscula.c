#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N = 26;
    int i;
    char *letra = (char *)malloc((N + 1) * sizeof(char));
    for (i = 0; i < N; i++)
    {
        letra[i] = 'A' + i;
        printf("%c ", letra[i]);
    }
    printf("\n");
    free(letra);
    return 0;
}
