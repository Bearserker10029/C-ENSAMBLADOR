Algoritmo RefraccionReflexion
	Escribir 'Ingrese el �ndice de refracci�n 1: '
	Leer n1
	Escribir 'Ingrese el �ndice de refracci�n 2: '
	Leer n2
	Escribir 'Ingrese el �ngulo incidente en grados sexagesimales: '
	Leer anguloIncidente
	Si (n1>=1 y n2>=1) Entonces
		Si (anguloIncidente>0) Entonces
			Si (anguloIncidente<90) Entonces
				Si (n1>n2) Entonces
					anguloCritico <- asen(n2/n1)
					anguloCritico <- anguloCritico*180/PI
					Si (trunc(anguloIncidente) = trunc(anguloCritico)) Entonces
						Escribir 'Ocurre reflexi�n interna total - �ngulo cr�tico'
					SiNo
						Si (anguloIncidente > anguloCritico) Entonces
							Escribir 'Ocurre reflexi�n interna total'
						SiNo
							anguloIncidente <- anguloIncidente*PI/180
							anguloRefractado <- asen(n1*(sen(anguloIncidente))/n2)
							anguloRefractado <- anguloRefractado * 180/PI
							Escribir 'Ocurre refracci�n con un �ngulo de ', anguloRefractado
						FinSi
					FinSi
				SiNo
					Escribir 'el �ndice del medio 1 debe ser mayor que el medio 2'
				FinSi
			SiNo
				Escribir 'El �ngulo de incidencia debe ser menor que 90'
			FinSi
		SiNo
			Escribir 'El �ngulo de incidencia debe ser mayor que cero'
		FinSi		
	SiNo
		Escribir 'Los �ndices de refracci�n deben ser n�meros mayores o iguales a uno.'
	FinSi
FinAlgoritmo
