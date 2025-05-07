#include <stdio.h>

int main(){
	int i,sumatoria;
	
	i = 0;
	sumatoria = 0;
	while (i<=10){
		sumatoria += i; 	/*sumatoria = sumatoria + i;*/
		i++;
	}
	printf("La sumatoria del 0 al 10 es %d\n",sumatoria);
	return 0;
}
