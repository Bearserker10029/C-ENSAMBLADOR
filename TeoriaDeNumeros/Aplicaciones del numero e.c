#include <stdio.h>
#include <math.h>

double CalcularNumeroe(int);

int main ()
{
    char TipoAplicacion;
    int Cant_Iteraciones;
    double Numeroe, PoblacionActual, PoblacionFinal, TasaCrecimientoPoblacional, Tiempo;
    double AhorroInicial, AhorroFinal, TasaInteres, Constante, Variable;

    //Consulta el numero de iterarionces para el calculo de la aproximacion del Numero e.
    printf("Ingrese el numero de iteraciones para calcular el Numero e: ");
    scanf("\n %d", &Cant_Iteraciones);

    if ( Cant_Iteraciones>10 )
    {
        //Calcula el Numero e con un numero dado de iteraciones.
        Numeroe = CalcularNumeroe(Cant_Iteraciones);

        printf("Ingrese el tipo de aplicacion\n");
        printf("Crecimiento Poblacional [P], Interes Compuesto [I], Logaritmo Natural [L]: ");
        scanf("\n %c", &TipoAplicacion);

        switch ( TipoAplicacion )
        {
            case 'P' :
                //Solicita los datos para el calculo de la poblacion final.
                printf("\nIngrese la poblacion actual: ");
                scanf(" %lf", &PoblacionActual);
                printf("Ingrese la tasa de crecimiento poblacional anual (0 a 100): ");
                scanf(" %lf", &TasaCrecimientoPoblacional);
                printf("Ingrese el tiempo a transcurrir en anos: ");
                scanf(" %lf", &Tiempo);

                //Estima la poblacion final al termino de un tiempo dado.
                PoblacionFinal = PoblacionActual * pow(Numeroe, (TasaCrecimientoPoblacional/100)*Tiempo);
                printf("La poblacion final estimada a los %.2lf sera de %.0lf personas", Tiempo, PoblacionFinal);
                break;
            case 'I' :
                //Solicita los datos para el calculo del ahorro al final del periodo.
                printf("\nIngrese el dinero depositado en soles: ");
                scanf(" %lf", &AhorroInicial);
                printf("Ingrese la tasa de interes anual (0 a 100): ");
                scanf(" %lf", &TasaInteres);
                printf("Ingrese el tiempo del deposito en anos: ");
                scanf(" %lf", &Tiempo);

                //Estima la poblacion final al termino de un tiempo dado.
                AhorroFinal = AhorroInicial * pow(Numeroe, (TasaInteres/100)*Tiempo);
                printf("El ahorro al finalizar los %.2lf anos sera de %.2lf soles", Tiempo, AhorroFinal);
                break;
            case 'L' :
                //Solicita la constante para despejar el logaritmo natural.
                printf("\nIngrese la constante a evaluar para despejar la variable X: ");
                scanf(" %lf", &Constante);

                //Calcula el valor de la Variable e imprime el resultado.
                Variable = pow(Numeroe, Constante);
                printf("Para una ecuacion de la forma Ln(X) = %.2lf el valor de X que la resuelve es %.2lf",

                Constante, Variable);

                break;
            default :
                printf("El tipo de aplicacion no es valido.");
        }
    }
    else
        printf("El numero de iteraciones debe ser mayor o igual a 10.");
}

double CalcularNumeroe(int Cant_Iteraciones)
{
    int Cont=1; //Se inicializa el contador en 1.
    double Producto, Numeroe;

    //Se inicializan las variables para el calculo del exponencial.
    Producto = 1;
    Numeroe = 1;

    //Ejecuta cada iteracion que calcula la Razon Aurea.
    do
    {
        //Acumula el contador en Producto
        Producto = Producto * Cont;

        //Obtiene el valor del Numero e.
        Numeroe = Numeroe + pow(Producto, -1);

        Cont++;

    } while (Cont <= Cant_Iteraciones);

    //Devuelve el exponencial calculado.
    return Numeroe;
}
