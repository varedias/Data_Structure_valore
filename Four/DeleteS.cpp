#include <iostream>




void DeteleString(char* string1,char * string2,int &size1,int &size2)
{
    for(int i=0;i<size1;i++)
    {
        if(string1[i]==string2[0])
        {
            for(int j=1;j<size2;j++)
            {
                if(string1[i+j]!=string2[j])
                break;
            }
            for(int m=i+size2;m<size1-1;m++)
            string1[i]=string1[m+1];
           size1=size1-size2;
        }
    }

}


int main()
{
    int size1=7;
    int size2=1;
    char  string1[]="aaabcd";
    char * string2="a";
    DeteleString(string1,string2,size1,size2);
    for(int i=0;i<size1;i++)
    {std::cout<<string1[i];}

}
