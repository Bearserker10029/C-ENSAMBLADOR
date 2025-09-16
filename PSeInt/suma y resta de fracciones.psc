Funcion gcd_val <- mcd(a, b)
    Definir temp Como Entero;
    a <- abs(a);
    b <- abs(b);
    Mientras b <> 0 Hacer
        temp <- b;
        b <- a MOD b;
        a <- temp;
    FinMientras
    gcd_val <- a;
FinFuncion

Algoritmo SumaYRestaDeFracciones
    Definir num1, den1, num2, den2, num_res, den_res Como Entero;
    Definir last_valid_num, last_valid_den Como Entero;
    Definir op Como Caracter;
    Definir has_last_valid Como Logico;
    Definir common_divisor Como Entero;

    has_last_valid <- Falso;

    Repetir
        Escribir "Ingrese el numerador y denominador de la primera fracción:";
        Leer num1, den1;

        Si num1 = 0 y den1 <> 0 y has_last_valid Entonces
            common_divisor <- mcd(last_valid_num, last_valid_den);
            Escribir "La fracción irreductible del último resultado válido es: ", last_valid_num / common_divisor, "/", last_valid_den / common_divisor;
        SiNo
            Si den1 = 0 Entonces
                Escribir "El denominador no puede ser cero.";
            SiNo
                Escribir "Ingrese el numerador y denominador de la segunda fracción:";
                Leer num2, den2;

                Si den2 = 0 Entonces
                    Escribir "El denominador no puede ser cero.";
                SiNo
                    Escribir "Ingrese la operación a realizar: (+) suma o (-) resta:";
                    Leer op;

                    Si op = "+" o op = "-" Entonces
                        si op = "+" Entonces
                            num_res <- num1 * den2 + num2 * den1;
                            den_res <- den1 * den2;
                        sino
                            num_res <- num1 * den2 - num2 * den1;
                            den_res <- den1 * den2;
                        FinSi

                        last_valid_num <- num_res;
                        last_valid_den <- den_res;
                        has_last_valid <- Verdadero;
                        
                        si den_res < 0 entonces
                            den_res <- -den_res;
                            num_res <- -num_res;
                        finsi

                        Si abs(num_res) < abs(den_res) Entonces
                            Escribir "Fracción propia. El resultado es: ", num1, "/", den1, " ", op, " ", num2, "/", den2, " = ", num_res, "/", den_res;
                        SiNo
                            Escribir "Fracción impropia. El resultado es: ", num1, "/", den1, " ", op, " ", num2, "/", den2, " = ";
                            Si num_res MOD den_res = 0 Entonces
                                Escribir Sin Saltar num_res / den_res;
                            SiNo
                                Escribir Sin Saltar trunc(num_res / den_res), " ", abs(num_res MOD den_res), "/", den_res;
                            FinSi
                            Escribir "";
                        FinSi
                    SiNo
                        Escribir "Solo se trabajará con sumas y restas.";
                    FinSi
                FinSi
            FinSi
        FinSi
    Hasta Que Falso;

FinAlgoritmo