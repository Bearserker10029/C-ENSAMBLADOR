Algoritmo Poker
	Escribir 'Ingrese la carta 1: '
	Leer num1
	Escribir 'Ingrese la carta 2: '
	Leer num2
	Escribir 'Ingrese la carta 3: '
	Leer num3
	Escribir 'Ingrese la carta 4: '
	Leer num4
	Escribir 'Ingrese la carta 5: '
	Leer num5
	
	Si ((num1>=1 y num1<=13) y (num2>=1 y num2<=13) y (num3>=1 y num3<=13) y (num4>=1 y num4<=13) y (num5>=1 y num5<=13)) Entonces
		//verificar si se tiene escalera
		//Primer paso: buscar la carta mayor
		Si (num1>=num2 y num1>=num3 y num1>=num4 y num1>=num5) Entonces
			cartaMayor <- num1
		SiNo
			Si (num2>=num1 y num2>=num3 y num2>=num4 y num2>=num5) Entonces
				cartaMayor <- num2
			SiNo
				Si (num3>=num1 y num3>=num2 y num3>=num4 y num3>=num5) Entonces
					cartaMayor <- num3
				Sino
					Si (num4>=num1 y num4>=num2 y num4>=num3 y num4>=num5) Entonces
						cartaMayor <- num4
					Sino 
						cartaMayor <- num5
					FinSi
				FinSi
			FinSi
		FinSi
		//Segundo paso: Verificar si hau secuencia de tipo escalera
		hayPredecesor1 <-  (num1= (cartaMayor-1) o num2= (cartaMayor-1) o num3= (cartaMayor-1) o num4= (cartaMayor-1) o num5= (cartaMayor-1))
		hayPredecesor2 <-  (num1= (cartaMayor-2) o num2= (cartaMayor-2) o num3= (cartaMayor-2) o num4= (cartaMayor-2) o num5= (cartaMayor-2))
		hayPredecesor3 <-  (num1= (cartaMayor-3) o num2= (cartaMayor-3) o num3= (cartaMayor-3) o num4= (cartaMayor-3) o num5= (cartaMayor-3))
		hayPredecesor4 <-  (num1= (cartaMayor-4) o num2= (cartaMayor-4) o num3= (cartaMayor-4) o num4= (cartaMayor-4) o num5= (cartaMayor-4))
		hayAs <- (num1=1 o num2=1 o num3=1 o num4=1 o num5=1)
		Si (hayAs y cartaMayor=13 y hayPredecesor1 y hayPredecesor2 y hayPredecesor3) Entonces
			Escribir 'Hay escalera real'
		SiNo
			Si (hayPredecesor1 y hayPredecesor2 y hayPredecesor3 y hayPredecesor4) Entonces
				Escribir 'Hay escalera simple'
			SiNo
				Escribir 'No hay escalera ni real ni simple'
			FinSi
		FinSi
	SiNo
		Escribir 'El valor de alguna carta es incorrecto'
	FinSi
FinAlgoritmo
