#include <iostream>
#define Size 20

void ReverseString(char* String,int length)
{
    char temp;
    for(int i=0;i<length/2;i++)
    {
        temp = String[length-i-1];
        String[length-i-1]=String[i];
        String[i]=temp;
    }
}


int main()
{
    char String [Size]={"hello,we are here"};
    ReverseString(String,Size);
    for(int i=0;i<Size;i++)
    {
        std::cout<<String[i];
    }

}