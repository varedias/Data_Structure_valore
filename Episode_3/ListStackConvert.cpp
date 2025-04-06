#include <iostream>

struct Node{
    int data;
    Node* next;
    Node(int value):data(value),next(nullptr){}
};

struct StackNode{
    int value;
    StackNode* next;
    StackNode(int Key):value(Key),next(nullptr){}
};


class LinkStack{
    private:
    StackNode* m_top;

    public:
        LinkStack():m_top(nullptr){}


        bool empty()
        {
            return m_top==nullptr;
        }

        void push(int value)
        {
            StackNode* NewNode = new StackNode(value);
            NewNode->next = m_top;
            m_top = NewNode;
        }

        int pop()
        {
            if(empty())
            {
                return -1;
            }
            StackNode* temp = m_top;
            int value  = temp->value;
            m_top = m_top->next;
            delete temp;
            return value;
        }
};


Node* Reverse(Node* head)
{
    LinkStack stack;
    Node* current = head;
    while( current!= nullptr)
    {
        stack.push(current->data);
        current = current->next;
    }

    Node* NewHead =nullptr;
    Node* NewCurrent = nullptr;
    while(stack.empty()!=true)
    {
        int value = stack.pop();
        if(NewHead==nullptr)
        {
            NewHead=new Node(value);
            NewCurrent = NewHead;
        }
        else{
            NewCurrent->next = new Node(value);
            NewCurrent = NewCurrent->next;
        }
    }
    return NewHead;
}

void PrintList(Node* head)
{   
    Node* current = head;
    if(!head)return ;
    while(current!=nullptr)
    {
        std::cout<<current->data<<std::endl;
        current = current->next;
    }
}

int main()
{

     Node* head = new Node(1);
     head->next = new Node(2);
     head->next->next = new Node(3);
 
     std::cout << "Original: ";
     PrintList(head);
 
     Node* reversedHead = Reverse(head);
 
     std::cout << "after reverse: ";
     PrintList(reversedHead);
 
     return 0;
}

