#include <iostream>
#include <string>




int patten_index(std::string& patten,std::string& string2)
{
    std::string pattenW;
    int index=0;
    for(int i=0;i<patten.size();i++)
    {
        if(patten[i]=='?')
        {
            pattenW=patten.substr(i+1);
        break;
         }
    }

    for(int i=0;i<string2.size();i++)
    {
        if(string2[i]==pattenW[0])
        {
            for(int j=1;j<pattenW.size();j++)
            {
                if(string2[i+j]!=pattenW[j])
                break;
                index++;
                i=i+j;
            }
        }
    }
    return index;

}


int main()
{

    std::string patten="?re";
    std::string string2="there are";
    std::cout<<patten_index(patten,string2);
}