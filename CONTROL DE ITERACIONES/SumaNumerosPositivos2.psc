Algoritmo SumaNumerosPositivos2
	terminar <- Falso
	suma <- 0
	Mientras (no terminar) Hacer
		Escribir 'Ingrese un número: '
		Leer num
		Si (num>0) Entonces
			suma <- suma + num
		SiNo
			terminar <- Verdadero
		FinSi
	FinMientras
	Escribir 'La suma de los números positivos ingresados es: ',suma
FinAlgoritmo
