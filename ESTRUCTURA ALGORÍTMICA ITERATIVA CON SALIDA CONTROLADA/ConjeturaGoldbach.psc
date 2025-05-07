Algoritmo ConjeturaGoldbach
	Escribir 'Ingrese rango inicial a: '
	Leer a
	Escribir 'Ingrese rango final b: '
	Leer b
	Si (a>0 y a<b) Entonces
		contPares <- 0
		contCumplen <- 0
		//se recorrer� todo el rango de n�meros entre [a,b]
		Para i<- a hasta b con paso 1 Hacer
			//evaluar n�meros pares mayores a 2
			Si (i>2 y (i mod 2)=0) Entonces
				contPares <- contPares+1
				cumpleCondicion <- Falso
				Para numIzq<-2 hasta (i-2) con paso 1 Hacer
					//contar los divisores del n�mero de la parte izquierda
					contDivIzq <- 0
					Para j<-1 hasta numIzq con paso 1 Hacer
						Si (numIzq MOD j)=0 Entonces
							contDivIzq <- contDivIzq+1
						FinSi
					FinPara
					numDer <- i - numIzq
					//contar los divisores del n�mero de la parte derecha
					contDivDer <- 0
					Para j<-1 hasta numDer con paso 1 Hacer
						Si (numDer MOD j)=0 Entonces
							contDivDer <- contDivDer+1
						FinSi
					FinPara
					//eval�o si los n�meros de izq y derecha son primos
					Si (contDivIzq=2 y contDivDer=2) Entonces
						Escribir i,' = ',numIzq,' + ',numDer
						cumpleCondicion <- Verdadero
					FinSi					
				FinPara
				Si (cumpleCondicion) Entonces
					contCumplen <- contCumplen+1
				FinSi				
			FinSi
		FinPara		
		Si (contPares=contCumplen) Entonces
			Escribir 'Se cumple la conjetura de Goldbach'
		FinSi
	FinSi	
FinAlgoritmo
