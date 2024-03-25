#include <iostream>
#include <stack>

// Szablon dla węzła drzewa binarnego i drzewa BST.
template <typename T>
struct BSTNode {
// the default access mode and default inheritance mode are public
    T value;
    BSTNode *left, *right;
    //BSTNode *parent;   // używane w pewnych zastosowaniach
    // kostruktor domyślny
    BSTNode() : value(T()), left(nullptr), right(nullptr) {}
    // konstruktor zwykły
    BSTNode(const T& item) : value(item), left(nullptr), right(nullptr) {}
    ~BSTNode() {} // destruktor
};
template <typename T>
int calc_leaves(BSTNode<T>* node){
if(node ==nullptr){
return 0;
}
if(node->right ==nullptr&& node->left == nullptr){
return 1;
}
return calc_leaves(node->right)+calc_leaves(node->left);
}

template <typename T>
int leaves_iteracyjnie(BSTNode<T>* node){
if(node == nullptr){
	return 0;
	}
std::stack<BSTNode<T>*> stos;
stos.push(node);
int counter = 0;
BSTNode<T>* aktualny_wezel;
while(!stos.empty()){
aktualny_wezel = stos.top();
stos.pop();
if(aktualny_wezel->left == nullptr && aktualny_wezel->right ==nullptr){
	counter +=1;
	}
if(aktualny_wezel->left != nullptr){
	stos.push(aktualny_wezel->left);
	}
if(aktualny_wezel->right != nullptr){
	stos.push(aktualny_wezel->right);
	}
}
return counter;
}	

int main() {
    // Example usage:
    BSTNode<int>* root = new BSTNode<int>(10);
    root->left = new BSTNode<int>(5);
    root->right = new BSTNode<int>(15);
    root->left->left = new BSTNode<int>(3);
    root->left->right = new BSTNode<int>(7);

    int leaves = calc_leaves(root);
    std::cout << "Number of leaves 1st method: " << leaves << std::endl;
    int leaves2 = leaves_iteracyjnie(root);
    std::cout <<"Number of leaves 2nd method: "<<leaves2<<std::endl;

    // Don't forget to free the allocated memory
    // (this is a simplified example; in practice, you would use smart pointers or implement proper memory management)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
