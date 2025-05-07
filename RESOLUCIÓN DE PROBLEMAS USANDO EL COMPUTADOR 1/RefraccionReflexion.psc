Algoritmo RefraccionReflexion
	Escribir 'Ingrese el índice de refracción 1: '
	Leer n1
	Escribir 'Ingrese el índice de refracción 2: '
	Leer n2
	Escribir 'Ingrese el ángulo incidente en grados sexagesimales: '
	Leer anguloIncidente
	Si (n1>=1 y n2>=1) Entonces
		Si (anguloIncidente>0) Entonces
			Si (anguloIncidente<90) Entonces
				Si (n1>n2) Entonces
					anguloCritico <- asen(n2/n1)
					anguloCritico <- anguloCritico*180/PI
					Si (trunc(anguloIncidente) = trunc(anguloCritico)) Entonces
						Escribir 'Ocurre reflexión interna total - Ángulo crítico'
					SiNo
						Si (anguloIncidente > anguloCritico) Entonces
							Escribir 'Ocurre reflexión interna total'
						SiNo
							anguloIncidente <- anguloIncidente*PI/180
							anguloRefractado <- asen(n1*(sen(anguloIncidente))/n2)
							anguloRefractado <- anguloRefractado * 180/PI
							Escribir 'Ocurre refracción con un ángulo de ', anguloRefractado
						FinSi
					FinSi
				SiNo
					Escribir 'el índice del medio 1 debe ser mayor que el medio 2'
				FinSi
			SiNo
				Escribir 'El ángulo de incidencia debe ser menor que 90'
			FinSi
		SiNo
			Escribir 'El ángulo de incidencia debe ser mayor que cero'
		FinSi		
	SiNo
		Escribir 'Los índices de refracción deben ser números mayores o iguales a uno.'
	FinSi
FinAlgoritmo
