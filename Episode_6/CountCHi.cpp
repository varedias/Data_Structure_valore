#include <iostream>

int counter = 0;

struct Dtree {
    int data;
    Dtree* left;
    Dtree* right;
    Dtree() : data(0), left(nullptr), right(nullptr) {}
    Dtree(int val) : data(val), left(nullptr), right(nullptr) {}
};

void CountCHi(Dtree* root) {
    if (root != nullptr) {
        counter++;
        CountCHi(root->left);
        CountCHi(root->right);
    }
}


void printTree(Dtree* root) {
    if (root == nullptr) {
        std::cout << "nullptr ";
        return;
    }
    std::cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

void testCountCHi() {

    Dtree* root = new Dtree(1);
    root->left = new Dtree(2);
    root->right = new Dtree(3);
    root->left->left = new Dtree(4);
    root->left->right = new Dtree(5);
    root->right->left = new Dtree(6);
    root->right->right = new Dtree(7);

    std::cout << "original: ";
    printTree(root);
    std::cout << std::endl;

    CountCHi(root);

    std::cout << "number of node: " << counter-1 << std::endl;

 
}

int main() {
    testCountCHi();
    return 0;
}
