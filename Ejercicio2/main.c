#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


double factorial(double val){
	double calc=1;
	double aux=0;
    int i;
    for(i=1; i<=val; i++){
            aux=calc*i;
            calc=aux;
       }
    
    return calc;
}

void coeficientesPolinomio(double val){
	double (*calc)(double)=factorial;
        int longitud=10000;
        double resultadoCoeficiente;
        char *polinomio = malloc(longitud * sizeof(char));
		polinomio[0] = '\0'; 
		char temp[100];
        int i;

        for (i=val; i>=0; i--) {
 
        	resultadoCoeficiente=calc(val)/(calc(i)*calc(val-i));
        	
	        if (i != 0){
	        	sprintf(temp, " (%g x^%d) +", resultadoCoeficiente, i);
			}
	            
	        else{
	        	sprintf(temp, " %g", resultadoCoeficiente);
			}
	            
	        strcat(polinomio, temp);
    }

    printf("%s\n\n", polinomio);
    free(polinomio);

    }


void resultadoPolinomio(double val){
		double (*calc)(double)=factorial;
        double  resultadoCoeficiente;
        int longitud=10000;
        char *polinomio = malloc(longitud * sizeof(char));
        polinomio[0] = '\0'; 
		char temp[100];
        double aux=0;
        double acum;
        double resultado=0;
        double x;
		int i;
		
        printf("\nIntroduzca el valor de x a sustituir en el polinomio: ");
		scanf("%lf",&x);
        printf("Sustituyendo...\n");

        //Sustituyendo por la variable del usuario
		
        for (i =val; i>=0; i--) {
            resultadoCoeficiente=calc(val)/(calc(i)*calc(val-i));

            if(i!=0){
            	sprintf(temp, " (%g*%g^%d) +", resultadoCoeficiente, x, i);
            }
            else{
            	sprintf(temp, " %g\n\n", resultadoCoeficiente);
            }
            strcat(polinomio, temp);
        }

        //Resolviendo el exponente

        for ( i =val; i>=0; i--) {
            resultadoCoeficiente=calc(val)/(calc(i)*calc(val-i));

            if(i!=0){
            	sprintf(temp, " (%g*%g) +", resultadoCoeficiente, pow(x,i));
            }
            else{
            	sprintf(temp, " %g\n\n", resultadoCoeficiente);
            }
            strcat(polinomio, temp);
        }

        //Resolviendo multiplicaciones

        for ( i =val; i>=0; i--) {
            resultadoCoeficiente=calc(val)/(calc(i)*calc(val-i));

            if(i!=0){
            	sprintf(temp, " (%g) +", resultadoCoeficiente*pow(x,i));
            }
            else{
            	sprintf(temp, " %g\n\n", resultadoCoeficiente);
            }
            strcat(polinomio, temp);
        }

        //Resultado

        for (i =val; i>=0; i--) {
            resultadoCoeficiente=calc(val)/(calc(i)*calc(val-i));
            aux=resultadoCoeficiente*pow(x,i);
            acum=resultado+aux;
            resultado=acum;
        }

        printf("\n%s\nEl resultado es %g",polinomio, resultado);
        free(polinomio);
    }

void modificarArchivo(char tiempo[]){
	FILE *fptr;
	fptr = fopen("C:/Users/User/Downloads/proyectosJavaIntellij/Ejercicio2/pruebaDiagnostica/Ejercicio2.txt", "a");
	fprintf(fptr, tiempo);
	fclose(fptr);
}


int main(int argc, char *argv[]) {
	
	void (*formula)(double)= coeficientesPolinomio;
	void (*formula1)(double)= resultadoPolinomio;
	char cadena[100]="\n\n Este programa de C se ejecuto en:";
	char cadena2[20];
	double val;
	clock_t inicio, fin;
    float tiempo;
	printf("Introduzca el grado del polinomio: ");
	scanf("%lf",&val);
	inicio = clock();
	formula(val);
	formula1(val);
	fin=clock();
	tiempo = (float) (fin- inicio)/CLOCKS_PER_SEC;
	sprintf(cadena2, " %f segundos", tiempo);
	strcat(cadena,cadena2);
    modificarArchivo(cadena);
    
	
	return 0;
}
