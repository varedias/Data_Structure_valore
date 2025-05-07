#include <iostream>
#include <vector>

struct Node {
    char data;
    Node* lchild;
    Node* rchild;
    
    Node(char value = '\0') : data(value), lchild(nullptr), rchild(nullptr) {}
};

Node* Convert(const std::vector<char>& original, size_t i = 0) {
    if (i >= original.size() || original[i] == 0) {
        return nullptr;
    }
    
    Node* root = new Node(original[i]);
    root->lchild = Convert(original, 2 * i + 1);
    root->rchild = Convert(original, 2 * i + 2);
    return root;
}

void TraverseTree(Node* root, int mode) {
    if (root == nullptr) return;
    
    switch (mode) {
        case 1: 
            std::cout << root->data << " ";
            TraverseTree(root->lchild, mode);
            TraverseTree(root->rchild, mode);
            break;
        case 2: 
            TraverseTree(root->lchild, mode);
            std::cout << root->data << " ";
            TraverseTree(root->rchild, mode);
            break;
        case 3: 
            TraverseTree(root->lchild, mode);
            TraverseTree(root->rchild, mode);
            std::cout << root->data << " ";
            break;
        default:
            std::cerr << "Invalid traversal mode!" << std::endl;
    }
}



int main() {
    std::vector<char> original = {'A','B','C','D',0,'E','F',0,'G',0,0,'H',0};
    
    Node* root = Convert(original);
    
    std::cout << "前序遍历结果: ";
    TraverseTree(root, 1);
    std::cout << std::endl;
    
    std::cout << "中序遍历结果: ";
    TraverseTree(root, 2);
    std::cout << std::endl;
    
    std::cout << "后序遍历结果: ";
    TraverseTree(root, 3);
    std::cout << std::endl;
    

    
    return 0;
}