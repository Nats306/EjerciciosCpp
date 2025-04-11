#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>


using namespace std;

//El metodo recibe un vector de palabras y devuelve grupos de anagramas
vector<vector<string>> agruparAnagramas(vector<string>& palabras) { //Se recibe un vector de palabras y el & indica que estamos trabajando sobre el vector ORIGINAL
    //Vamos a utilizar un mapa(diccionario) donde:
    // - La CLAVE es la palabra ordenada (anagrama)
    // - El VALOR es un vector de palabras que son anagramas entre sí

    //Emeplo:
    //Para "tea" y "eat", la clave es "aet" y el valor es un vector que contiene "tea" y "eat"
    //Para "tan" y "nat", la clave es "ant" y el valor es un vector que contiene "tan" y "nat"
    unordered_map<string, vector<string>> grupos;

    //Acá recorremos cada palabra del vector de palabras
    for (string palabra : palabras) {
        //Primero creamos una copia de la palabra para ordenarla
        string clave = palabra;
        //Ordenamos la palabra alfabeticamente para obtener la clave del anagrama
        //Para esto se usa sort() que necesita el inicio y el fin del string
        sort(clave.begin(), clave.end());
        //Ahora, añadimos la palabra original a su grupo correspondiente
        //grupos[clave] accede al vector asociaodo a esa clave
        //Si no existe, se crea un nuevo vector automáticamente
        //push_back() añade la palabra al final vector
        grupos[clave].push_back(palabra);

        /*
         * Ejemplo con "tea":
         * 1. clave = "tea" ordenado → "aet"
         * 2. grupos["aet"] → como no existe, crea un vector vacío
         * 3. Añade "tea" → grupos["aet"] = ["tea"]
         * 
         * Luego con "eat":
         * 1. clave = "eat" ordenado → "aet"
         * 2. grupos["aet"] ya existe (tiene ["tea"])
         * 3. Añade "eat" → grupos["aet"] = ["tea", "eat"]
         */
    }

    //Vamos a convertir el mapa en un vecstor de vectores

    vector<vector<string>> resultado;
    //// for (auto par : grupos) recorre cada par clave-valor del mapa
    for (auto par : grupos) {
         /*par es un par donde:
           - par.first es la clave (string ordenado)
           - par.second es el valor (vector de palabras)
           
           Solo nos interesan el vector de palabras (par.second)*/
        resultado.push_back(par.second);
    }

    return resultado;
}

int main(){
    vector<string> palabras = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> grupos = agruparAnagramas(palabras);

    //Imprimir los grupos de anagramas
    for (auto grupo : grupos) {
        for (string palabra : grupo) {
            cout << palabra << " ";
        }
        cout << endl;
    }

    return 0;
}