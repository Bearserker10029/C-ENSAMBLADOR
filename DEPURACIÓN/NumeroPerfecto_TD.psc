Algoritmo NumeroPerfecto
	Escribir 'Ingrese el número a evaluar: '
	Leer num
	Si num>0 Entonces
		i <- 1
		suma <- 0
		Mientras (i<num) Hacer
			resto <- num mod i
			Si (resto=0) Entonces
				suma <- suma + i
			FinSi
			i <- i+1
		FinMientras
		Si (suma=num) Entonces
			Escribir 'El número ',num,' es perfecto'
		Sino
			Escribir 'El número ',num,' no es perfecto'
		FinSi
	SiNo
		Escribir 'El número a evaluar debe ser mayor a 0'
	FinSi	
FinAlgoritmo
// Tabla de datos
// # iteración	num		i	suma		resto
//      0		 6		1	  0		 N.D.
//	   1			 6		2	  1    	  0
//     2			 6		3	  3		  0
//     3           6       4     6        0
//     4			 6		5	 6	      2
//	  5			 6		6	 6		 1
