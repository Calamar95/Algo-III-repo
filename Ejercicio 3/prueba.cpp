using namespace std;
#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>
#include <sys/time.h>
#include <sstream>
#include <fstream>


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

int main(){
	
	vector<char> v1 = {'x', 'a' , 'g', 'c'};
	sort(v1.begin(), v1.begin()+v1.size());
	while (next_permutation(v1.begin(), v1.begin()+v1.size()) ){
		imprimir(v1);
	}
	
	imprimir(v1);



}