// #include <iostream>
// #include <algorithm>
// #define SIZE 50

// struct Node {
//     int value;
//     Node* left, *right;
//     Node(int val) : value(val), left(nullptr), right(nullptr) {}
// };


// Node* insertNode(Node* root, int value) {
//     if (root == nullptr) {
//         return new Node(value);
//     }
    
//     if (value < root->value) {
//         root->left = insertNode(root->left, value);
//     }
//     else if (value > root->value) {
//         root->right = insertNode(root->right, value);
//     }
//     else {
//         std::cout << "error " << value << "exist" << std::endl;
//     }
    
//     return root;
// }


// void inorderTraversal(Node* root) {
//     if (root != nullptr) {
//         inorderTraversal(root->left);
//         std::cout << root->value << " ";
//         inorderTraversal(root->right);
//     }
// }




// int main() {
//     Node* root = nullptr;
    
//     int testValues[] = {50, 30, 70, 20, 40, 60, 80};
//     for (int value : testValues) {
//         root = insertNode(root, value);
//     }
    
//     std::cout << "the result of inorderTraversal: ";
//     inorderTraversal(root);
//     std::cout << std::endl;
   
    

//     return 0;
// }



