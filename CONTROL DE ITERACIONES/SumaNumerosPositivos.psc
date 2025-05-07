Algoritmo SumaNumerosPositivos
	centinela <- Verdadero
	suma <- 0
	Mientras (centinela) Hacer
		Escribir 'Ingrese un número: '
		Leer num
		Si (num>0) Entonces
			suma <- suma + num
		SiNo
			centinela <- Falso
		FinSi
	FinMientras
	Escribir 'La suma de los números positivos ingresados es: ',suma
FinAlgoritmo
