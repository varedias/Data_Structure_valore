#include <iostream>

struct Node{
    int data;
    Node* next;
    Node(int value):data(value),next(nullptr){}
};

class Stack
{
    private:
    Node** stack;
    int m_top;
    int m_capacity;
    public:
    Stack(){}
    Stack(int size)
    {
        m_capacity = size;
        stack = new Node*[size];
        m_top=-1;
    }
    bool empty()
    {
        return m_top==-1;
    }
    bool full()
    {
        return m_top==m_capacity-1;
    }

    void push(Node* node)
    {
        if(full())return ;
        stack[++m_top]=node;
    }

    Node* pop()
    {
        if(empty())return nullptr ;
        return stack[m_top--];        
    }
};

Node* reverList(Node* head,int size)
{
    if(head==nullptr||head->next==nullptr)return head;
    Stack stack(size);
    Node* current = head;
    while(current)
    {
        stack.push(current);
        current=current->next;
    }

    head = stack.pop();
    current = head;
    while(stack.empty()!=true)
    {
        current->next = stack.pop();
        current  = current->next;
    }
    current->next = nullptr;
    return head;
}


void printerStack(Node* head)
{
        Node* current  = head;
        while(current!=nullptr)
        {
            std::cout<<current->data<<std::endl;
            current  =current->next;
        }
}





int main()
{
       
       Node* head = new Node(1);
       head->next = new Node(2);
       head->next->next = new Node(3);
       head->next->next->next = new Node(4);
       head->next->next->next->next = new Node(5);

       int size = 5;
   
       std::cout << "original: ";
       printerStack(head);
   
       head = reverList(head,size);
   
       std::cout << "after reversing: ";
       printerStack(head);
   
       return 0;
}