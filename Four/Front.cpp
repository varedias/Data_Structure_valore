#include <iostream>

bool Front(char * String1,char * String2,int lenght1,int length2)
{
    if(lenght1>length2)
    return false;
    for(int i=0;i<lenght1-1;i++)
    {
        if(String1[i]!=String2[i])return false;
    }
    return true;
}


int main()
{
    char String1[8]={"Wounder"};
    char String2[11]={"Wounderful"};
    std::cout<<Front(String1,String2,8,11);
}