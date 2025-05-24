#include <iostream>

#define length 100

void SerachKey(int * Arr,int key)
{
    for(int i=0;i<length;i++)
    {
        if(Arr[i]==key)
        {
            std::cout<<"Key found at index "<<i<<std::endl;
            return;
        }
    }
    std::cout<<"Key not found"<<std::endl;
}

int main()
{
    int Arr[length];
    
    for(int i=0;i<length;i++)
    {
        Arr[i]=rand()%100;
    }
    SerachKey(Arr,50);
    return 0;
}