Algoritmo SumaNumerosPositivos2
	terminar <- Falso
	suma <- 0
	Mientras (no terminar) Hacer
		Escribir 'Ingrese un n�mero: '
		Leer num
		Si (num>0) Entonces
			suma <- suma + num
		SiNo
			terminar <- Verdadero
		FinSi
	FinMientras
	Escribir 'La suma de los n�meros positivos ingresados es: ',suma
FinAlgoritmo
