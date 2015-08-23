#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <time.h>

using namespace std;

int conectar(vector<int> v , int longCable) {

	int resTemp = 1;
	int start = 0;
	int actual = 0;
	int aux = 0;

	while (longCable > 0 && v[actual] != v.back()) {
		aux = longCable;
		if (actual == 0) {
			longCable = longCable - v[actual+1]; //si comparamos con el primer elemento del vector (el km 0), entonces a longCable le restamos el valor del segundo elemento.
		} else {
			longCable = longCable -(v[actual+1] - v[actual]); //si comparamos con otro elemento, a longCable le restamos la diferencia entre dicho elemento y su próximo.
		}

		if (longCable >= 0) {
			resTemp++; //actualizamos resTemp solo si longCable sigue siendo positivo.
		}
		actual++;
	}

	if (resTemp == 1) {
		resTemp = 0; //si resTemp sigue en 1 como lo definimos, es porque no se conectó ninguna ciudad, entonces lo seteamos en 0.
	}

	if (longCable < 0) {
		longCable = aux; //si nos pasamos y longCable queda negativo, volvemos al valor anterior.
	}

	while (v[actual] != v.back()) { //mientras que el elemento actual no sea el último..
		int conectadas;
		if (resTemp == 0) {
			conectadas = 0; //si no conectamos ninguna ciudad, contectadas será 0, start 1, actual+1
			start++;
			actual++;
		} else {
			conectadas = resTemp - 1; //si conectamos alguna ciudad, 'conectadas' será la cant de ciudades conectadas - 1.
			longCable = longCable + (v[start+1]-v[start]);
			start++;
		}

		while (longCable >= 0 && v[actual]!= v.back()) {
			longCable = longCable - (v[actual+1]- v[actual]);
			actual++;
			if (longCable >= 0) {
				conectadas++;
			}
		}

		if (conectadas > resTemp) {
			resTemp = conectadas;
		}

	}

	if (resTemp == 1) {
		resTemp = 2;
	}

	//imprimimos por pantalla el tiempo transcurrido para cada iteracion de 'conectar'.
	//printf("Tiempo en segundos transcurrido de un ramal: %f \n", ((double)clock() - startTime) / CLOCKS_PER_SEC);

	return resTemp;
}


int main() {

	ofstream out;
	out.open("resultado.out");
    ifstream in("Tp1Ej1.in");

    int iteraciones = 0;
    double tiempo_promedio = 0;

    while (in.good()) {
    	vector<int> vec;
    	vec.push_back(0);

	    string st;
	    getline(in,st);
	    istringstream iss;
	    iss.str(st);
	    iss.clear();

	    int a;
	    iss>>a;

	    
	    getline(in,st);	    
	    iss.str(st);
	    iss.clear();
	    int b;
	    
	    while (iss>>b) {
	    	vec.push_back(b);
	    }

		while (iteraciones <= 100) {
			clock_t startTime = clock();  //empezamos a medir el tiempo

			int f = conectar(vec,a); //f es la cantidad máxima de ciudades conectadas de un ramal.

			tiempo_promedio += ((double)clock() - startTime) / (CLOCKS_PER_SEC / 1000); //primero sumo los tiempos de las 100 iteraciones.

			if(iteraciones == 0){
				out << f << endl; //en el archivo de salida guardo una vez la cantidad maxima de ciudades conectadas del ramal.
			}
			iteraciones++;
	    }

	    tiempo_promedio = tiempo_promedio/100.0; //calculo el promedio del tiempo de las 100 iteraciones.
	    printf("Tiempo en milisegundos de un ramal: %f \n", tiempo_promedio);

	    tiempo_promedio = 0.0;
	    iteraciones = 0;
    }

    out.close();

    /*

	vector<int> a;

	a.push_back(0);
	a.push_back(6);
	a.push_back(8);
	a.push_back(12);
	a.push_back(15);	
	int a1 = conectar(a,6);
	cout << "total " << a1 << endl;

	vector<int> b;
	b.push_back(0);
	b.push_back(8);
	b.push_back(14);
	b.push_back(20);
	b.push_back(40);
	b.push_back(45);
	b.push_back(54);
	b.push_back(60);
	b.push_back(67);
	b.push_back(74);
	b.push_back(89);
	b.push_back(99);
	int b1 = conectar(b,35);
	cout << "total " <<  b1 << endl;

	
	vector<int> c;
	c.push_back(0);
	c.push_back(35);
	c.push_back(87);
	c.push_back(141);
	c.push_back(163);
	c.push_back(183);
	c.push_back(252);
	c.push_back(288);
	c.push_back(314);
	c.push_back(356);
	c.push_back(387);
	int c1 = conectar(c,100);
	cout << "total " << c1 << endl;

	vector<int> d;
	d.push_back(0);
	d.push_back(6);
	d.push_back(8);
	d.push_back(16);
	d.push_back(19);
	d.push_back(28);
	d.push_back(32);
	d.push_back(37);
	d.push_back(45);
	d.push_back(52);
	d.push_back(60);
	d.push_back(69);
	d.push_back(78);
	d.push_back(82);
	int d1 = conectar(d,90);
	cout <<  "total " << d1 << endl;
	
	vector<int> e;
	e.push_back(0);
	e.push_back(5);
	e.push_back(13);
	e.push_back(19);
	e.push_back(26);
	e.push_back(35);
	int e1 = conectar(e,4);
	cout << "total " << e1 << endl;

	vector<int> f;
	f.push_back(0);
	f.push_back(5);
	f.push_back(13);
	f.push_back(19);
	f.push_back(26);
	f.push_back(35);
	int f1 = conectar(f,5);
	cout << "total " << f1 << endl;

	vector<int> g;
	g.push_back(0);
	g.push_back(7);
	g.push_back(16);
	g.push_back(19);
	g.push_back(27);
	g.push_back(33);
	int g1 = conectar(g,5);
	cout << "total " << g1 << endl;

	vector<int> h;
	h.push_back(0);
	h.push_back(2);
	h.push_back(5);
	h.push_back(8);
	h.push_back(14);
	h.push_back(18);
	int h1 = conectar(h,8);	
	cout <<  "total " << h1 << endl;

	vector<int> i;
	i.push_back(0);
	i.push_back(3);
	i.push_back(6);
	i.push_back(9);
	i.push_back(15);
	i.push_back(19);
	int i1 = conectar(i,8);
	cout << "total " << i1 << endl;

	d.push_back(0);
	d.push_back(7);
	d.push_back(16);
	d.push_back(19);
	d.push_back(27);
	d.push_back(33);

	d.push_back(0);
	d.push_back(2);
	d.push_back(5);
	d.push_back(8);
	d.push_back(14);
	d.push_back(18);

	d.push_back(0);
	d.push_back(3);	
	d.push_back(6);
	d.push_back(9);
	d.push_back(15);
	d.push_back(19);

	int d1 = conectar(d,90);
	
*/
	return 0;
}