#include <stdio.h>
int evaluarSiEsPrimo(int numero);
int IdentificarPosicion(int num);
int HallarElPrimoEnPosicion(int pos);
int sumaDigitos(int numero);
int main()
{
    char opcion;
    int esprimo, pos, sumaDig, sumaPos, primo, numero;
    while (1)
    {
        printf("Opciones:\n");
        printf("A) Verificar si el número es Honaker\n");
        printf("B) Hallar el número primo en la posición y verificar si es Honaker\n");
        printf("C) Salir\n");
        scanf("\n %c", &opcion);
        if (opcion == 'C')
        {
            break;
        }
        else
        {
            if (opcion == 'A')
            {
                printf("Ingrese el número : ");
                scanf(" %d", &numero);
                if (numero > 0)
                {
                    esprimo = evaluarSiEsPrimo(numero);
                    if (esprimo)
                    {
                        pos = IdentificarPosicion(numero);
                        sumaPos = sumaDigitos(pos);
                        sumaDig = sumaDigitos(numero);
                        if (sumaPos == sumaDig)
                        {
                            printf("El número primo %d en la posición %d es Honaker\n", numero, pos);
                        }
                        else
                        {
                            printf("El número primo %d en la posición %d no es Honaker\n", numero, pos);
                        }
                    }
                    else
                    {
                        printf("El número no es primo\n");
                    }
                }
                else
                {
                    printf("El número debe ser tener valor mayor a 0\n");
                }
            }
            else
            {
                if (opcion == 'B')
                {
                    printf("Ingrese la posición : ");
                    scanf(" %d", &pos);
                    if (pos > 0)
                    {
                        primo = HallarElPrimoEnPosicion(pos);
                        sumaPos = sumaDigitos(pos);
                        sumaDig = sumaDigitos(primo);
                        if (sumaPos == sumaDig)
                        {
                            printf("El número primo en la posición %d es %d y es Honaker\n", pos, primo);
                        }
                        else
                        {
                            printf("El número primo en la posición %d es %d y no es Honaker\n", pos, primo);
                        }
                    }
                    else
                    {
                        printf("La posición debe ser un valor mayor a 0\n");
                    }
                }
                else
                {
                    printf("Ha ingresado una opción inválida\n");
                }
            }
        }
    }
    return 0;
}
int evaluarSiEsPrimo(int numero)
{
    int cont = 0, i = 1;
    while (i <= numero)
    {
        if (numero % i == 0)
        {
            cont++;
        }
        i++;
    }
    if (cont == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int sumaDigitos(int numero)
{
    int suma = 0, dig;
    while (numero > 0)
    {
        dig = numero % 10;
        suma = suma + dig;
        numero = numero / 10;
    }
    return suma;
}
int IdentificarPosicion(int num)
{
    int i = 2, cont = 0, esprimo;
    while (1)
    {
        esprimo = evaluarSiEsPrimo(i);
        if (esprimo)
        {
            cont++;
        }
        if (i == num)
        {
            break;
        }
        i++;
    }
    return cont;
}
int HallarElPrimoEnPosicion(int pos)
{
    int i = 2, cont = 0, esprimo;
    while (1)
    {
        esprimo = evaluarSiEsPrimo(i);
        if (esprimo)
        {
            cont++;
        }
        if (cont == pos)
        {
            break;
        }
        i++;
    }
    return i;
}