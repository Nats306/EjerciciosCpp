#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<string> eliminarDuplicados(vector<string>& palabras) {
    //Hacemos un mapa para guardar la última posición de cada palabra
    //La clave es la palabra y el valor es su última posición en el vector
    unordered_map<string, int> ultimaPosicion;
    
    for (int i = 0; i < palabras.size(); ++i) {
        ultimaPosicion[palabras[i]] = i;
        //Actualizamos el mapa con la posición actual para cada palabra
        //Si la palabra ya estaba, se actualiza su posición
        //Si no estaba, se añade con la posición actual
    }
    
    vector<string> resultado;
    for (int i = 0; i < palabras.size(); ++i) {
        if (ultimaPosicion[palabras[i]] == i) {
            resultado.push_back(palabras[i]);
        }
    }
    
    return resultado;
}

int main() {
    vector<string> input = {"apple", "banana", "apple", "orange", "banana"};
    vector<string> output = eliminarDuplicados(input);
    
    // Mostrar el resultado
    cout << "[";
    for (int i = 0; i < output.size(); ++i) {
        if (i > 0) {  // Si no es el primer elemento
            cout << ", ";
        }
        cout << output[i];
    }
    cout << "]" << endl;
    
    return 0;
}