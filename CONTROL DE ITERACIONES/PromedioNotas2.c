#include <stdio.h>

int main(){
	int contNotas;
	double nota,suma,promedio;
	
	/*inicializar variables*/

	suma = 0;
	contNotas = 0;
	while (1){
		printf("Ingrese la nota: ");
		scanf("%lf",&nota);
		if (nota>=0){
			suma += nota;
			contNotas++;
		}
		else{
			break;
		}		
	}
	promedio = suma/contNotas;
	printf("El promedio de notas de los %d alumnos es: %.2lf\n",contNotas, promedio);
	return 0;
}
