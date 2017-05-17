
#include <cstdlib>
#include <stdio.h>
#include <time.h>

using namespace std;

//******************************************************************************
//                      FUNCION fac
//Su funcion es calcular el factorial de un numero
//******************************************************************************

double fac(double num){
    double i=1;
    double fac=1;
    for(i;i<=num;i++){
        fac=fac*i;
    }
    return fac;
}

//*****************************************************************************
//                      FUNCION facR
//Su funcion es calcular el factorial de un numero recursivamente
//******************************************************************************

double facR(double n){
    //Caso base
    if(n<2){
        return 1;
    }else{  
        return (n*facR(n-1));
    }
}

//*****************************************************************************
//                      FUNCION coBin
//Su funcion es cacular el coeficinente binomial de forma iterativa
//******************************************************************************

double coBin(int n,int k){
    //Calculamos el factorial de n
    double facN=fac(n);
    //Calculamos el factorial de k
    double facK=fac(k);
    //Calculamos el coeficiente
    return (facN/(facK*(n-k)));
    
}

//*****************************************************************************
//                      FUNCION coBinRic
//Su funcion es calcular el coeficiente binomial de forma recursiva
//******************************************************************************

double coBinRic(double n,double k){
    
    return facR(n)/facR(k)/facR(n-k);
}


int main(int argc, char** argv) {

    //Los dos numeros a calcular
    double n,k;
    printf("Insertar n:");
    scanf("%lf",&n);
    printf("Insertar k:");
    scanf("%lf",&k);
    double time1,time2;
    
    //Inicializamos la variable start para calcular el tiempo
    double start=clock();
    double res=coBin(n,k);
    double end=clock();
    //Finalizamos la ejecucion y calculamos el tiempo
    time1 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("El resultado del algoritmo iterarativo es %f\n",res);
    printf("El tiempo implicado en dicho algoritmo es %f\n",time1);
    
    double start1=clock();
    double resRic=coBinRic(n,k);
    double end1=clock();
    
    time2 = ((double) (end1 - start1)) / CLOCKS_PER_SEC;
    printf("El resultado del algoritmo recursivo es %f\n",resRic);
    printf("El tiempo implicado en dicho algoritmo es %f\n",time2);

    return 0;
}

