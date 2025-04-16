#include  <iostream>

typedef struct link{
    int info;
    link *next;
    link():info(0),next(nullptr){}//初始化
}Link;

int ShowTop(Link*& Top)
{
    if(Top!=nullptr)
   return Top->info;
   return -1;
}


bool empty(Link*& Top)
{
    return Top==nullptr;
}

void EnStack(Link*&Top,int value)
{
    Link* Temp = new Link();
    Temp->info = value;
    Temp->next = Top;
    Top=Temp;
}

int  Pop(Link*& TOP)
{
    Link* temp=TOP; 
    if(!empty(TOP)){
    TOP=TOP->next;
    delete temp;
    return temp->info;
    }
    return -1;
}

int main()
{
    Link* top = nullptr;


    EnStack(top, 5);
    std::cout << "enstack: 5 top is: " << ShowTop(top) << std::endl;

    EnStack(top, 10);
    std::cout << "enstack: 10 top is : " << ShowTop(top) << std::endl;

    int poppedValue = Pop(top);
    std::cout << "pop : " << poppedValue << std::endl;
    std::cout << "top is: " << ShowTop(top) << std::endl;

    poppedValue = Pop(top);
    std::cout << "pop is : " << poppedValue << std::endl;

    poppedValue = Pop(top); 

    return 0;
}