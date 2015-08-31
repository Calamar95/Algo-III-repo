using namespace std;
#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>



class Ronda {
	public:
		Ronda();
		
		Ronda(vector<char> exploradoras, vector< vector<char> > amigas);
		
		vector<char> amigasDe(char e);
		
		vector<char> exploradoras();
		
		tuple<int, vector<char> > mejorOrden();

		void verRonda();

	private:

		vector< vector<char> > friends;
		vector<char> explorers;

		// El conjunto de amigas en la posicion i de friends corresponde a la exploradora en la posicion i en explorers.

		void completarAmigas (vector<char>& exploradoras, vector<vector<char> >& amigas);
		bool pertenece (vector<char> v , char e);
		bool perteneceConPos (vector<char> v , char e, int& posicion);
		tuple<int, int, vector<char> > calcularDistancias (vector<char> permutacion, vector<char> e, vector<vector<char> > a);
};


//**************************************************************************
//FUNCIONES PUBLICAS DE LA CLASE RONDA
//**************************************************************************

// Constructor de ronda vacia.
Ronda::Ronda(){}								//O(1)

//**************************************************************************

//ACLARAR QUE LA COMPLEJIDAD DE completarAmigas SE TIENE QUE TENER EN CUENTA PARA LA COMPLEJIDAD DE LA RONDA OPTIMA

// Constructor de ronda a partir de una lista de exploradoras y una lista con las amigas de cada una (cada exploradora se asocia a su grupo de amigas mediante el indice de las listas).
Ronda::Ronda(vector<char> exploradoras, vector< vector<char> > amigas) {
	explorers = exploradoras;					//O(e)
	friends = amigas; 							//O(a)
	completarAmigas(explorers, friends);
}

// e = cantidad de exploradoras
// a = cantidad de amistades

//**************************************************************************

// Imprime las exploradoras de la ronda, cada una con sus respectivas amigas.
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

//**************************************************************************

// Dada una exploradora perteneciente a la ronda, devuelve una lista que contiene a sus amigas.
vector<char> Ronda::amigasDe(char e) {
	int i = 0;								// O(1)
	while ( explorers[i] != e ) i++;			// O(1)
	return friends[i];						// O(1)
}

//**************************************************************************

// Devuelve una lista que contiene a todas las exploradoras de la ronda.
vector<char> Ronda::exploradoras() {
	return explorers;						// O(1)
}

//**************************************************************************

// Devuelve una tupla donde la segunda componente es la ronda optima, y la primera corresponde a la distancia maxima entre 2 amigas en dicha ronda.
tuple<int, vector<char> > Ronda::mejorOrden() {															//O(e³ e!)
	vector<char> exploradoras = explorers;																//O(e)
	sort( exploradoras.begin(), exploradoras.begin()+exploradoras.size() );									//O(e log(e))
	tuple<int, int, vector<char> > minimaSuma = calcularDistancias (exploradoras, explorers, friends);		//O(e³)
	while ( next_permutation(exploradoras.begin(), exploradoras.begin()+exploradoras.size()) ){			//O(e)
		tuple<int, int, vector<char> > dist = calcularDistancias(exploradoras, explorers, friends);			//O(e³)
		if ( get<0>(dist) < get<0>(minimaSuma) ) {														//O(1)
			minimaSuma = dist;																			//O(e)
		}
	}
	tuple<int, vector<char> > res;																			//O(1)
	get<0>(res) = get<1>(minimaSuma);																	//O(1)
	get<1>(res) = get<2>(minimaSuma);																	//O(e)
	return res;																								//O(1)
}

// e = cantidad de exploradoras

//**************************************************************************
// FUNCIONES AUXILIARES(PRIVADAS) DE LA CLASE RONDA
//**************************************************************************

// Funcion utilizada a la hora de crear una ronda no vacia. Como en el archivo de entrada las amistades pueden no estar escritas de manera simetrica, esta funcion verifica si falta escribir algo y lo agrega, para almacenarlo de esta forma.
void Ronda::completarAmigas (vector<char>& exploradoras, vector<vector<char> >& amigas) { //O(e³)
	int i = 0;																//O(1)
	while ( i < exploradoras.size() ) {										//O(e)
		int j = 0;															//O(1)
		while ( j < amigas[i].size() ) {										//O(e)
			int pos;															//O(1)
			if ( perteneceConPos(exploradoras, amigas[i][j], pos) ) {		//O(e)
				if ( !(pertenece(amigas[pos], exploradoras[i])) ) {			//O(e)
					amigas[pos].push_back(exploradoras[i]);				//O(1)
				}
			}else{
				exploradoras.push_back(amigas[i][j]);						//O(1)
				vector<char> nueva = {exploradoras[i]};					//O(1)
				amigas.push_back(nueva);									//O(1)
			}
			j++;															//O(1)
		}
		i++;																//O(1)
	}
}

