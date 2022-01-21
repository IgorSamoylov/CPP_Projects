

#include "C++ TREE TRAVERSAL.h"
template <class T>
void tree_traversal(Node<T>* node) {
    if (node->left != nullptr) tree_traversal(node->left);
    std::cout << node->val << std::endl;
    if (node->right != nullptr) tree_traversal(node->right);
}

int main()
{
    
    Tree<int>* myTree = new Tree<int>();

    std::mt19937_64 rand;
    rand.seed(std::time(nullptr));
    
    for (int i = 0; i < 100; i++) {
        int n = rand();
        myTree->add(n);
    }
    tree_traversal(myTree->first);

}



