Algoritmo ValorPi
	Escribir 'Cantidad de términos a evaluar: '
	Leer cantidad
	Si (cantidad<1) Entonces
		Escribir 'Error, la cantidad de términos debe ser mayor o igual a 1.'
	SiNo
		i <- 0
		signo <- 1
		sumatoria <- 0
		denominador <- 1
		Repetir
			i <- i+1
			termino <- signo*(1/denominador)
			sumatoria <- sumatoria + termino
			denominador <- denominador+2
			signo <- signo*(-1)			
		Mientras Que (i<cantidad)
		calculoPi <- 4*sumatoria
		Escribir 'Nro de términos  Resultado aprox de Pi  Diferencia'
		Escribir '   ', cantidad, '               ',calculoPi,'           ', abs(3.1415926536-calculoPi)
	FinSi	
FinAlgoritmo
