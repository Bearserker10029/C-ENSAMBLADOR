Algoritmo ValidarRectángulo
	Escribir 'Ingrese las coordenadas del punto A: '
	Leer xA,yA
	Escribir 'Ingrese las coordenadas del punto B: '
	Leer xB,yB
	Escribir 'Ingrese las coordenadas del punto C: '
	Leer xC,yC
	mAB <- (yB - yA)/(xB - xA)
	mBC <- (yC - yB)/(xC - xB)
	//validar si AB y BC son perpendiculares para ingresar el punto D
	Si ((mAB*mBC) = -1) Entonces
		Escribir 'Ingrese las coordenadas del punto D: '
		Leer xD,yD
		mAD <- (yD - yA)/(xD - xA)
		mCD <- (yD - yC)/(xD - xC)
		//validamos si las rectas opuestas son paralelas
		Si (mAB = mCD y mBC = mAD) Entonces
			Si ((mAD*mCD)=-1) Entonces
				Escribir 'Los puntos ingresados forman un rectángulo'
			SiNo
				Escribir 'Las rectas AD y CD no son perpendiculares'
			FinSi
		SiNo
			Escribir 'Las rectas (AB,CD) o (BC,AD) no son paralelas'
		FinSi
	SiNo
		Escribir 'Las rectas AB y BC no son perpendiculares'
	FinSi	
FinAlgoritmo
