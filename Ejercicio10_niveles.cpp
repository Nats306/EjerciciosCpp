#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


vector<vector<int>> niveles(TreeNode* root) {
    // Vector que almacenará el resultado final (lista de niveles)
    vector<vector<int>> resultado;
    
    if (!root) return resultado;
    
    queue<TreeNode*> q;
    
    q.push(root);
    
    while (!q.empty()) {
        // Obtenemos el número de nodos en el nivel actual
        int tamNivel = q.size();
        
        // Vector para almacenar los valores del nivel actual
        vector<int> nivelActual;
        
        // Procesamos todos los nodos del nivel actual
        for (int i = 0; i < tamNivel; ++i) {
            // Obtenemos el nodo frontal de la cola
            TreeNode* node = q.front();
            // Lo removemos de la cola (FIFO)
            q.pop();
            
            // Añadimos su valor al nivel actual
            nivelActual.push_back(node->val);
            
            // Si existe hijo izquierdo, lo añadimos a la cola para el siguiente nivel
            if (node->left) q.push(node->left);
            
            // Si existe hijo derecho, lo añadimos a la cola para el siguiente nivel
            if (node->right) q.push(node->right);
        }
        
        // Añadimos los valores del nivel procesado al resultado final
        resultado.push_back(nivelActual);
    }
    
    return resultado;
}


int main() {
    
    TreeNode* root = new TreeNode(1);
    
    root->left = new TreeNode(2);    // Hijo izquierdo: 2
    root->right = new TreeNode(3);   // Hijo derecho: 3
    
    root->left->left = new TreeNode(4);   
    root->left->right = new TreeNode(5);  
    
    // Obtenemos los niveles del árbol
    vector<vector<int>> levels = niveles(root);
    
    // Mostramos el resultado en el formato solicitado
    cout << "[";
    for (int i = 0; i < levels.size(); ++i) {
        if(i > 0) cout << ", ";
        cout << "[";
        for (int j = 0; j < levels[i].size(); ++j) {
            if(j > 0) cout << ", ";  // Añadimos comas entre elementos
            cout << levels[i][j];
            
        }
        cout << "]";
    }
    cout << "]" << endl;
    
    return 0; 
}