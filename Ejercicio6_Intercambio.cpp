#include <iostream>
#include <vector>

using namespace std;

vector<string> intercambiarListas(vector<string> lista1, vector<string> lista2) {
    vector<string> resultado;
    int n = max(lista1.size(), lista2.size());

    //Recorremos hasta el tamaño máximo de las dos listas
    //Y en cada iteración añadimos un elemento de cada lista
    //Cuando se acabe una lista, pero la otra todavía tiene elementos, entonces ya solo uno de los ifs se cumple, y no hay problema de index fuera de rango
    //Haciendolo con el maximo de las dos y con un solo for, nos evitamos el tener que hacer un index para cada lista
    
    for(int i=0; i<n; i++) {
        if(i < lista1.size()) {
            resultado.push_back(lista1[i]);
        }
        if(i < lista2.size()) {
            resultado.push_back(lista2[i]);
        }
    }
    return resultado;
}

int main(){
    vector<int> lista1 = {1,2,3};
    vector<string> lista2 = {"a","b"};

    //Convertimos el vector de enteros a vector de strings
    //Usamos to_string para convertir cada entero a string
    //Y ya no hay problema de tipos
    
    vector<string> lista1s;
    for(int i=0; i<lista1.size(); i++) {
        lista1s.push_back(to_string(lista1[i]));
    }
    
    vector<string> resultado = intercambiarListas(lista1s, lista2);
    
    cout << "[";
    for(int i=0; i<resultado.size(); i++) {
        if(i > 0) cout << ", ";
        cout << resultado[i];
    }
    cout << "]" << endl;
    
    return 0;
}