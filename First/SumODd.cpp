#include <iostream>
#include <fstream>
#define Log(x)  std::cout<<x<<std::endl;
void readfile(std::ifstream& in,int* arr,int Lenth)
{
    for(int i=0;i<Lenth;i++)
    {
        in>>arr[i];
    }
     in.close();
}

void fun(int *a , int n , int *odd ,int *even)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]%2==0) *even+=a[i];
        if(a[i]%2==1) *odd+=a[i];
    }
}

int main() {
    std::ifstream in("inputfile.txt");
    int arr[6];
    readfile(in,arr,6);
    int odd=0,even=0;
    fun(arr,6,&odd,&even);
    Log(odd);
    Log(even);
    return 1 ;
}
