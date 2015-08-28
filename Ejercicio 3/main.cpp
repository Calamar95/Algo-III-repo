using namespace std;
#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>
#include <sys/time.h>
#include <sstream>
#include <fstream>


class Ronda {
	public:
		Ronda();
		void agregarExploradora(char e, vector<char> amigas);
		vector<char> dameAmigasDe(char e);
		bool esAmigaDe?(char )



};


tuple<int, int, vector<char> > calcularDistancias (vector<char> permutacion, vector<tuple<char,vector<char> > > entrada);
vector<char> buscarAmigas (char e, vector<tuple<char,vector<char> > > entrada);
bool pertenece (vector<char> v , char e);
void imprimir (vector<char>);
void completarAmigas (vector<tuple<char,vector<char> > >& entrada);
void imprimirG (vector<tuple<char,vector<char> > > v); 
bool perteneceBis (vector<tuple<char,vector<char> > > v , char e, int& posicion);



tuple<int, vector<char> > ejercicio3 (vector<tuple<char,vector<char> > > entrada) {
	completarAmigas(entrada);
	vector<char> exploradoras;
	for(int i = 0; i < entrada.size();i++){
		exploradoras.push_back(get<0>(entrada[i]));
	}
	sort(exploradoras.begin(), exploradoras.begin()+exploradoras.size());
	tuple<int, int, vector<char> > minimaSuma = calcularDistancias (exploradoras, entrada); 
	while (next_permutation(exploradoras.begin(), exploradoras.begin()+exploradoras.size()) ){
		tuple<int, int, vector<char> > dist = calcularDistancias(exploradoras, entrada);
		if (get<0>(dist) < get<0>(minimaSuma)) {
			minimaSuma = dist;
		}
	}
	tuple<int, vector<char> > res;
	get<0>(res) = get<1>(minimaSuma);
	get<1>(res) = get<2>(minimaSuma);
	return res;
}


// Completa el input de manera tal que en el vector esten todas las exploradoras, cada una con todas sus amigas
void completarAmigas (vector<tuple<char,vector<char> > >& entrada) {
	int i = 0;
	while (i < entrada.size()) {
		int j = 0;
		while ( j < (get<1>(entrada[i])).size() ) {
			int pos;
			if  (perteneceBis(entrada, (get<1>(entrada[i]))[j] , pos ) ) {
				if ( !(pertenece ( get<1>(entrada[pos]), get<0>(entrada[i]) ) ) ) {
					 (get<1>(entrada[pos])).push_back(get<0>(entrada[i]));
				}
			}else{
				tuple<char,vector<char> > nueva;
				get<0>(nueva) = (get<1>(entrada[i]))[j];
				vector <char> v = { get<0>(entrada[i]) };
				get<1>(nueva) = v;
				entrada.push_back(nueva);
			}
			j++;
		}
		i++;
	}
}


//Dada una ronda, calcula la suma de las distancias entre las exploradoras que son amigas, y la mayor distancia entre 2
tuple<int, int, vector<char> > calcularDistancias (vector<char> permutacion, vector<tuple<char,vector<char> > > entrada){
	int i = 0;
	int suma = 0;
	int maxLograda = 0;
	while (i < permutacion.size()) {
		vector<char> amigas = buscarAmigas(permutacion[i], entrada);
		int j = i + 1;
		while (j < permutacion.size()) {
			if ( pertenece(amigas, permutacion[j]) ) {                     
				int distancia;
				if (j - i > permutacion.size() / 2) {					
					distancia = permutacion.size() - (j - i); 
				}else{
					distancia = j - i;
				}
				if (maxLograda < distancia) maxLograda = distancia;
				suma = suma + distancia;
			}
			j++;
		} 
		i++;
	}
	tuple<int, int, vector<char> > res;
	get<0>(res) = suma;
	get<1>(res) = maxLograda;
	get<2>(res) = permutacion;
	return res;
}


//Devuelve el conjunto de amigas de una exploradora
vector<char> buscarAmigas (char e, vector<tuple<char,vector<char> > > entrada) {
	int i = 0;
	while (get<0>(entrada[i]) != e) {
		i++;
	}
	return get<1>(entrada[i]);
}

//Funcion pertenece para vector
bool pertenece (vector<char> v , char e) {
	int i = 0;
	bool noEncontrado = true;
	while (noEncontrado && i < v.size() ){
		noEncontrado = !(v[i] == e);
		i++;
	}
	return !noEncontrado;
}

//Funcion pertenece para vector de tuplas respecto de la primer coordenada
bool perteneceBis (vector<tuple<char,vector<char> > > v , char e, int& posicion) {
	int i = 0;
	bool noEncontrado = true;
	while (noEncontrado && i < v.size() ){
		noEncontrado = !(get<0>(v[i]) == e);
		i++;
	}
	posicion = i - 1;
	return !noEncontrado;
}



void imprimir (vector<char> v) {
	cout << "[";
	for(int j = 0; j < v.size() ; j++){
		if (j + 1 == v.size()) {
			cout << v[j];	
		}else{
			cout << v[j] << ",";
		}
	}
	cout << "]";
}

