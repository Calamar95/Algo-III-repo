#include <iostream>
#include <vector>
#include <string>
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

if (res == 1){
	res = 0;
}

if (cable<0){
	cable = aux;
}

while (v[end] != v.back()){
	
	int conectadas;
	if (res==0) {
		conectadas = 0;
		start++;
		end++;
	}else{
		conectadas = res - 1;
		cable = cable + (v[start+1]-v[start]);
		start++;
	}

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

if (res == 1){
	res = 2;
}
return res;
}


int main(){







































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


/*

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