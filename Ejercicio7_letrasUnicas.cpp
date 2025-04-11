#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;


bool tieneLetrasUnicas(string palabra) {
    unordered_set<char> letrasVistas; // Almacena las letras que ya hemos visto
    //Usamos un set porque permite verificar si una letra ya existe en O(1) tiempo promedio

    
    for (char letra : palabra) { // Recorremos cada letra de la palabra
        // Si la letra ya está en el conjunto, está repetida
        if (letrasVistas.count(letra) > 0) {
            return false;
        }
        // Si no está repetida, la añadimos al conjunto
        letrasVistas.insert(letra);
    }
    
    // Si terminamos el bucle sin encontrar repetidas, todas son únicas
    return true;
}


vector<string> filtrarPalabrasUnicas(vector<string> palabras) {
    vector<string> resultado;
    
    for (string palabra : palabras) { // Recorremos cada palabra
        if (tieneLetrasUnicas(palabra)) { // Verificamos si tiene letras únicas
            resultado.push_back(palabra); // Si cumple, la añadimos al resultado
        }
    }
    
    return resultado;
}

int main() {
    vector<string> palabras = {"hola", "casa", "perro", "luz"};
    
    vector<string> palabrasUnicas = filtrarPalabrasUnicas(palabras);
    
    // Mostramos el resultado
    cout << "[";
    for (size_t i = 0; i < palabrasUnicas.size(); ++i) {
        if(i > 0) cout << ", "; 
        cout << "\"" << palabrasUnicas[i] << "\"";
        
    }
    cout << "]" << endl;
    
    return 0;
}