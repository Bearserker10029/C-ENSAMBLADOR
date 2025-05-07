Algoritmo ProductoWallis
	piReal <- 3.1415926535
	Escribir 'Ingrese la cantidad de términos: '
	Leer cantMaxTerminos
	
	Si (cantMaxTerminos<=0) Entonces
		Escribir 'La cantidad de términos debe ser mayor que cero.'
	SiNo
		i <- 1
		productoria <- 1
		Mientras (i<=cantMaxTerminos) Hacer
			termino <- ((2*i)^2) / ((2*i-1)*(2*i+1))
			productoria <- productoria*termino
			i <- i+1
		FinMientras
		piCalculado <- productoria*2
		error <- abs(piReal-piCalculado)
		Escribir 'El valor de PI calculado es: ',piCalculado
		Escribir 'El valor de PI real es: ',piReal
		Escribir 'El error es: ',error
	FinSi	
FinAlgoritmo
