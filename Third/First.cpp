#include <iostream>

#define MAX 1024

typedef struct stack{
    int data[MAX];
    int top;
}STACK;

void Init(STACK& STA)
{
    for(int i=0;i<MAX;i++)
    {
        STA.data[i]=0;
    }
    STA.top=0;

}

void ShowTop(STACK& STA)
{
    std::cout<<STA.data[STA.top]<<std::endl;
}


bool full(STACK& STA)
{
    return STA.top>=MAX;
}

bool empty(STACK& STA)
{
    return STA.top==0;
}
void EnStack(int* x,STACK & STA)
{
    if(!full(STA))
    STA.data[++STA.top]=*x;
}

int Pop(STACK & STA)
{
    if(!empty(STA))
    return STA.data[STA.top--];
    return -1;
}


int main()
{
    STACK sta;
    Init(sta);

    int a = 5;
    EnStack(&a, sta);
    ShowTop(sta);

    int b = 10;
    EnStack(&b, sta);
    ShowTop(sta);

    int poppedValue = Pop(sta);
    std::cout << "pop out: " << poppedValue << std::endl;
    ShowTop(sta);

    // 测试栈空
    if (empty(sta))
    {
        std::cout << "empty" << std::endl;
    }
    else
    {
        std::cout << "not empty" << std::endl;
    }

   
    for (int i = 0; i < MAX - 1; ++i) 
    {
        int value = i;
        EnStack(&value, sta);
    }

    if (full(sta))
    {
        std::cout << "full" << std::endl;
    }
    else
    {
        std::cout << "not full" << std::endl;
    }

    
    int c = 20;
    EnStack(&c, sta);

    return 0;
}

