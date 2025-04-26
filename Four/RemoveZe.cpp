#include <iostream>


int * RemoveZ(int* Arr,int n)
{
    int * NewArr;
    int Count=0;
    for(int i=0;i<n;i++)
    {
        if(Arr[i]!=0){
        NewArr[Count]=Arr[i];
        Count++;
        }
      
    }
    return NewArr;
}


int main()
{
    int Arr[10]={1,2,3,0,0,4,5,6,0,10};
    int * NEwarr=RemoveZ(Arr,10);
    int counter=0;
    for(int i=0;i<7;i++){
        if(NEwarr[counter]!=0)
        std::cout<<NEwarr[counter++]<<" "<<std::endl;
    }
}