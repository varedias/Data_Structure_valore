#include <iostream>

void  Init(int* Arr,int& length)
{

    for(int i=0;i<length;i++)
    {
        Arr[i]=0;
    }
}

void Out(int *Arr,int & length)
{
    for(int i=0;i<length;i++)
    {
        std::cout<<Arr[i]<<std::endl;
    }
}


int GetKey(int *Arr,int position)
{
    return Arr[position];
}

void DeletePosition(int *Arr,int Position,int &length)
{
    for(int i=Position;i<length;i++)
    {
        Arr[i]=Arr[i+1];
    }
    length--;
}

void DeleteKey(int *Arr,int key,int  &length)
{
    for(int i=0;i<length;i++)
    {
        if(Arr[i]==key)
        {
            DeletePosition(Arr,i,length);
            i--;
        }
    }
}


void AddTail(int * Arr,int & length,int NewKey)
{
    length++;
    Arr[length-1]=NewKey;
}

void AddHead(int *Arr,int & length,int NewKey)
{
        length++;
        for(int i=length-2;i>0;i--)
        {
            Arr[i+1]=Arr[i];
        }
        Arr[0]=NewKey;
}


void AddInPosition(int *Arr,int Position,int & length,int NewKey)
{
    length++;
    for(int i=length-2;i>Position;i--)
    {
        Arr[i+1]=Arr[i];
    }
    Arr[Position]=NewKey;
}

bool Exist(int *Arr,int Key,int & length)
{
    for(int i=0;i<length;i++)
    {
        if(Arr[i]==Key)
        return true;
    }
    return false;
}

int main()
{
    int length = 10;
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    std::cout << "original: ";
    Out(a, length);

    std::cout << "whether 10 is exist: " << (Exist(a, 10, length) ? "exist" : "non exist") << std::endl;

    std::cout << "delete position 5 : ";
    DeletePosition(a, 5, length);
    Out(a, length);

    std::cout << "delete key 3: ";
    DeleteKey(a, 3, length);
    Out(a, length);

    std::cout << "add 10 in tail: ";
    AddTail(a, length, 10);
    Out(a, length);

    std::cout << "add 0 in head: ";
    AddHead(a, length, 0);
    Out(a, length);

    std::cout << "insert 3 in position 3 : ";
    AddInPosition(a, 3, length, 3);
    Out(a, length);

    std::cout << "detect 3 : " << (Exist(a, 3, length) ? "exist" : "non exist ") << std::endl;

    std::cout << "init : ";
    Init(a, length);
    Out(a, length);

    return 0;
}