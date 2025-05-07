#include <iostream>

struct Node{
    int data;
    Node* lchild ,*rchild;
    Node():data(0),lchild(nullptr),rchild(nullptr){}
    Node(int value):data(value),lchild(nullptr),rchild(nullptr){}
};

int NumOfNode(Node* root)
{
    int count=0;
    if(root!=nullptr)
    {
        count++;
        count+=NumOfNode(root->lchild);
        count+=NumOfNode(root->rchild);
    }
    return count;
}

int NumOfLeaf(Node* root)
{
    if(root!=nullptr)
    {
        if(root->lchild==nullptr&&root->rchild==nullptr)
        {
            return 1;
        }
    
    return NumOfLeaf(root->lchild)+NumOfLeaf(root->rchild);
    }
    return 0;

}


void ThroughTree(Node* root, int Mode) {
    if (root != nullptr) {
        if (Mode == 1) { 
            std::cout << root->data << std::endl;
            ThroughTree(root->lchild, Mode);
            ThroughTree(root->rchild, Mode);
        } else if (Mode == 2) { 
            ThroughTree(root->lchild, Mode);
            std::cout << root->data << std::endl;
            ThroughTree(root->rchild, Mode);
        } else if (Mode == 3) { 
            ThroughTree(root->lchild, Mode);
            ThroughTree(root->rchild, Mode);
            std::cout << root->data << std::endl;
        }
    }
}


int depth(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftDepth = depth(root->lchild);
    int rightDepth = depth(root->rchild);
    return std::max(leftDepth, rightDepth) + 1;
}

int depthByValue(Node* root, int value, int currentDepth = 0) {
    if (root == nullptr) {
        return 0;
    }
    if (root->data == value) {
        return currentDepth + 1;
    }
    int leftResult = depthByValue(root->lchild, value, currentDepth + 1);
    if (leftResult != 0) {
        return leftResult;
    }
    return depthByValue(root->rchild, value, currentDepth + 1);
}


int main()
{
    Node* root = new Node(10);
    root->lchild = new Node(3);
    root->lchild->lchild=new Node(2);
    root->lchild->rchild=new Node(4);
    root->lchild->rchild->rchild=new Node(9);
    root->lchild->rchild->rchild->lchild=new Node(8);
    root->lchild->rchild->rchild->rchild=new Node(9);
    root->rchild = new Node(18);
    root->rchild->lchild=new Node(13);
    root->rchild->rchild=new Node(21);
    std::cout << "the Number of node: " << NumOfNode(root) << std::endl;
    std::cout << "the Number  of leaf: " << NumOfLeaf(root) << std::endl;
    std::cout << "the depth of the tree"<<depth(root)<<std::endl;
    std::cout << " 2 is in the "<<depthByValue(root,2,0)<<std::endl;
    std::cout<<"through tree"<<std::endl;
    ThroughTree(root,1);


}