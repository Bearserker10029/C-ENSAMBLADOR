Algoritmo DistanciaEntreDosPuntos
	Escribir 'Ingrese el punto 1:'
	Leer x1,y1
	Escribir 'Ingrese el punto 2:'
	Leer x2,y2
	//Evaluar que los puntos se encuentren en el primer cuadrante
	Si (x1>0 y y1>0 y x2>0 y y2>0) Entonces
		distancia <- rc((x2-x1)^2 + (y2-y1)^2)
		Escribir 'La distancia entre los dos puntos es: ', distancia
	SiNo
		Escribir 'Los puntos no se encuentran en el primer cuadrante.'
	FinSi	
FinAlgoritmo
