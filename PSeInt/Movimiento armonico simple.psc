Algoritmo MovArmSimple
	//Ingresar los datos del escenario 1
	Escribir "Datos Escenario 1: "
	Escribir  "Ingrese la amplitud (m) : "
	leer amplitud
	Escribir  "Ingrese la frecuencia ciclica (rad/s) : "
	leer frecuencia
	Escribir  "Ingrese la fase inicial (grados sexagesimales) : "
	leer faseinicial
	Escribir  "Ingrese el tiempo (min) : "
	leer tiempo
	
	// Formula para comprobar los datos del escenario 1
	comprobardatos1<- amplitud>0 y frecuencia>0 y faseinicial>=0 y faseinicial<360 y tiempo>0
	
	//Usar la estructura algoritmica selectiva debido a que piden que se ejecute en caso los datos sean correctos
	si comprobardatos1 Entonces
		
		//Formulas dadas en el ejercicio y convertir los datos a las magnitudes dadas para las formulas
		distancia<-amplitud*sen(frecuencia*(tiempo*60)+faseinicial*(2*pi/(360)))
		velocidad<-frecuencia*rc(amplitud^2-distancia^2)
		aceleracion<-amplitud*(frecuencia^2)*sen(frecuencia*(tiempo*60)+faseinicial*(2*pi/(360)))*(-1)
		
		// Resultados obtenidos de las formulas en el escenario 1 si la proposicion es verdadera
		Escribir "Resultados Escenario 1"
		Escribir "Distancia ", distancia," m"
		Escribir "Velocidad ", velocidad," m/s"
		Escribir "Aceleracion ", aceleracion,"m/s2"
		
		//Ejecucion si la proposicion es falsa
	SiNo
		
		//Resultado obtenido si la proposicion es falsa
		Escribir "Para el escenario 1 los datos no son validos"
	FinSi
	
	//Ingresar los datos del escenario 2
	Escribir "Datos Escenario 2: "
	Escribir "Ingrese la velocidad (m/h) :"
	leer velocidad2
	Escribir "Ingrese la amplitud (m) :"
	leer amplitud2
	Escribir "Ingrese la distancia (cm) :"
	leer distancia2
	Escribir "Ingrese el tiempo (s) :"
	leer tiempo2
	
	// Formula para comprobar los datos del escenario 2
	comprobardatos2<- amplitud2>0 y amplitud2<100 y velocidad2>0 y distancia2>0 y tiempo2>0
	
	si comprobardatos2 Entonces
		
		//Formulas dadas en el ejercicio y convertir los datos a las magnitudes dadas para las Formulas
		frecuencia2<-(velocidad2/3600)/(rc(amplitud2^2-(distancia2/100)^2))
		faseinicial2<- acos((velocidad2/3600)/(amplitud2*frecuencia2))-frecuencia2*tiempo2
		aceleracion2<- amplitud2*(frecuencia2^2)*sen(frecuencia2*tiempo2+faseinicial2)*(-1)
		
		// Resultados obtenidos de las Formulas en el escenario 2 si la proposicion es verdadera
		Escribir "Resultados Escenario 2"
		Escribir "Frecuencia ciclica ", frecuencia2," rad/s"
		Escribir "Fase inicial ", faseinicial2," rad"
		Escribir "Aceleracion ", aceleracion2, " m/s2"
		
		//Ejecuci�n si la proposicion es falsa
	sino
		
		//Resultado obtenido si la proposicion es falsa
		Escribir " Para el escenario 2 los datos no son v�lidos"
	FinSi
	
	//Comprobar si Aceleracion 1 es mayor Aceleracion 2
	ac1mayorac2<-aceleracion-aceleracion2
	
	//Usar la estructura algoritmica selectiva debido a que piden que se ejecute en caso los datos sean correctos
	si ac1mayorac2>0 y comprobardatos1 y comprobardatos2 entonces
		
		//Resultados obtenidos
		Escribir "En el escenario 2 la Aceleracion es menor que el escenario 1"
		Escribir "la diferencia entre las aceleraciones es: ", ac1mayorac2," m/s2"
	finsi	
	si ac1mayorac2<0 y comprobardatos1 y comprobardatos2 entonces
		
		//Resultados obtenidosy multiplicar por -1 debido a que el resultado de ac1mayorac2 es negativo
		Escribir "En el escenario 2 la aceleracion es mayor o igual que el escenario 1"
		Escribir "la diferencia entre las aceleraciones es: ", ac1mayorac2*(-1)," m/s2"
	FinSi
FinAlgoritmo
