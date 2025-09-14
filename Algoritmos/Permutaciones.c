#include <stdio.h>

int validarLetras(char car1,char car2,char car3,char car4);
int validarMayusc(char car);
void mostrarEncontrarPermutaciones(char car1,char car2,char car3,char car4,int *cantTotal,
char *letraImp1Mayor,char *letraImp2Mayor,char *letraImp3Mayor,char *letraImp4Mayor,int *posicion,int *mayor);
char buscarLetra(int ,char ,char , char ,char);
int calcularMayorNumero(char letraImp1Mayor,char letraImp2Mayor,
char letraImp3Mayor,char letraImp4Mayor);

int main(){
    int cantTotal=0,mayor=0,calculo,posicion;
    char car1,car2,car3,car4;
    char letraImp1Mayor,letraImp2Mayor,letraImp3Mayor,letraImp4Mayor;
    printf("Ingrese 4 caracteres:");
    scanf(" %c %c %c %c",&car1,&car2,&car3,&car4);
    if (validarLetras(car1,car2,car3,car4)){
        mostrarEncontrarPermutaciones(car1,car2,car3,car4,&cantTotal,&letraImp1Mayor,
        &letraImp2Mayor,&letraImp3Mayor,&letraImp4Mayor,&posicion,&mayor);
        calcularMayorNumero(letraImp1Mayor,letraImp2Mayor,letraImp3Mayor,letraImp4Mayor);
        printf("Cantidad de permutaciones: %d\n",cantTotal);
        printf("El mayor numero formado es: %d\n",mayor);
        printf("Es el resultado de la permutacion %d de las letras %c %c %c %c ",posicion,letraImp1Mayor,letraImp2Mayor,
        letraImp3Mayor,letraImp4Mayor);
        printf(" %dx1000+ %dx100+ %dx10+ %d = %d\n",letraImp1Mayor,letraImp2Mayor,
        letraImp3Mayor,letraImp4Mayor,mayor);
    }
    else
        printf("Las letras ingresadas no son mayusculas o no son diferentes entre si\n");
    return 0;
}

int validarLetras(char car1,char car2,char car3,char car4){
    int mayusc,dif;
    mayusc=validarMayusc(car1) && validarMayusc(car2) && validarMayusc(car3) && validarMayusc(car4);
    dif=car1!=car2 && car1!=car3 && car1!=car4 && car2!=car3 && car2!=car4 && car3!=car4;
    return mayusc && dif;
}

int validarMayusc(char car){
    return car>='A' && car<='Z';
}

void mostrarEncontrarPermutaciones(char car1,char car2,char car3,char car4,int *cantTotal,
char *letraImp1Mayor,char *letraImp2Mayor,char *letraImp3Mayor,char *letraImp4Mayor,int *posicion,int *mayor){
    int i,j,k,l,cant=0,calculo;
    char letraImp1,letraImp2,letraImp3,letraImp4;
    for(i=1;i<=4;i++){
        for (j=1;j<=4;j++){
            for (k=1;k<=4;k++){
                for (l=1;l<=4;l++) {
                    if (i!=j && i!=k && i!=l && j!=k && j!=l && k!=l){
                        letraImp1=buscarLetra(i,car1,car2,car3,car4);
                        letraImp2=buscarLetra(j,car1,car2,car3,car4);
                        letraImp3=buscarLetra(k,car1,car2,car3,car4);
                        letraImp4=buscarLetra(l,car1,car2,car3,car4);
                        cant++;
                        printf(" %d) %c %c %c %c\n",cant,letraImp1,letraImp2,letraImp3,letraImp4);
                        calculo=calcularMayorNumero(letraImp1,letraImp2,letraImp3,letraImp4);
                        if (calculo>*mayor){
                            *mayor=calculo;
                            *letraImp1Mayor=letraImp1;
                            *letraImp2Mayor=letraImp2;
                            *letraImp3Mayor=letraImp3;
                            *letraImp4Mayor=letraImp4;
                            *posicion=cant;
                        }
                    }
                }
            }
        }
    }
    *cantTotal=cant;
}

char buscarLetra(int num,char car1,char car2, char car3,char car4){
    if (num==1)
        return car1;
    else
        if (num==2)
            return car2;
        else
        if (num==3)
            return car3;
        else
            return car4;
}

int calcularMayorNumero(char letraImp1Mayor,char letraImp2Mayor,
char letraImp3Mayor,char letraImp4Mayor){
    return letraImp1Mayor*1000+letraImp2Mayor*100+letraImp3Mayor*10+letraImp4Mayor;
}
