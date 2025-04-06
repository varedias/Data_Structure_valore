#include <iostream>


struct Node{
    int value;
    Node * next;
    Node(int Key):value(Key),next(nullptr){}
};


void InsertNode(Node *&tail,int value)
{
    Node* NewNode = new Node(value);
    if(!tail)
    {
        tail = NewNode;
        tail->next  =tail;
    }else{
        NewNode->next = tail->next;//新节点放在最后面
        tail->next = NewNode;
        tail =NewNode;
    }
}


void PrintList(Node* tail)
{
    if(!tail)return ;
    Node* Current =tail->next;
   do
    {
        std::cout<<Current->value<<std::endl;
        Current = Current->next;
    }while(Current!=tail->next);
}

void InitList(Node * tail)
{
    if(!tail)return ;
    Node* Current = tail->next;
    do{
        Current->value = 0;
        Current = Current->next;
    }
    while(Current!=tail->next);
}


int GetKeyWithPoi(Node* tail,int Position)
{
    if(!tail)return -1;
    Node* Current = tail->next;
    int counter =0;
    do{
        if(counter==Position) return Current->value;
        else{
            counter++;
            Current = Current->next;
        }
    }while(Current!=tail->next);
    return -1;
}

void DeleWithPos(Node* tail,int Position)
{
    if(!tail)return;
    Node* Current = tail->next,*temp;
    int counter =0;
    do{
        if(counter+1==Position) 
        {
            temp=Current->next;
            Current->next = temp->next;
            if(temp==tail)tail = Current;
            delete temp;
            break;
        }
        else{
            counter++;
            Current = Current->next;
        }
    }while(Current!=tail->next);
}

void DeleWithKey(Node* tail,int key)
{
    if(!tail)return ;
    Node* Current = tail->next,*temp;
    do{
        if(Current->next->value==key) 
        {
            temp=Current->next;
            Current->next = temp->next;
            if(temp==tail)tail=Current;
            delete temp;
            break;
        }
        else{
            Current = Current->next;
        }
    }while(Current!=tail->next);
}



void AddInPos(Node* tail,int position,int Key)
{
    if(!tail)return ;
    Node* Current = tail->next,*temp ;
    temp = new Node(Key);
    int counter =0;
    do{
        if(counter+1==position) 
        {
            temp->next = Current->next;
            Current->next = temp;
            if(position==0)tail=temp;
            break;
        }
        else{
            Current = Current->next;
            counter++;
        }
    }while(Current!=tail->next);
}


bool SearchWithKey(Node* tail,int key)
{
    if(!tail)return false;
    Node* Current = tail->next;
    do{
        if(Current->value==key) return true;
        else{
            Current = Current->next;
        }
    }while(Current!=tail->next);
    return false;
}


int main()
{
    Node* tail = nullptr;

    // 插入元素
    InsertNode(tail, 1);
    InsertNode(tail, 5);
    InsertNode(tail, 7);

    std::cout << "Initialize:" << std::endl;
    PrintList(tail);

    // 检查特定位置的元素
    std::cout << "position 1 : " << GetKeyWithPoi(tail, 1) << std::endl;

    // 检查是否包含特定元素
    std::cout << "include 2?: " << (SearchWithKey(tail, 2) ? "yes" : "no") << std::endl;

    // 在特定位置插入元素
    AddInPos(tail, 2, 10);
    std::cout << "insert 10 in 2 :" << std::endl;
    PrintList(tail);

    // 删除特定位置的元素
    DeleWithPos(tail, 2);
    std::cout << "delete position 2 :" << std::endl;
    PrintList(tail);

    // 删除特定键的元素
    DeleWithKey(tail, 2);
    std::cout << "delete key  2:" << std::endl;
    PrintList(tail);

    // 初始化链表（将所有元素设为 0）
    InitList(tail);
    std::cout << "initialize:" << std::endl;
    PrintList(tail);

    return 0;
}
