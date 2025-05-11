#include <iostream>
#include <vector>

struct Edge{
    int front;
    int behind;
    Edge(int fir,int sec):front(fir),behind(sec){}
};

void InsertLine(std::vector<std::vector<int>>& Graphic,Edge E)
{
    if(E.front>6||E.behind>6||E.front<0||E.behind<0)
    {
        std::cout<<"Error edge!"<<std::endl;
        return;
    }
    Graphic[E.front][E.behind]=1;
}

void DeleteLine(std::vector<std::vector<int>>& Graphic,Edge E)
{
    if(E.front>6||E.behind>6||E.front<0||E.behind<0)
    {
        std::cout<<"Error edge!"<<std::endl;
        return;
    }
    Graphic[E.front][E.behind]=0;

}


void printAll(std::vector<std::vector<int>>& Graphic)
{
    for(const auto& row :Graphic)
    {
        for(int val: row)
        {
            std::cout<<val<<"";
        }
        std::cout<<std::endl;
    }
}


int main()
{
    std::vector<std::vector<int>> adjacent(7,std::vector(7,0));
    adjacent[1][2]=1;
     adjacent[1][3]=1;
    adjacent[1][4]=1;
    adjacent[6][4]=1;
    adjacent[6][5]=1;
     adjacent[3][5]=1;
    adjacent[3][2]=1; 
    adjacent[4][5]=1;
    printAll(adjacent);
    Edge* NEW1 = new Edge(4,3);
    InsertLine(adjacent,*NEW1);
    std::cout<<std::endl;
    printAll(adjacent);
    Edge* Dele1 = new Edge(6,5);
    DeleteLine(adjacent,*Dele1);
    std::cout<<std::endl;
    printAll(adjacent);

}
