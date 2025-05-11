#include <iostream>
#include <vector>

struct Edge{
    int front;
    int behind;
    Edge(int fir,int sec):front(fir),behind(sec){}
};

void InsertLine(std::vector<std::vector<int>>& Graphic,Edge E)
{
    if(E.front>7||E.behind>7||E.front<0||E.behind<0)
    {
        std::cout<<"Error edge!"<<std::endl;
        return;
    }
    Graphic[E.front][E.behind]=1;
    Graphic[E.behind][E.front]=1;
}

void DeleteLine(std::vector<std::vector<int>>& Graphic,Edge E)
{
    if(E.front>7||E.behind>7||E.front<0||E.behind<0)
    {
        std::cout<<"Error edge!"<<std::endl;
        return;
    }
    Graphic[E.front][E.behind]=0;
    Graphic[E.behind][E.front]=0;
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
    std::vector<std::vector<int>> adjacent(8,std::vector(8,0));
    adjacent[0][1]=1; adjacent[1][0]=1;
    adjacent[1][4]=1;adjacent[4][1]=1;
    adjacent[4][3]=1; adjacent[3][4]=1;
    adjacent[3][2]=1; adjacent[2][3]=1;
    adjacent[1][2]=1;adjacent[2][1]=1;
    adjacent[0][5]=1; adjacent[5][0]=1;
    adjacent[5][7]=1; adjacent[7][5]=1;
    adjacent[7][6]=1; adjacent[6][7]=1;
    adjacent[5][6]=1; adjacent[6][5]=1;
    printAll(adjacent);
    Edge* NEW1 = new Edge(5,4);
    InsertLine(adjacent,*NEW1);
    std::cout<<std::endl;
    printAll(adjacent);
    Edge* Dele1 = new Edge(6,7);
    DeleteLine(adjacent,*Dele1);
    std::cout<<std::endl;
    printAll(adjacent);

}
