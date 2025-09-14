Algoritmo movimientodelbloqueinclinado
	Escribir "Ingrese la altura del bloque al piso y su unidad de medida (c:centimetros, d: decimetros, m:metros)"
	leer altura,unidad
	si altura>0 Entonces
		si unidad="c" o unidad ="d" o unidad="m" Entonces
			escribir "Ingrese el coseno del angulo: "
			leer coseno
			si coseno>=-1 y coseno<=1 Entonces
				escribir "Ingrese si existe fricci�n entre el bloque y el plano indicado, si (S o s), no (N o n) :"
				leer friccion
				si friccion="s" o friccion="S" o friccion="n" o friccion="N" entonces
					angulo<-acos(coseno)
					si angulo*180/pi>0 y angulo*180/pi<90 Entonces
						si unidad="c" entonces alturaenm<-altura/100
						FinSi
						si unidad="d" entonces alturaenm<-altura/10
						FinSi
						si unidad="m" entonces alturaenm<-altura
						FinSi
						si friccion="s" o friccion="S" Entonces
							escribir"Ingrese el coeficiente de rozamiento din�mico"
							leer coefrozamiento
							si coefrozamiento>0 y coefrozamiento<=tan(angulo)entonces
								escribir "Cuando S� existe fricci�n entre el objeto y plano inclinado"
								acfriccion<-9.81*sen(angulo)-coefrozamiento*9.81*cos(angulo)
								tiempofriccion<-(1/(raiz(sen(angulo)*(sen(angulo)-coefrozamiento*cos(angulo)))))*raiz(2*alturaenm/9.81)
								velocidadfriccion<-raiz((sen(angulo)-coefrozamiento*cos(angulo))/sen(angulo))*raiz(2*9.81*alturaenm)
								escribir "La aceleraci�n es ",acfriccion*3600, "m/min2"
								escribir "El tiempo que tarda el bloque en llegar al final del plano inclinado es: ",tiempofriccion/60," min"
								escribir "La velocidad final del bloque es ",velocidadfriccion*60," m/min"
							sino escribir"El coeficiente debe ser positivo o no existe movimiento porque el coeficiente es mayor a la tangente del angulo"
							fin si
						SiNo
							escribir "Cuando NO existe fricci�n entre el objeto y plano inclinado"
							acsinfriccion<-9.81*sen(angulo)
							tiemposinfriccion<-(1/sen(angulo))*raiz(2*alturaenm/9.81)
							velocidadsinfriccion<-raiz(2*9.81*alturaenm)
							escribir "La aceleraci�n es",acsinfriccion, "m/s2"
							escribir "El tiempo que tarda el bloque en llegar al final del plano inclinado es: ",tiemposinfriccion," s"
							escribir "La velocidad final del bloque es ",velocidadsinfriccion," m/s"
						FinSi
						
						
					sino escribir "El �ngulo debe ser mayor a 0 y menor a 90 grados sexagesimales"
					FinSi
				sino escribir "No se ingres� correctamente si existe o no fricci�n entre el bloque y el plano inclinado"
				FinSi
			sino escribir "El coseno del �ngulo no es correcto"
			FinSi
			finsi
	sino escribir "Los datos de la altura no son correctos"	
	FinSi
FinAlgoritmo
