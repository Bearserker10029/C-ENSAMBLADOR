#include <stdio.h>
#include <math.h>

double CalcularDistanciaEntreDosPuntos(double x1,double y1,double x2,double y2);
void HallarYmostrarREctaMenorDistancia(double x1,double y1);

int main(){
	int salir,opcion;
	double x1,y1,x2,y2,distancia,mayorDistancia,x1Mayor,y1Mayor,x2Mayor,y2Mayor;
	
	salir = 0;
	while (!salir){
		printf("Menú de opciones: \n");
		printf("1.- Calcular la distancia entre 2 puntos\n");
		printf("2.- Calcular la distancia mínima de un punto a varias rectas\n");
		printf("3. Salir del programa\n");
		printf("Ingrese la opción:");
		scanf("%d",&opcion);
		switch(opcion){
			case 1: {
				mayorDistancia = 0;
				x1Mayor = 0;
				x2Mayor = 0;
				y1Mayor = 0;
				y2Mayor = 0;				
				do{
					printf("Ingrese la coordenada x e y del punto P: ");
					scanf("%lf %lf",&x1,&y1);
					printf("Ingrese la coordenada x e y del punto Q: ");
					scanf("%lf %lf",&x2,&y2);
					if (x1!=0 || y1!=0 || x2!=0 || y2!=0){
						distancia = CalcularDistanciaEntreDosPuntos(x1,y1,x2,y2);
						printf("La distancia de P y Q es: %lf\n",distancia);
						/*se va buscando la mayor distancia*/
						if (distancia>mayorDistancia){
							mayorDistancia = distancia;
							x1Mayor = x1;
							x2Mayor = x2;
							y1Mayor = y1;
							y2Mayor = y2;
						}
					}			
					
				}while(x1!=0 || y1!=0 || x2!=0 || y2!=0);
				printf("Los puntos que dieron la mayor distancia fueron P(%.lf,%.2lf) y Q(%.2lf,%.2lf) con %.lf de distancia",x1Mayor,y1Mayor,x2Mayor,y2Mayor,mayorDistancia);
				break;
			}
			case 2:{
				printf("Ingrese la coordenada x e y del punto P: ");
				scanf("%lf %lf",&x1,&y1);
				HallarYmostrarREctaMenorDistancia(x1,y1);
				break;
			}
			case 3:{
				salir = 1;
				break;
			}
			default:{
				printf("Opción incorrecta\n");
				break;
			}
		}		
	}	
	return 0;
}

double CalcularDistanciaEntreDosPuntos(double x1,double y1,double x2,double y2){
	return sqrt(pow(abs(x2-x1),2)+ pow(abs(y2-y1),2));
}
void HallarYmostrarREctaMenorDistancia(double x1,double y1){
	
}
