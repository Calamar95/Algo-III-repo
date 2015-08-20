#include <iostream>
#include <utility>
#include <vector>
#include <set>
using namespace std;

vector<int> medianas(vector<int> a){
    vector<int> res;
    res.push_back(a[0]);
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
            res.push_back((maximo+minimo)/2);
        } else if (masGrandes.size() - masChicos.size() == 1){
            minimo = *masGrandes.begin();
            res.push_back(minimo);
        } else if (masGrandes.size() - masChicos.size() == -1){
            maximo = *masChicos.rbegin();            
            res.push_back(maximo);
        }
    }
    return res;
}
int main() {
    vector<int> a;
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(1);
    a.push_back(2);

    vector<int> b;
    b.push_back(2);
    b.push_back(7);
    b.push_back(2);
    b.push_back(8);
    b.push_back(4);
    b.push_back(9);
    b.push_back(1);
    b.push_back(6);
    b.push_back(5);


    vector<int> c;
    c.push_back(1);
    c.push_back(87);
    c.push_back(4);

    vector<int> d;
    d.push_back(4);
    d.push_back(0);
    d.push_back(32);
    d.push_back(6);
    d.push_back(8);
    d.push_back(10);

    vector<int> res;
    res = medianas(d);
    for(int i = 0; i<res.size(); i++){
        cout << res[i] << endl;
    }
    return 0;
}
