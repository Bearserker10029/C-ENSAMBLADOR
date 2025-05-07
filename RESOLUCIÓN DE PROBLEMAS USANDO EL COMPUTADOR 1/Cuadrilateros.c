#include <stdio.h>

int main(){
	double lado1,lado2,lado3,lado4,alpha,beta,gamma,delta;
	int ladosParalelos,todosladosIguales,todosAngulosIguales,dosParesAngulosIguales,dosParesLadosIguales,dosAngulosRectangulos,dosAngulosIguales,todosLadosDiferentes,noHayAnguloRecto;
	
	printf("Ingrese los 4 lados del cuadrilátero: ");
	scanf("%lf %lf %lf %lf",&lado1,&lado2,&lado3,&lado4);
	printf("Ingrese los 4 ángulos internos del cuadrilátero: ");
	scanf("%lf %lf %lf %lf",&alpha,&beta,&gamma,&delta);
	printf("Ingrese la cantidad de lados paralelos: ");
	scanf("%d",&ladosParalelos);
	
	if (lado1<=0 || lado2<=0 || lado3<=0 || lado4<=0){
		printf("Los datos ingresados son incorrectos. Los lados deben ser mayores que cero.\n");
	}
	else if((alpha+beta+gamma+delta)!=360){
		printf("La suma de los ángulos internos no suma 360.\n");
	}
	else if(alpha<=0 || beta<=0 || gamma<=0 || delta<=0){
		printf("Los ángulos no pueden ser negativos.\n");
	}
	else if(ladosParalelos!=0 && ladosParalelos!=2 && ladosParalelos!=4){
		printf("Los lados paralelos ingresados solo pueden ser los valores de 0, 2 y 4\n");
	}
	else{
		/*Si entra acá es porque se realizaron todas las validaciones previas y los datos son correctos*/
		/*Caso PARALELOGRAMO */
		if (ladosParalelos==4){
			todosladosIguales = (lado1==lado2 && lado2==lado3 && lado3==lado4 && lado4==lado1);
			todosAngulosIguales = (alpha==beta && beta==gamma && gamma==delta && delta==alpha);
			dosParesAngulosIguales = (alpha==beta && gamma==delta) || (alpha==delta && beta==gamma) || (alpha==gamma && (beta== delta));
			dosParesLadosIguales = (lado1==lado2 && lado3==lado4) || (lado1==lado3 && lado2==lado4) || (lado1==lado4 && lado2==lado3);
			
			if (todosladosIguales){
				if (todosAngulosIguales){
					printf("Paralelogramo - Cuadrado\n");
				}
				else if (dosParesAngulosIguales){
					printf("Paralelogramo - Rombo\n");
				}
				else{
					printf("Los datos ingresados no corresponden con un cuadrilátero\n");
				}
			}
			else{
				if (dosParesLadosIguales){
					if (todosAngulosIguales){
						printf("Paralelogramo - Rectángulo\n");		
					}
					else if (dosParesAngulosIguales){
						printf("Paralelogramo - Romboide\n");
					}
					else{
						printf("Los datos ingresados no corresponden con un cuadrilátero\n");
					}
				}
				else{
					printf("Los datos ingresados no corresponden con un cuadrilátero\n");
				}
			}
		} /*Caso: TRapecios*/
		else if (ladosParalelos==2){
			dosAngulosRectangulos = (alpha==90 && beta==90 && gamma!=90 && delta!=90) ||
									(alpha==90 && gamma==90 && beta!=90 && delta!=90) ||
									(alpha==90 && delta==90 && beta!=90 && gamma!=90) ||
									(beta==90 && gamma==90 && alpha!=90 && delta!=90) ||
									(beta==90 && delta==90 && alpha!=90 && gamma!=90) ||
									(delta==90 && gamma==90 && alpha!=90 && beta!=90);
			dosAngulosIguales = (alpha==beta && alpha!=gamma && alpha!=delta) ||
								(alpha==gamma && alpha!=beta && alpha!=delta) ||
								(alpha==delta && alpha!=beta && alpha!=gamma) ||
								(beta==gamma && beta!=alpha && beta!=delta) ||
								(beta==delta && beta!=alpha && beta!=gamma) ||
								(delta==gamma && delta!=alpha && delta!=beta);
			todosLadosDiferentes = (lado1!=lado2 && lado2!=lado3 && lado3!=lado4 && lado4!=lado1);
			noHayAnguloRecto = (alpha!=90 && beta!=90 && gamma!=90 && delta!=90);
			if (dosAngulosRectangulos){
				printf("Trapecio - Rectángulo\n");
			}
			else if(dosAngulosIguales){
				printf("Trapecio - Isósceles\n");	
			}						
			else if (todosLadosDiferentes && noHayAnguloRecto){
				printf("Trapecio - Escaleno\n");	
			}
			else{
				printf("Los datos ingresados no corresponden con un cuadrilátero\n");
			}
		}
		else{ /*Caso todo el resto*/
			printf("Trapezoide\n");
		}
	}	
	return 0;
}
