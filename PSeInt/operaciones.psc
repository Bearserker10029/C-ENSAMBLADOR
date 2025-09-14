Algoritmo operaciones
	Escribir "Indicar los operandos y operador"
	Leer operando1, operando2, operador
	div0<-Verdadero
	si operador=="+" entonces resultado<-operando1+operando2
		sino si operador=="-" entonces resultado<-operando1-operando2
			sino si operador=="*" entonces resultado<-operando1*operando2
				sino si	 operador=="/" entonces 
						si operando2<>0 entonces
							resultado<-operando1/operando2
						sino div0<- Falso
							escribir "No se puede dividir entre cero"
						FinSi
				finsi
			FinSi
		finsi
	finsi
	si div0 entonces
		Escribir resultado
		finsi
	FinAlgoritmo
