Algoritmo Movimiento_Circular_Uniforme
	// Introducir los datos requeridos
	escribir "Ingrese la distancia (en metros) de la pista circular: "
	leer distancia
	escribir "Ingrese el tiempo (en segundos) que se demora en recorrer la distancia de la pista circular el auto 1: "
	leer tiempo_de_auto1
	escribir "Ingrese el tiempo (en segundos) que se demora en recorrer la distancia de la pista circular el auto 2: "
	leer tiempo_de_auto2
	escribir "Ingrese la masa (en Kg) del auto 1: "
	leer masa_auto1
	escribir "Ingrese la masa (en Kg) del auto 2: "
	leer masa_auto2
	//Calculo del radio a partir de la formula distancia=2*pi*radio
	radio<-distancia/(2*3.141592)
	
	//Calculo de la velocidad del auto 1 a partir de la formula distancia= velocidad*tiempo
	velocidad1<-distancia/tiempo_de_auto1
	//Calculo de la aceleracion normal del auto 1 a partir de la formula an=(v al cuadrado)/r
	an1<- velocidad1^2/radio
	//Calculo de la fuerza central del auto 1 a partir de la formula F=m*an
	F1<-masa_auto1*an1
	
	//Calculo de la velocidad del auto 2 a partir de la formula distancia= velocidad*tiempo
	velocidad2<-distancia/tiempo_de_auto2
	//Calculo de la aceleracion normal del auto 2 a partir de la formula an=(v al cuadrado)/r
	an2<- velocidad2^2/radio
	//Calculo de la fuerza central del auto 2 a partir de la formula F=m*an
	F2<-masa_auto2*an2
	
	//Resultados que se obtuvieron a partir de los Calculos
	escribir "La fuerza central para el auto 1 es: ",F1," newton"
	escribir "La fuerza central para el auto 2 es: ",F2," newton"
	//Comparar las fuerzas obtenidas
	F1mayorF2<-F1>F2 o F1=F2 //usar "o" porque si las fuerzas son iguales, la fuerza del auto 1 es mayor que el auto 2
	escribir "Fuerza central del auto 1 es mayor que el auto 2? ",F1mayorF2
	F2mayorF1<-F2>F1
	escribir "Fuerza central del auto 2 es mayor que el auto 1? ",F2mayorF1
	
FinAlgoritmo
