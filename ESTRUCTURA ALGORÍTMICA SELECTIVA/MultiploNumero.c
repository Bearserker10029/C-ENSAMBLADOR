#include <stdio.h>

int main(){
	int n,m;
	
	printf("Ingrese n y m: ");
	scanf("%d %d",&n,&m);
	if ((m % n) == 0){
		printf("%d es m�ltiplo de %d\n",m,n);
	}
	else{
		printf("%d no es m�ltiplo de %d\n",m,n);
	}	
	return 0;
}
