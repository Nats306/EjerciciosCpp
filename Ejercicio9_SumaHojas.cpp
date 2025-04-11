#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int sumaHojas(TreeNode* root){
    if(!root) return 0; //Árbol vacío
    if(!root->left && !root->right) return root->val; //La raiz no tiene hijos, es hoja

    //LLamada recursiva a la izquierda y derecha
    return sumaHojas(root->left) + sumaHojas(root->right);

}

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(10);

    cout << "La suma de las hojas es: " << sumaHojas(root) << endl;

    return 0;
}