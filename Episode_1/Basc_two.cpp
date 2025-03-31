#include <iostream>
/*基础训练1-4 没有进行main函数的编写而是直接将所有的函数写出来
并且每一个函数都是测试过的
刘华强12303010232*/


int fun(int *a,int *b)
{
    if(*a==*b)
    return 1;
    return 0;
}


void fun(int *a,int n,int *odd,int *even)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]%2==0)
        (*even)++;
        else
        (*odd)++;
    }
}

int fun(int *a ,int *b, int n)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]%2==0)
        b[count++]=a[i];
    }
    return 1 ;
}

int exchange(int *a,int n)
{
    int max,min,maxloca=0,minloca=0;
    max=a[0];
    min=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]>max)max=a[i],maxloca=i;
        if(a[i]<min)min=a[i],minloca=i;
    }
    a[maxloca]=min;
    a[minloca]=max;
    return 1;
}


int main()
{
   
}