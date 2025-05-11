#include <iostream>
#include <vector>

class stack{
    private: 
    int *stacks;
    int top;
    int capicity;
    public:
    stack():top(0),capicity(0){}
    stack(int value):top(0),capicity(value){
        stacks=new int[capicity];
    }
    
    bool full()
    {
        return top==capicity;
    }

    bool empty()
    {
        return top==0;
    }
    void push(int value)
    {
        if(!full())
        stacks[top++]=value;
    }

    int pop()
    {
        if(!empty())
        {
            return stacks[--top];
        }
        return -1;
    }
    
};

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


void DFS( std::vector<std::vector<int>>& Graphic, int start)
{
    std::vector<bool> visited(Graphic.size(),false);
    stack s(Graphic.size());
    s.push(start);
    visited[start]=true;
    while(!s.empty()){
        int v = s.pop();
        std::cout<<v<<"";
        for(int i=0;i<Graphic.size();i++)
        {
            if(Graphic[v][i]==1&&!visited[i])
            {
                s.push(i);
                visited[i]=true;
            }
        }
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
    std::cout<<"DFS from 0  ";
    DFS(adjacent,0);
    std::cout<<std::endl;
    return 0;

}
