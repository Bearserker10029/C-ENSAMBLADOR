Algoritmo CalculoMCD
	Escribir 'Ingrese dos números: '
	Leer a,b
	Si (a>0 y b>0) Entonces
		//guardar los valores iniciales de a y b
		aInicial <- a
		bInicial <- b
		finIteracion <- Falso
		Mientras (no finIteracion) Hacer
			Si (b<a) Entonces //propiedad 1
				//permutar los valores de a y b aplicando la propiedad 1
				aux <- a
				a <- b
				b <- aux				
			FinSi
			Si (a<1) Entonces //propiedad 3
				finIteracion <- Verdadero
			SiNo //propiedad 2
				b <- b-a
			FinSi			
		FinMientras
		Escribir 'El MCD de ',aInicial,' y ',bInicial,' es ', b
	SiNo
		Escribir 'Debe ingresar dos números mayores que cero.'
	FinSi
FinAlgoritmo
