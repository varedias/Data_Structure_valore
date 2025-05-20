#include <iostream>
#include <vector>
#include <algorithm>

//用于检测是否会出现环
class UnionFind{
    private:
    std::vector<int> parent,rank;
    public:
    UnionFind(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;++i)
        {
            parent[i]=i;
        }
    }
    //查找u的根节点
    int find(int u)
    {
        if(u!=parent[u])
        parent[u]=find(parent[u]);
        return parent[u];
    }
    //合并元素u和v所在的集合
    void unionSets(int u,int v)
    {
        int rootU = find(u);
        int rootV = find(v);
        if(rootU>rank[rootV])
        parent[rootV]=rootU;
        else{
            parent[rootU] = rootV;
            if(rank[rootU]==rank[rootV])
            rank[rootV]++;
        }
    }
    
};

struct Edge{
    int u,v ,weight;
    Edge(int u,int v ,int w ):u(u),v(v),weight(w){}

    bool operator<(const Edge& other)const{// 用于对比两个边的权重大小
        return weight<other.weight;
    }
};


std::vector<Edge> kruskalMST(std::vector<Edge>& edges,int Numvertices)
{
    std::sort(edges.begin(),edges.end());//按权重排序
    UnionFind uf(Numvertices);

    std::vector<Edge> mst;

    for(const Edge& edge: edges)
    {
        //如果两个顶点不在同一个集合（也就是不会形成环）
        if(uf.find(edge.u)!=uf.find(edge.v)){
            uf.unionSets(edge.u,edge.v);//合并成两个集合
            mst.push_back(edge);//将边接入最小生成树
        }
        if(mst.size()==Numvertices-1)
        break;
    }
    return mst;
}




int main()
{

    std::vector<Edge> edges = {
        {1, 7, 6}, {1, 5, 23},{1, 6, 4}, {2, 1, 18}, {2, 5, 12},
        {2, 4, 8}, {2, 3, 5},{3, 4, 10}, {4, 5, 15}, {4, 6, 20},
        {5, 6, 25}, {6, 7, 7}
    };

    int Numvertices = 7;

    std::vector<Edge> mst = kruskalMST(edges,Numvertices);

    std::cout<<"the MST edge is :"<<std::endl;
    int totalweight = 0;
    for(const Edge& edge : mst)
    {
        std::cout<<edge.u<<"-"<<edge.v<<":"<<edge.weight<<std::endl;
        totalweight +=edge.weight;
    }

    std::cout<<"the min weightis :"<<totalweight<<std::endl;
    return 0;
    

}