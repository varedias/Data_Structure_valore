#include<iostream>
#include <ctime>
#include <cstdlib>
/*进阶训练1 构造一维苏斯基整数型数组并且完成了7个操作
7个操作都进行过测试
刘华强12303010232*/
void  swap(int & fir,int & sec)
{
    int temp;
    temp=fir;
    fir=sec;
    sec=temp;
}

void DeleteByVAlue(int* arr,int& lenth,int value)//it will delete all the value ! 
{
    for(int i=0;i<lenth;i++)
    {
        if(arr[i]==value)
        {
            for(int j=i;j<lenth-1;j++)
            {
                swap(arr[j],arr[j+1]);
            }
            lenth--;//renew the length
            i--;
        }
    }

}

void DeleteByPosition(int* arr,int& lenth,int position)//the postition is not equal the subscript ! 
{
  
    if(position>lenth||position<=0){std::cout<<"the position is not exist !"<<std::endl;}
    for(int i=position-1;i<lenth-1;i++)
    {
        swap(arr[i+1],arr[i]);
    }
    lenth--;
    return ;
}

bool JudeSame(int i,int& value,int *temp)
{
    for(int j=0;j<i;j++)
    {
        if(temp[j]==value)
        return true;
    }
    return false;
}

void DeleteSameValue(int *arr,int &lenth)
{
    int temp[lenth]={0};
    int count=1;
    temp[0]=arr[0];
    for(int i=1;i<lenth;i++)
    {   
            if(JudeSame(i,arr[i],temp)) 
            {DeleteByPosition(arr,lenth,i+1);
            i--;
            }
            //be careful here we need to i-- otherwise we will get over a value ! 
            else  
            temp[count++]=arr[i];
    }
}

void AddInPosition(int *arr,int &lenth,int Position,int value)
{
    if(Position>lenth+1||Position<0) return ;
    lenth++;//before add we need to enlarge the array
    for(int i=lenth-2;i>Position-2;i--)
    {
        swap(arr[i+1],arr[i]);
    }
    arr[Position-1]=value;
}

void Sort(int *arr,int &lenth)//insert sort
{
    for(int i=0;i<lenth-1;i++)
    {
        int endPo = i;
        int temp = arr[endPo+1];
        while(endPo>=0)
        {
            if(arr[endPo]>temp)
            {
                arr[endPo+1]=arr[endPo];
                endPo--;
            }
            else
            break;
        }

        arr[endPo+1]=temp;
    }
}

void AddWithSequence(int *arr,int &lenth,int position,int value)
{
   lenth++;
   arr[lenth-1]=value;//directly add in the tail of that array and then sort it 
    Sort(arr,lenth);
}

void BackSort(int *arr,int &lenth)
{
    int j=0;
        for(int i=lenth-1;i>lenth/2;i--)
        {
            swap(arr[i],arr[j++]);
        }

}



int main()
{
    std::srand(std::time(0));
    int length = std::rand()%100+1;//the randow is from 1-99
    int arr[length];
    for(int i=0;i<length;i++)
        arr[i]=std::rand()%100;
   
    BackSort(arr,length);
    for(int i=0;i<length;i++)
    {
        std::cout<<arr[i]<<std::endl;
    }
    std::cout<<length<<std::endl;

}