/*Importo las directivas que se van a usar en el programa*/
#include <stdio.h>
/*Uso "main" debido a que es la parte fundamental de un programa*/
int main()
{
	/*Variables del problema*/
	/*Debe usar "char" debido a que los datos y la respuesta que se desea obtener son caracteres*/
	char c1 = 'L', c2 = 'U', c3 = 'I', c4 = 'S';
	/*El problema nos indica que debe desplazarse 3 unidades a la derecha, por lo que sumo 3 a las variables*/
	char c1_cifrado = c1 + 3;
	char c2_cifrado = c2 + 3;
	char c3_cifrado = c3 + 3;
	char c4_cifrado = c4 + 3;
	/*Muestro el resultado obtenido*/
	printf("El mensaje cifrado es %c %c %c %c \n", c1_cifrado, c2_cifrado, c3_cifrado, c4_cifrado);
	/*Termino la ejecucion del programa*/
	return 0;
}
