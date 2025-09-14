Algoritmo calculo_numero_e
	i<-0
	suma<-0
	factorial<-1
	Mientras i<10 Hacer
		si i=0 Entonces
			suma<-suma+1
		SiNo
			suma<-suma+1/i
			factorial<-factorial*i
			Escribir i," ", factorial
		FinSi
		i<-i+1
	FinMientras
	Escribir "suma=", suma
FinAlgoritmo
