#include <iostream>
using namespace std;

struct TreeNode {
    int valor;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : valor(x), left(nullptr), right(nullptr) {}
};

//Funcion recursiva
bool isMirror(TreeNode* left, TreeNode* right) {
    //Caso base: si ambos nodos son nulos, son espejo
    if (left == nullptr && right == nullptr) return true;

    //Si uno es nulo y el otro no, no son espejo
    if (left == nullptr || right == nullptr) return false;

    //Comparamos los valores de los nodos y llamamos recursivamente a la izquierda y derecha
    //Verificar: 
    //1) Valores iguales
    //2) Subárbol izquierdo de left con subárbol derecho de right
    //3) Subárbol derecho de left con subárbol izquierdo de right
    return (left->valor == right->valor) && isMirror(left->right, right->left) && isMirror(left->left, right->right);
}

bool isSymmetric(TreeNode* root) {
    //Si el árbol está vacío, es simétrico
    if (root == nullptr) return true;

    //Llamamos a la función recursiva para verificar si es espejo
    return isMirror(root->left, root->right);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    cout << (isSymmetric(root) ? "El árbol es simétrico" : "El árbol no es simétrico") << endl;

    return 0;
}