#include <iostream>
#include <vector>
using namespace std;

int conectar(vector<int> v , int cable){

int res = 1;
int end = 0;
int start = 0;
int aux = 0;

while(cable>0 && v[end] != v.back()){
	aux = cable;
	if (end != 0){
		cable = cable -(v[end+1] - v[end]);
	}else{
		cable = cable - v[end+1];
	}
	end++;
	if (cable >= 0){
		res++;
	}
	
}

if (cable<0){
	cable = aux;
}
cout << cable << endl;

//cout<< start << endl;
//cout<< end << endl;
//cout<< cable << endl;
//cout<< res << endl;

while (v[end] != v.back()){
	int conectadas = res - 1; //OJO
	cable = cable + (v[start+1]-v[start]);
	//cout << cable << endl;
	start++;
	while (cable >= 0 && v[end]!= v.back()){
		cable = cable - (v[end+1]- v[end]);
		end++;
		if (cable>= 0){
			conectadas++;
		}
	}
	if (conectadas>res){
		res = conectadas;
	}
}
return res;
}

int main(){

	vector<int> a;

/*	a.push_back(0);
	a.push_back(8);
	a.push_back(14);
	a.push_back(20);
	a.push_back(40);
	a.push_back(45);
	a.push_back(54);
	a.push_back(60);
	a.push_back(67);
	a.push_back(74);
	a.push_back(89);
	a.push_back(99);

*/

/*
	a.push_back(0);
	a.push_back(35);
	a.push_back(87);
	a.push_back(141);
	a.push_back(163);
	a.push_back(183);
	a.push_back(252);
	a.push_back(288);
	a.push_back(314);
	a.push_back(356);
	a.push_back(387);
*/

	a.push_back(0);
	a.push_back(6);
	a.push_back(8);
	a.push_back(16);
	a.push_back(19);
	a.push_back(28);
	a.push_back(32);
	a.push_back(37);
	a.push_back(45);
	a.push_back(52);
	a.push_back(60);
	a.push_back(69);
	a.push_back(78);
	a.push_back(82);
	

	int b = conectar(a,100);
	
	cout << b << endl;
	return 0;
}