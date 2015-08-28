#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <sstream>
#include <fstream>
using namespace std;

vector<int> medianas(vector<int> a){
    vector<int> res(a.size(),0);
    res[0] = a[0];
    multiset<int> masGrandes;
    multiset<int> masChicos;
    int minimo;
    int maximo;
    masGrandes.insert(a[0]);
    for (int i = 1; i < a.size(); i++){
        if (a[i] >= res[i-1]){
            masGrandes.insert(a[i]);
        } else {
            masChicos.insert(a[i]);
        }
        if (masGrandes.size() - masChicos.size() == 2){
            minimo = *masGrandes.begin();
            masGrandes.erase(minimo);
            masChicos.insert(minimo);
        } else if (masGrandes.size() - masChicos.size() == -2){
            maximo = *masChicos.rbegin();
            masChicos.erase(maximo);
            masGrandes.insert(maximo);
        }
        if (masGrandes.size() == masChicos.size()){
            minimo = *masGrandes.begin();
            maximo = *masChicos.rbegin();
            res[i] = (maximo+minimo)/2;
        } else if (masGrandes.size() - masChicos.size() == 1){
            minimo = *masGrandes.begin();
            res[i] = minimo;
        } else if (masGrandes.size() - masChicos.size() == -1){
            maximo = *masChicos.rbegin();            
            res[i] = maximo;
        }
    }
    return res;
}
int main() {
    
    ofstream out;
    out.open("resultado.out");
    ifstream in("Tp1Ej2.in");
    while (in.good()){
        vector<int> vec;
        string st;
        getline(in, st);
        istringstream iss;
        iss.str(st);
        iss.clear();
        int a;
        while(iss>>a){
            vec.push_back(a);
        }
        vector<int> res = medianas(vec);
        for(int i = 0; i<res.size(); i++){
            out << res[i] << " ";
        }
        out << endl;
    }
    out.close();

    return 0;
}
