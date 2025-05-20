#include <iostream>
#include <climits>

struct EdgeNode {
    int adjvex;         
    int weight;         
    EdgeNode* next;      
};


struct VexNode {
    EdgeNode* link;     
};


struct Graph {
    VexNode* adjlist;    
    int vexnum;         
};

void initGraph(Graph& G, int n) {
    G.vexnum = n;
    G.adjlist = new VexNode[n];
    for (int i = 0; i < n; i++) {
        G.adjlist[i].link = nullptr;
    }
}

void addEdge(Graph& G, int from, int to, int weight) {
    EdgeNode* newNode = new EdgeNode{to, weight, G.adjlist[from].link};
    G.adjlist[from].link = newNode;
}

void dijkstra(const Graph& G, int src) {
    int n = G.vexnum;
    
  
    int* dist = new int[n];      
    bool* sptSet = new bool[n]; 
    
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    
    dist[src] = 0;  
    
    
    for (int count = 0; count < n-1; count++) {
      
        int minDist = INT_MAX;
        int u = -1;
        
        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && dist[v] <= minDist) {
                minDist = dist[v];
                u = v;
            }
        }
        
        if (u == -1) break;  
        
        sptSet[u] = true;  
        
      
        EdgeNode* p = G.adjlist[u].link;
        while (p != nullptr) {
            int v = p->adjvex;
            if (!sptSet[v] && dist[u] != INT_MAX && 
                dist[u] + p->weight < dist[v]) {
                dist[v] = dist[u] + p->weight;
            }
            p = p->next;
        }
    }
    
    
    std::cout << "vertex\tdistance(from" << src << ")" << std::endl;
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            std::cout << i << "\tunreachable" << std::endl;
        } else {
            std::cout << i << "\t" << dist[i] << std::endl;
        }
    }
    
    
}

int main() {
    const int V = 5;  
    Graph G;
    initGraph(G, V);
    
    
    addEdge(G, 0, 1, 4);
    addEdge(G, 0, 2, 1);
    addEdge(G, 1, 3, 1);
    addEdge(G, 2, 1, 2);
    addEdge(G, 2, 3, 5);
    addEdge(G, 3, 4, 3);
    
   
    dijkstra(G, 0);
    
    return 0;
}