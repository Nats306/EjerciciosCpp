#include <iostream>
#include <vector>
#include <sstream> // Para dividir el string en palabras

using namespace std;

string rotarPalabras(string texto, int k) {
    //Dividimos el texto en palabras individuales
    vector<string> palabras;
    string palabra;
    stringstream ss(texto); // Creamos un flujo de string
    
    // Extraemos palabra por palabra usando el espacio como separador
    while (ss >> palabra) {
        palabras.push_back(palabra);
    }
    
    // Si k es 0, retornar el texto original
    if (k == 0) {
        return texto;
    }
    
    // Ajustamos k por si es mayor que el número de palabras
    // Esto se hace porque rotar k veces es lo mismo que rotar k % palabras.size() veces
    //Por ejemplo, si tenemos 4 palabras y k = 5, es lo mismo que rotar 1 vez
    //Esto se hace para evitar rotaciones innecesarias
    k = k % palabras.size();
    
    vector<string> rotadas;
    
    //Son las últimas palabras que se van a mover al inicio
    for (int i = palabras.size() - k; i < palabras.size(); i++) {
        rotadas.push_back(palabras[i]);
    }
    
    //Añadimos el resto de las palabras que no se mueven
    for (int i = 0; i < palabras.size() - k; i++) {
        rotadas.push_back(palabras[i]);
    }
    
    
    string resultado;
    for (int i = 0; i < rotadas.size(); i++) {
        if (i != 0) {
            resultado += " ";
        }
        resultado += rotadas[i];
    }
    
    return resultado;
}

int main() {
    string texto = "uno dos tres cuatro";
    int k = 1;
    
    string resultado = rotarPalabras(texto, k);
    
    cout << resultado << endl;
    
    return 0;
}