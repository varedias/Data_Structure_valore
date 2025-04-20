// #include <iostream>

// struct Dtree {
//     int data;
//     Dtree* left;
//     Dtree* right;
//     Dtree() : data(0), left(nullptr), right(nullptr) {}
//     Dtree(int val) : data(val), left(nullptr), right(nullptr) {}
// };

// void Change(Dtree*& root) {
//     if (root == nullptr) {
//         root = new Dtree;
//         return;
//     }

//     Dtree* Temp = root->left;
//     root->left = root->right;
//     root->right = Temp;
// }


// void printTree(Dtree* root) {
//     if (root == nullptr) {
//         std::cout << "nullptr ";
//         return;
//     }
//     std::cout << root->data << " ";
//     printTree(root->left);
//     printTree(root->right);
// }


// void testChange() {

//     Dtree* root = new Dtree(1);
//     root->left = new Dtree(2);
//     root->right = new Dtree(3);
//     root->left->left = new Dtree(4);
//     root->left->right = new Dtree(5);
//     root->right->left = new Dtree(6);
//     root->right->right = new Dtree(7);

//     std::cout << "before change: ";
//     printTree(root);
//     std::cout << std::endl;

   
//     Change(root);

//     std::cout << "after change: ";
//     printTree(root);
//     std::cout << std::endl;


// }

// int main() {
//     testChange();
//     return 0;
// }