void imprimirG (vector<tuple<char,vector<char> > > v) {
	cout << "[";
	for(int j = 0; j < v.size() ; j++){
		cout << "{" << get<0>(v[j]) << " ; ";
		imprimir(get<1>(v[j]));
		cout << "} ";
	}
	cout << "]" <<endl;
}


int main (){
	/*char mychars[] = {'a', 'b', 'c'};
	cout << mychars[0] << ' ' << mychars[1] << ' ' << mychars[2] <<endl;
	while (next_permutation(mychars, mychars+3) ){
		cout << mychars[0] << ' ' << mychars[1] << ' ' << mychars[2] <<endl;
	}

	*/

	/*vector<int> v = {1,4,2,9,7,5};

	cout << "[";
	for(int j = 0; j < v.size() ; j++){
		cout << v[j] << ",";
	}
	cout << "]" <<endl;

	sort (v.begin(), v.begin()+6);

	cout << "[";
	for(int j = 0; j < v.size() ; j++){
		cout << v[j] << ",";
	}
	cout << "]" <<endl;
	*/

//a bcde;b acde;c abde;d abc;e abc

	/*vector <char> amigas1 = {'b', 'c', 'd', 'e'};
	//imprimir(amigas1);
	tuple<char, vector<char> > a1 ('a', amigas1);

	vector <char> amigas2 = {'a', 'c', 'd', 'e'};
	//imprimir(amigas2);
	tuple<char, vector<char> > a2 ('b', amigas2);

	vector <char> amigas3 = {'a', 'b', 'd', 'e'};
	//imprimir(amigas3);
	tuple<char, vector<char> > a3 ('c', amigas3);

	vector <char> amigas4 = {'a', 'b', 'c'};
	//imprimir(amigas4);
	tuple<char, vector<char> > a4 ('d', amigas4);

	vector <char> amigas5 = {'a', 'b', 'c'};
	//imprimir(amigas5);
	tuple<char, vector<char> > a5 ('e', amigas5);

	vector<tuple<char,vector<char> > > inst = {a1, a2, a3, a4, a5};

	tuple<int, vector<char> > resultado = ejercicio3(inst);
	cout << get<0>(resultado) << ";";
	imprimir(get<1>(resultado)); 
*/
/*
	//a bcd;b ae;c ad;d ac;e b


	vector <char> amigas1 = {'b', 'c', 'd'};
	//imprimir(amigas1);
	tuple<char, vector<char> > a1 ('a', amigas1);

	vector <char> amigas2 = {'a', 'e'};
	//imprimir(amigas2);
	tuple<char, vector<char> > a2 ('b', amigas2);

	vector <char> amigas3 = {'a', 'd'};
	//imprimir(amigas3);
	tuple<char, vector<char> > a3 ('c', amigas3);

	vector <char> amigas4 = {'a', 'c'};
	//imprimir(amigas4);
	tuple<char, vector<char> > a4 ('d', amigas4);

	vector <char> amigas5 = {'b'};
	//imprimir(amigas5);
	tuple<char, vector<char> > a5 ('e', amigas5);

	vector<tuple<char,vector<char> > > inst = {a1, a2, a3, a4, a5};

	tuple<int, vector<char> > resultado = ejercicio3(inst);
	cout << get<0>(resultado) << ";";
	imprimir(get<1>(resultado)); 

*/
/*
	//a fb;b gc;d gc;f agh;e hd

	vector <char> amigas1 = {'f', 'b'};
	//imprimir(amigas1);
	tuple<char, vector<char> > a1 ('a', amigas1);

	vector <char> amigas2 = {'g', 'c'};
	//imprimir(amigas2);
	tuple<char, vector<char> > a2 ('b', amigas2);

	vector <char> amigas3 = {'g', 'c'};
	//imprimir(amigas3);
	tuple<char, vector<char> > a3 ('d', amigas3);

	vector <char> amigas4 = {'a', 'g', 'h'};
	//imprimir(amigas4);
	tuple<char, vector<char> > a4 ('f', amigas4);

	vector <char> amigas5 = {'h', 'd'};
	//imprimir(amigas5);
	tuple<char, vector<char> > a5 ('e', amigas5);

	vector<tuple<char,vector<char> > > inst = {a1, a2, a3, a4, a5};

	tuple<int, vector<char> > resultado = ejercicio3(inst);
	cout << get<0>(resultado) << ";";
	imprimir(get<1>(resultado)); 

	//imprimirG(inst);
	//completarAmigas(inst);
	//imprimirG(inst);
*/

/*
	vector <char> amigas1 = {'y', 'z'};
	//imprimir(amigas1);
	tuple<char, vector<char> > a1 ('x', amigas1);

	vector<tuple<char,vector<char> > > inst = {a1};

	tuple<int, vector<char> > resultado = ejercicio3(inst);
	
	
	/*
	cout << get<0>(resultado) << ";";
	imprimir(get<1>(resultado)); 

	*/
	
	ifstream in("Tp1Ej3.in");
	
	while (in.good()) {
	string s;

	getline(in, s, ' ');
	getline(in, s, ';');
	cout << s <<endl;
	}


  
}



