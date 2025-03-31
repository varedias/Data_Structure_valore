#include <iostream>
#include <fstream>
#define Log(X)  std::cout<<X<<std::endl;

void readfile(std::ifstream& in,int* arr,int Lenth)
{
    for(int i=0;i<Lenth;i++)
    {
        in>>arr[i];
    }
     in.close();
}


int exchange(int *a ,int n)
{
    int max=a[0],min=a[0],maxloca=0,minloca=0,temp;
    for(int i=1;i<n;i++)
    {
        if(a[i]>max){max=a[i];maxloca=i;}
        if(a[i]<min){min=a[i];minloca=i;}
    }
    temp=a[maxloca];
    a[maxloca]=a[minloca];
    a[minloca]=temp;
    return 1;
}

int main()
{
    std::ifstream in ("inputfile.txt");
    int arr[6];
    readfile(in,arr,6);
    Log("former:");
    for(int i=0;i<6;i++) Log(arr[i]);
    exchange(arr,6);
    Log("later");
    for(int i=0;i<6;i++) Log(arr[i]);


}