// e = cantidad de exploradoras

//**************************************************************************

// Devuelve true si e aparece al menos una vez en v.
bool Ronda::pertenece (vector<char> v , char e) {	//O(n)
	int i = 0;										//O(1)
	bool noEncontrado = true;						//O(1)
	while (noEncontrado && i < v.size() ){			//O(n)
		noEncontrado = !(v[i] == e);				//O(1)
		i++;										//O(1)
	}
	return !noEncontrado;							//O(1)
}

// n = longitud del vector v

//**************************************************************************

// Igual que pertenece, pero ademas modifica posicion asignandole el indice del caracter encontrado (si es false no se debe tener en cuenta).
bool Ronda::perteneceConPos (vector<char> v , char e, int& posicion) { //O(n)
	int i = 0;											//O(1)
	bool noEncontrado = true;							//O(1)
	while (noEncontrado && i < v.size() ){				//O(n)
		noEncontrado = !(v[i] == e);					//O(1)
		i++;
	}
	posicion = i - 1;										//O(1)
	return !noEncontrado;								//O(1)
}

// n = longitud del vector v

//**************************************************************************

// Dada una posible permutacion de una ronda, calcula la suma de las distancias entre las exploradoras que son amigas, y la mayor  distancia entre 2 amigas en dicha ronda. Tambien devuelve la permutacion de entrada.
tuple<int, int, vector<char> > Ronda::calcularDistancias (vector<char> permutacion, vector<char> e, vector<vector<char> > a) { //O(e³)
	int i = 0;																//O(1)
	int suma = 0;															//O(1)
	int maxLograda = 0;													//O(1)
	while ( i < permutacion.size() ) {										//O(e)
		int indice;															//O(1)
		perteneceConPos(e, permutacion[i], indice);						//O(e)
		vector<char> amigas = a[indice];									//O(1)
		int j = 0;															//O(1)
		while ( j < amigas.size() ) {                    								//O(e)
			int pos;															//O(1)
			int distancia;													//O(1)
			perteneceConPos(permutacion, amigas[j], pos);					//O(e)
			if (pos - i > 0) {													//O(1)
				if (pos - i > permutacion.size() / 2) {							//O(1)
					distancia = permutacion.size() - (pos - i); 				//O(1)
				}else{														//O(1)
					distancia = pos - i;										//O(1)
				}
				if (maxLograda < distancia) maxLograda = distancia;		//O(1)
				suma = suma + distancia;									//O(1)
			}
			j++;															//O(1)
		} 
		i++;																//O(1)
	}
	tuple<int, int, vector<char> > res;										//O(1)
	get<0>(res) = suma;													//O(1)
	get<1>(res) = maxLograda;											//O(1)
	get<2>(res) = permutacion;											//O(e)
	return res;																//O(1)
}

// e = cantidad de exploradoras

//**************************************************************************
// OTRAS FUNCIONES
//**************************************************************************

// Imprime un vector<char>.
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

//**************************************************************************

// Imprime un vector< vector<char> >.
void imprimir2 (vector< vector<char> > v ) {
	cout << "[";
	for ( int j = 0; j < v.size() ; j++ ) {
		cout << "{";
		for ( int i = 0; i < v[j].size() ; i++ ) {
			if ( i == v[j].size() - 1 ) {
				cout << v[j][i];
			}else{
				cout << v[j][i] << ",";
			}
		}
		cout << "}";
		if ( j != v.size() - 1 ) {
			cout << ";";
		}
	}
	cout << "]" <<endl;
}

//**************************************************************************

int main() {

 	ifstream in("Tp1Ej3.in");
 	ofstream out;
   	out.open("resultados.out");
	

	while(in.good()) {
		vector<char> exploradoras;
		vector<vector<char> > amigas;
		string s,xs;	
		getline(in, s);

		for(int i = 0; i < s.size(); i++) {	 // Con esto reemplazo los ";" por " ".
			if (s[i] == ';') s[i] = ' ';
		}

		istringstream iss;
		iss.str(s);
		iss.clear();
		while(iss >> s >> xs) {
			exploradoras.push_back(s[0]);
			vector<char> v;
			for (int j = 0; j < xs.size(); j++) {
				v.push_back(xs[j]);
			}
			amigas.push_back(v);  
		}
		Ronda r(exploradoras, amigas);
		tuple<int, vector<char> > res = r.mejorOrden();
		out << get<0>(res) << " ";
		for (int i = 0; i < get<1>(res).size(); i++) {
			out << get<1>(res)[i];
		}
		out << endl;

	}
	out.close();

}


