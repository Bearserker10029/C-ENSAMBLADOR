Algoritmo CantidadNumImpares
	esImpar <- Verdadero
	contImpares <- 0
	Mientras (esImpar) Hacer
		Escribir 'Ingrese el número impar: '
		Leer num
		//validar que el número sea impar
		Si ((num mod 2) = 1) Entonces
			contImpares <- contImpares +1
		SiNo
			esImpar <- Falso
		FinSi		
	FinMientras
	Escribir 'La cantidad de números impares leídos es: ',contImpares
FinAlgoritmo
