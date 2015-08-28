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
		
		Ronda(vector<char> exploradoras, vector< vector<char> > amigas);
		
		vector<char> amigasDe(char e);
		//bool esAmigaDe(char e);
		
		vector<char> exploradoras();
		
		tuple<int, vector<char> > mejorOrden();

		void verRonda();

		



	private:

		vector< vector<char> > friends;
		vector<char> explorers;

		// El conjunto de amigas en la posicion i de friends corresponde a la exploradora en la posicion i en explorers.

		void completarAmigas (vector<char>& exploradoras, vector<vector<char> >& amigas);
		tuple<int, int, vector<char> > calcularDistancias();
		bool pertenece (vector<char> v , char e);
		bool perteneceConPos (vector<char> v , char e, int& posicion);
		tuple<int, int, vector<char> > calcularDistancias (vector<char> permutacion, vector<char> e, vector<vector<char> > a);
};

Ronda::Ronda(){}


Ronda::Ronda(vector<char> exploradoras, vector< vector<char> > amigas) {
	explorers = exploradoras;
	friends = amigas; 
	completarAmigas(explorers, friends);
}

void Ronda::verRonda() {
	cout << "[";
	for ( int j = 0; j < explorers.size() ; j++ ) {
		cout << "{" << explorers[j] << " ; " << "[";
		for ( int i = 0; i < friends[j].size() ; i++ ) {
			if ( i == friends[j].size() - 1 ) {
				cout << friends[j][i];
			}else{
				cout << friends[j][i] << ",";
			}
		}
		cout << "] }";
	}
	cout << "]" <<endl;
}

vector<char> Ronda::amigasDe(char e) {
	int i = 0;
	while ( explorers[i] != e ) i++;
	return friends[i];
}

vector<char> Ronda::exploradoras() {
	return explorers;
}


tuple<int, vector<char> > Ronda::mejorOrden() {
	vector<char> exploradoras = explorers;
	sort( exploradoras.begin(), exploradoras.begin()+exploradoras.size() );
	tuple<int, int, vector<char> > minimaSuma = calcularDistancias (exploradoras, explorers, friends);
	while ( next_permutation(exploradoras.begin(), exploradoras.begin()+exploradoras.size()) ){
		tuple<int, int, vector<char> > dist = calcularDistancias(exploradoras, explorers, friends);
		if ( get<0>(dist) < get<0>(minimaSuma) ) {
			minimaSuma = dist;
		}
	}
	tuple<int, vector<char> > res;
	get<0>(res) = get<1>(minimaSuma);
	get<1>(res) = get<2>(minimaSuma);
	return res;
}


// Completa el input de manera tal que en el vector esten todas las exploradoras, cada una con todas sus amigas
void Ronda::completarAmigas (vector<char>& exploradoras, vector<vector<char> >& amigas) {
	int i = 0;
	while ( i < exploradoras.size() ) {
		int j = 0;
		while ( j < amigas[i].size() ) {
			int pos;
			if ( perteneceConPos(exploradoras, amigas[i][j], pos) ) {
				if ( !(pertenece(amigas[pos], exploradoras[i])) ) {
					amigas[pos].push_back(exploradoras[i]);
				}
			}else{
				exploradoras.push_back(amigas[i][j]);
				vector<char> nueva = {exploradoras[i]};
				amigas.push_back(nueva);
			}
			j++;
		}
		i++;
	}
}


bool Ronda::pertenece (vector<char> v , char e) {
	int i = 0;
	bool noEncontrado = true;
	while (noEncontrado && i < v.size() ){
		noEncontrado = !(v[i] == e);
		i++;
	}
	return !noEncontrado;
}

//Funcion pertenece para vector de tuplas respecto de la primer coordenada
bool Ronda::perteneceConPos (vector<char> v , char e, int& posicion) {
	int i = 0;
	bool noEncontrado = true;
	while (noEncontrado && i < v.size() ){
		noEncontrado = !(v[i] == e);
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
	cout << "]" << endl;
}


int main() {

	//a fb;b gc;d gc;f agh;e hd

	vector <char> amigas1 = {'f', 'b'};
	//imprimir(amigas1);
	

	vector <char> amigas2 = {'g', 'c', 'a'};
	//imprimir(amigas2);


	vector <char> amigas3 = {'g', 'c', 'e'};
	//imprimir(amigas3);
	

	vector <char> amigas4 = {'a', 'g', 'h'};
	//imprimir(amigas4);


	vector <char> amigas5 = {'h', 'd'};
	//imprimir(amigas5);

	vector <char> amigas6 = {'b', 'd', 'f'};

	vector <char> amigas7 = {'b', 'd'};

	vector <char> amigas8 = {'f', 'e'};

	vector<vector<char> > amigas = {amigas1, amigas2, amigas3, amigas4, amigas5, amigas6, amigas7, amigas8};

	vector<char> exploradoras = {'a', 'b', 'd', 'f', 'e', 'g', 'c', 'h'};


	vector<char> permutacion = {'a', 'b', 'c', 'f', 'g', 'd', 'h', 'e'};

	Ronda r1 (exploradoras, amigas);
	r1.verRonda();
	imprimir(get<1>(r1.mejorOrden()));




//abcfgdhe

}



//Dada una ronda, calcula la suma de las distancias entre las exploradoras que son amigas, y la mayor distancia entre 2
tuple<int, int, vector<char> > Ronda::calcularDistancias (vector<char> permutacion, vector<char> e, vector<vector<char> > a) {
	int i = 0;
	int suma = 0;
	int maxLograda = 0;
	while ( i < permutacion.size() ) {
		int indice;
		perteneceConPos(e, permutacion[i], indice);
		vector<char> amigas = a[indice];
		int j = 0;
		while ( j < amigas.size() ) {                    
			int pos;
			int distancia;
			perteneceConPos(permutacion, amigas[j], pos);
			if (pos - i > 0) {
				if (pos - i > permutacion.size() / 2) {					
					distancia = permutacion.size() - (pos - i); 
				}else{
					distancia = pos - i;
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