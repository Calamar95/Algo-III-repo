#include <time.h>
#include <stdio.h>
using namespace std;


int main() {


int iteraciones = 0;
double tiempo_promedio = 0;

while (iteraciones <= 100) {
			clock_t startTime = clock();  //empezamos a medir el tiempo

			int j = 1; //f es la cantidad máxima de ciudades conectadas de un ramal.

			tiempo_promedio += ((double)clock() - startTime) / (CLOCKS_PER_SEC / 1000); //primero sumo los tiempos de las 100 iteraciones.
			 printf("%f \n", tiempo_promedio);
			iteraciones++;
	    }



	    tiempo_promedio = tiempo_promedio/100.0; //calculo el promedio del tiempo de las 100 iteraciones en milisegundos.
	    printf("%f \n", tiempo_promedio);  //se descomenta para saber los tiempos promedios para el gráfico.




	    tiempo_promedio = 0.0;
	    iteraciones = 0;

}