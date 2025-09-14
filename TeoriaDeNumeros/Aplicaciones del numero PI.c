#include <stdio.h>
#include <math.h>

double CalcularNumeroPi(int);

int main ()
{
    char TipoAplicacion;
    int Cant_Iteraciones;
    double NumeroPi, Longitud, Aceleracion, PeriodoPendulo, Radio, LadoLateral, AreaLateral;
    double SemiEjeMayor, SemiEjeMenor, AreaElipse;

    //Consulta el numero de iterarionces de la aproximacion.
    printf("Ingrese el numero de iteraciones para calcular Pi: ");
    scanf("\n %d", &Cant_Iteraciones);

    if ( Cant_Iteraciones>=5 && Cant_Iteraciones<=20 )
    {
        //Consulta el tipo de objeto a evaluar.
        printf("Ingrese el tipo de aplicacion del Numero Pi,\n");
        printf("(Periodo del pendulo [P], Area lateral de superficie de un cono [C] o Area de una Elipse [E]): ");
        scanf("\n %c", &TipoAplicacion);

        //Calcula la Razon Aurea con un numero dado de iteraciones.
        NumeroPi = CalcularNumeroPi (Cant_Iteraciones);

        switch ( TipoAplicacion )
        {
            case 'P' :
                //Solicita los datos de la aplicacion
                printf("\nIngrese la longitud del pendulo (metros): ");
                scanf(" %lf", &Longitud);
                printf("Ingrese la aceleracion del pendulo (metros/segundo^2): ");
                scanf(" %lf", &Aceleracion);

                //Obtiene el periodo del pendulo e imprime el resultado.
                PeriodoPendulo = 2 * NumeroPi * sqrt(Longitud/Aceleracion);
                printf("El periodo de un pendulo de longitud %.2lf y aceleracion %.2lf es %.2lf segundos",
                Longitud, Aceleracion, PeriodoPendulo);
                break;
            case 'C' :
                //Solicita los datos de la aplicacion
                printf("\nIngrese el radio de la base del cono (metros): ");
                scanf(" %lf", &Radio);
                printf("Ingrese el lado lateral del cono (metros): ");
                scanf(" %lf", &LadoLateral);

                //Obtiene el area lateral del cono e imprime el resultado.
                AreaLateral = NumeroPi * Radio * LadoLateral;
                printf("El area lateral de un cono de radio %.2lf en la base y lado lateral %.2lf es %.2lf metros2",
                Radio, LadoLateral, AreaLateral);
                break;
            case 'E' :
                //Solicita los datos de la aplicacion
                printf("\nIngrese la longitud del semieje mayor de la elipse (metros): ");
                scanf(" %lf", &SemiEjeMayor);
                printf("Ingrese la longitud del semieje menor de la elipse (metros): ");
                scanf(" %lf", &SemiEjeMenor);

                //Obtiene el area de un elipse e imprime el resultado.
                AreaElipse = NumeroPi * SemiEjeMayor * SemiEjeMenor;
                printf("El area de una elipse de semiejes %.2lf y %.2lf es %.2lf metros2",
                SemiEjeMayor, SemiEjeMenor, AreaElipse);
                break;
            default :
                printf("La aplicacion ingresada no es valida.");
        }
    }
    else
        printf("El numero de iteraciones debe ser mayor a 5 y menor o igual a 20.");
}

double CalcularNumeroPi(int Cant_Iteraciones)
{
    int Cont = 2;
    double NumeroPi, X;

    //Se inicializa factor X1 con raiz de 2.
    X = sqrt(2);

    //Ejecuta cada iteracion que calcula la aproximacion de Pi.
    do
    {
        //Obtiene el factor de Xn.
        X = sqrt(2 - 2*sqrt(1 - pow(X, 2)/4));

        Cont++;

    } while (Cont <= Cant_Iteraciones);

    //Obtiene la aproximacion del valor de Pi.
    NumeroPi = pow(2, Cant_Iteraciones) * X;

    //Devuelve el numero Pi calculada.
    return NumeroPi;
}
