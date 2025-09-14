#include <stdio.h>

	int main() { 
	int i = 0;
	double suma = 0; 
	double factorial = 1; 
	while (i < 20) { 
	if (i == 0)
	suma = suma + 1; 
	else {
	suma = suma + (double) 1 / i; 
	factorial = factorial*i;
	printf("%d %lf\n", i, factorial); 
	} 
	i++; 
	}
	printf("Suma = %lf", suma); return 0;
	}
