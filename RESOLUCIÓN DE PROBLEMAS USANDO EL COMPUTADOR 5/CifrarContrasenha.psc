Algoritmo CifrarContrasenha
	final <- Falso
	Mientras (no final) Hacer
		Escribir 'Contrase�a: '
		Leer contrasenha
		si (contrasenha>0 y contrasenha<10^10) Entonces
			//se debe realizar la conversi�n de la contrase�a
			contrasenhaFinal <- 0
			i<-0
			Mientras (contrasenha>0) Hacer
				num2Cifras <- contrasenha mod 100
				contrasenha <- trunc(contrasenha/100)
				//separar el n�mero de 2 cifras en parte izquierda y parte derecha
				numIzquierda <- trunc(num2Cifras/10)
				numDerecha <-  num2Cifras mod 10
				potencia <- 4
				numBinario <- 0
				Mientras (numIzquierda>0) Hacer
					digitoBin <- numIzquierda mod 2
					numBinario <- numBinario+digitoBin*(2^potencia)
					numIzquierda <- trunc(numIzquierda/2)
					potencia <- potencia+1
				FinMientras
				numBinario <- numBinario+numDerecha
				contrasenhaFinal<- contrasenhaFinal+numBinario*(10^i)
				i <- i+2
				si (numBinario>99) Entonces
					i <- i+1
				FinSi				
			FinMientras
			Escribir 'La contrase�a transformada es: ',contrasenhaFinal			
		SiNo
			Si (contrasenha<=0) Entonces
				final <- Verdadero
			SiNo
				Escribir 'La contrase�a tiene m�s de 10 d�gitos'
			FinSi
		FinSi		
	FinMientras	
FinAlgoritmo
