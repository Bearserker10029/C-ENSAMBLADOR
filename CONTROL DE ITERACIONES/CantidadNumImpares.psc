Algoritmo CantidadNumImpares
	esImpar <- Verdadero
	contImpares <- 0
	Mientras (esImpar) Hacer
		Escribir 'Ingrese el n�mero impar: '
		Leer num
		//validar que el n�mero sea impar
		Si ((num mod 2) = 1) Entonces
			contImpares <- contImpares +1
		SiNo
			esImpar <- Falso
		FinSi		
	FinMientras
	Escribir 'La cantidad de n�meros impares le�dos es: ',contImpares
FinAlgoritmo
