#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> resumenDeRangos(const vector<int>& nums) {
    vector<string> resultado;

    //Declaramos una variable para el inicio del rango
    //Inicializamos con el primer número del vector que marcará el inicio del rango
    int inicio = nums[0];

    //Y empezamos a comprobar los números desde el segundo
    for (int i = 1; i <= nums.size(); i++) {
        // Verificamos si hemos llegado al final o si el número actual no es consecutivo (osea, se rompe el rango)
        if (i == nums.size() || nums[i] != nums[i - 1] + 1) {
            //Nota: Usamos i-1 porque estamos verificando el número actual nums[i], por lo que si nums[i] 
            //rompe la secuencia, entonces el rango válido termina justo antes, osea, en nums[i - 1].
            
            // Si el inicio y el final del rango son iguales, es un solo número
            if (inicio == nums[i - 1]) {
                resultado.push_back(to_string(inicio));
            } else {
                // Si no, es un rango que va desde 'inicio' hasta 'nums[i - 1]'
                resultado.push_back(to_string(inicio) + "->" + to_string(nums[i - 1]));
            }

            // Si no hemos llegado al final, actualizamos el nuevo inicio
            if (i < nums.size()) {
                inicio = nums[i];
            }
        }
    }

    return resultado;
}

int main() {
    vector<int> entrada = {0, 1, 2, 4, 5, 7};

    vector<string> resultado = resumenDeRangos(entrada);

    for (int i = 0; i < resultado.size(); i++) {
        if(i > 0) {
            cout << ", ";
        }
        cout << resultado[i];
    }

    return 0;
}
