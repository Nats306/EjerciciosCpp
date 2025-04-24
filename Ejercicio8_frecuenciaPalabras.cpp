#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <vector>

using namespace std;

string limpiarTexto(const string& texto) { //solo tenemos que considerar las letras (que son las palabras) y los espacios para separar las palabras
    string resultado; 
    for (char c : texto) {
        if (isalpha(c) || isspace(c)) { // Solo letras y espacios, ignoramos otros caracteres (., !, etc.)
            resultado += tolower(c); // Convertir a minúscula para por ejemplo, "Hola" y "hola" sean la misma palabra
        }
    }
    return resultado;
}

vector<pair<string, int>> frecuenciaPalabras(string texto) {
    //Primero limpiamos el texto para eliminar caracteres no deseados y convertir a minúsculas
    texto = limpiarTexto(texto);

   //Usamos un mapa para contar la frecuencia de cada palabra
    //El mapa tiene como clave la palabra y como valor la frecuencia
    map<string, int> contador;
    string palabra;
    for (char c : texto) {
        if (isspace(c)) {
            if (!palabra.empty()) {
                contador[palabra]++;
                palabra.clear();
            }
        } else {
            palabra += c;
        }
    }       
    if (!palabra.empty()) { // Para la última palabra
        contador[palabra]++;
    }

    // Convertir el mapa a un vector de pares para facilitar el acceso a los datos y poderlos imprimir con facilidad
    vector<pair<string, int>> resultado(contador.begin(), contador.end());

    return resultado;
}

int main() {
    string texto = "Hola mundo. Hola clase, hola estudiantes!";

    vector<pair<string, int>> frecuencias = frecuenciaPalabras(texto);
    
    cout << "[";
    for (int i=0; i < frecuencias.size(); i++) {
        if(i>0){
            cout << ", ";
        }
        cout << "(" <<  frecuencias[i].first << ": " << frecuencias[i].second << ")";
    }
    cout << "]";
    return 0;
}