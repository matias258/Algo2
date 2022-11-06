#include <vector>
#include "algobot.h"
#include <map>
using namespace std;

vector<int> interseccion(vector<int> a, vector<int> b) {
    set<int> set_a;
    for (int i = 0; i < a.size(); i++) {
        set_a.insert(a[i]);
    }
    vector<int> res;
    for (int i = 0; i < b.size(); i++) {
        if (set_a.count(b[i]) == 1) {
            res.push_back(b[i]);
        }
    }
    return res;
}

int posaparicion(vector<pair<char, char>> v, char l){

    int res = -1;

    for(int i = 0; i<v.size(); i++){
      if((v[i]).second == l) {
          res = i;
      }
    }

    return res;
}

// Ejercicio 1


/*
vector<int> quitar_repetidos(vector<int> s) {

    vector<int> v;

    for (int i = 0; i < s.size(); i++ ){
        bool norepe = true;
        for(int j = 0; j < s.size() && j != i; j++){
            if (s[j] == s[i]){
                norepe = norepe && false;
            }
            else{
                norepe = norepe && true;
            }
        }
        if (norepe == true){
            v.push_back(s[i]);
        }
    }
    return v;
}

*/

vector<int> quitar_repetidos(vector<int> s) {


    vector<int> v;
    set<int> set_s;

    for (int i = 0; i < s.size(); i++) {
        set_s.insert(s[i]);
    }

    for (int x : set_s){

        v.push_back(x);

    }

    return v;

}



// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {

    vector<int> v;
    set<int> set_s;

    for (int i = 0; i < s.size(); i++) {
        set_s.insert(s[i]);
    }

    for (int x : set_s){

        v.push_back(x);

    }

    return v;
}

// Ejercicio 3

/*
bool mismos_elementos(vector<int> a, vector<int> b) {

    vector<int> inters = interseccion(a,b);
    set<int> set_inters;

    for (int i = 0; i < inters.size(); i++) {
        set_inters.insert(inters[i]);
    }

    set<int> set_a;

    for (int i = 0; i < a.size(); i++) {
        set_a.insert(a[i]);
    }

    set<int> set_b;

    for (int i = 0; i < b.size(); i++) {
        set_b.insert(b[i]);
    }

    bool res = (set_a.size() == set_b.size()) && (set_b.size() == set_inters.size());

    return res;
}

 */


// Ejercicio 4

/*Verifica si las dos secuencias tienen los mismos elementos, sin importar
el orden o la cantidad de apariciones */

bool mismos_elementos(vector<int> a, vector<int> b) {

    vector<int> inters = interseccion(a, b);
    int mismosEle = 0;
    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < b.size(); j++){
            if (a[i] == b[j]){
                mismosEle = mismosEle + 1;
            }
            else {
                mismosEle = mismosEle;
            }
        }
    }
    if (mismosEle == a.size()){
        return true;
    }
    else {
        return false;
    }

}

bool mismos_elementos_v2(vector<int> a, vector<int> b) {

    set<int> set_a;
    set<int> set_b;

    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < b.size(); j++){
            if (a[i] == b[j]){
                set_a.insert(a[i]);
            }
        }
    }
    if (set_a.size() == quitar_repetidos(a).size()){
        return true;
    }
    else{
        return false;
    }

}


// Ejercicio 5

int cantidades_apariciones(int x, vector<int> s){
    int contador = 0;
    for (int i = 0; i < s.size(); i++){
        if (x == s[i]) {
            contador = contador + 1;
        }
        else{
            contador = contador;
        }
    }
    return contador;
}

map<int, int> contar_apariciones(vector<int> s) {
    map<int, int> numeros_repes;

    for (int i = 0; i < s.size(); i++) {
        numeros_repes[s[i]] = cantidades_apariciones(s[i], s);
    }
    return numeros_repes;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {

    map<int, int> ap = contar_apariciones(s);
    vector<int> v;

    for(int i = 0; i<s.size();i++){
        if (ap[s[i]] == 1) {
            v.push_back(s[i]);
        }
    }

    return v;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {

    set<int> inter;

    for (int x : a){
        if (b.count(x)==1){
            inter.insert(x);
        }
    }

    return inter;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {

    map<int, set<int>> m;

    for(int i=0; i<s.size(); i++){
    (m[(s[i]%10)]).insert(s[i]);

    }

    return m;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {

    vector<char> res;
    map<char, char> m;

    for(int i = 0; i<tr.size();i++){
        m[(tr[i]).first] = (tr[i]).second;
    }

    for(int i = 0; i<str.size(); i++){
        if (m.count(str[i]) ){
            res.push_back(m[str[i]]);
        } else {
            res.push_back(str[i]);
        }
    }

    return res;
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {

    return true;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
  return map<set<LU>, Mail>();
}
