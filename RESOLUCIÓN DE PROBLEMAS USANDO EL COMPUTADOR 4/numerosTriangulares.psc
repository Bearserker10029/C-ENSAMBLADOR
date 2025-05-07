Algoritmo numerosTriangulares
	Escribir 'Ingrese n: '
	Leer n
	filas <- n+2
	Si n>0 Entonces
		Escribir 'Los primeros ',n,' números triangulares son: '
		Para p<-0 hasta filas-1 Con Paso 1 Hacer
			Para  r<-0 hasta p Con Paso 1 Hacer
				//realizar el cálculo de los factoriales
				fact_p <- 1
				fact_r <- 1
				fact_p_menos_r <- 1
				Para i<-1 hasta p Con Paso 1 Hacer
					fact_p <- fact_p * i
					Si i<=r Entonces
						fact_r <- fact_r * i
					FinSi
					Si i<=(p-r) Entonces
						fact_p_menos_r <- fact_p_menos_r * i
					FinSi
				FinPara
				//aplicar la fórmula de la combinatoria
				combinatoria <- fact_p/(fact_r*fact_p_menos_r)
				Si p>=2 Entonces
					Si r=(p-2) Entonces
						Escribir combinatoria
					FinSi
				FinSi
			FinPara
		FinPara		
	SiNo
		Escribir 'n debe ser mayor que cero'
	FinSi	
FinAlgoritmo
