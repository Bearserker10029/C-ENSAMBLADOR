#include <stdio.h>

int main(){
	int notaPositiva,contNotas;
	double nota,suma,promedio;
	
	/*inicializar variables*/
	notaPositiva = 1;
	suma = 0;
	contNotas = 0;
	while (notaPositiva){
		printf("Ingrese la nota: ");
		scanf("%lf",&nota);
		if (nota>=0){
			suma += nota;
			contNotas++;
		}
		else{
			notaPositiva = 0;
		}		
	}
	promedio = suma/contNotas;
	printf("El promedio de notas de los %d alumnos es: %.2lf\n",contNotas, promedio);
	return 0;
}
