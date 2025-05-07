Algoritmo MayorPosible
	Escribir 'Ingrese la cantidad de números a evaluar: '
	Leer cantNum
	i <- 1
	Mientras (i<=cantNum) Hacer
		Escribir 'Ingrese un número de 3 cifras: '
		Leer num
		//obtener unidad, decena, centena
		unidad <- num mod 10
		decena <- trunc(num/10) mod 10
		centena <- trunc(num/100)
		//calcular la cifra mayor del número
		Si (unidad>decena y unidad>centena) Entonces
			cifraMayor <- unidad
		SiNo
			Si (decena>unidad y decena>centena) Entonces
				cifraMayor <- decena
			SiNo
				Si (centena>unidad y centena>decena) Entonces
					cifraMayor <- centena
				FinSi
			FinSi
		FinSi
		//calcular la cifra menor del número
		Si (unidad<decena y unidad<centena) Entonces
			cifraMenor <- unidad
		SiNo
			Si (decena<unidad y decena<centena) Entonces
				cifraMenor <- decena
			SiNo
				Si (centena<unidad y centena<decena) Entonces
					cifraMenor <- centena
				FinSi
			FinSi
		FinSi
		//calcular la cifra intermedia
		cifraMedia <- unidad + decena + centena - cifraMayor - cifraMenor
		mayorNumPosible <- cifraMayor*100 + cifraMedia*10 + cifraMenor
		Escribir 'El mayor número posible es: ',mayorNumPosible	
		i <- i+1
	FinMientras	
FinAlgoritmo
