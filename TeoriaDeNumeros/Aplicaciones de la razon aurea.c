#include <stdio.h>
#include <math.h>

double CalcularRazonAurea(int);

int main ()
{
    char TipoObjeto;
    int Cant_Iteraciones;
    double RazonAurea, Base, Altura, LadoMayor, LadoLateral, BaseMayor, BaseMenor;

    //Consulta el numero de iterarionces de la aproximacion.
    printf("Ingrese el numero de iteraciones para calcular la razon aurea: ");
    scanf("\n %d", &Cant_Iteraciones);

    if ( Cant_Iteraciones>=10 )
    {
        //Consulta el tipo de objeto a evaluar.
        printf("Ingrese el tipo de objeto (Rectangulo [R], Triangulo [T] o Trapecio [P]): ");
        scanf("\n %c", &TipoObjeto);

        //Calcula la Razon Aurea con un numero dado de iteraciones.
        RazonAurea = CalcularRazonAurea (Cant_Iteraciones);

        switch ( TipoObjeto )
        {
            case 'R' :
                printf("\nIngrese la base del rectangulo aureo: ");
                scanf(" %lf", &Base);

                //Obtiene la altura de un rectangulo aureo e imprime el resultado.
                Altura = RazonAurea * Base;
                printf("La altura de un rectangulo aureo de base %.2lf es %.2lf", Base, Altura);
                break;
            case 'T' :
                printf("\nIngrese la base del triangulo aureo: ");
                scanf(" %lf", &Base);

                //Obtiene el lado mayor del triangulo aureo e imprime el resultado.
                LadoMayor = RazonAurea * Base;

                //Obtiene la Altura del triangulo aureo.
                Altura = sqrt( pow(LadoMayor, 2) - pow(Base/2, 2) );
                printf("La altura de un triangulo aureo de base %.2lf es %.2lf y sus lados iguales son de %.2lf",

                Base, Altura, LadoMayor);

                break;
            case 'P' :
                printf("\nIngrese el lado lateral del trapecio aureo: ");
                scanf(" %lf", &LadoLateral);

                //Obtiene las bases del trapecio aureo e imprime los resultados;
                BaseMayor = LadoLateral * RazonAurea;
                BaseMenor = LadoLateral / RazonAurea;
                printf("Las bases de un trapecio aureo de lado lateral %.2lf son %.2lf y %.2lf", LadoLateral,

                BaseMayor, BaseMenor);

                break;
            default :
                printf("El tipo de objeto ingresado no es valido.");
        }
    }
    else
        printf("El numero de iteraciones debe ser mayor o igual a 10.");
}

double CalcularRazonAurea (int Cant_Iteraciones)
{
    int Cont = 1;
    double RazonAurea = 1; //Puede inicializarse con 0 o 1.

    //Ejecuta cada iteracion que calcula la Razon Aurea.
    do
    {
        RazonAurea = sqrt(1 + RazonAurea);

        Cont++;

    } while (Cont <= Cant_Iteraciones);

    //Devuelve la Razon Aurea calculada.
    return RazonAurea;
}
