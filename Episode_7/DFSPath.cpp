#include <iostream>



struct EdgeNode {
    int adjvex;        
    EdgeNode* next;     
};


struct VexNode {
    EdgeNode* link;      
};


struct Graph {
    VexNode* adjlist;    
    int vexnum;          
    bool* visited;      
};


void initGraph(Graph& G, int n) {
    G.vexnum = n;
    G.adjlist = new VexNode[n+1];  
    G.visited = new bool[n+1];
    for (int i = 0; i <= n; i++) {
        G.adjlist[i].link = nullptr;
        G.visited[i] = false;
    }
}


void addEdge(Graph& G, int from, int to) {
    EdgeNode* newNode = new EdgeNode{to, G.adjlist[from].link};
    G.adjlist[from].link = newNode;
}


class Stack {
private:
    int* data;          
    int top;            
    int capacity;       
public:
    Stack(int size = 100) {
        data = new int[size];
        top = -1;
        capacity = size;
    }
    
    ~Stack() {
        delete[] data;
    }
    
    void push(int x) {
        if (top >= capacity - 1) {
            std::cout << "Stack overflow!" << std::endl;
            return;
        }
        data[++top] = x;
    }
    
    int pop() {
        if (isEmpty()) {
            std::cout << "Stack underflow!" << std::endl;
            return -1;
        }
        return data[top--];
    }
    
    bool isEmpty() {
        return top == -1;
    }
    
    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty!" << std::endl;
            return -1;
        }
        return data[top];
    }
};


bool hasPathDFS(Graph& G, int vi, int vj) {
    if (vi == vj) return true; 
    
    Stack s;              
    s.push(vi);            
    G.visited[vi] = true;
    
    while (!s.isEmpty()) {
        int v = s.peek();   
        if (v == vj) {     
           
            for (int i = 0; i <= G.vexnum; i++) {
                G.visited[i] = false;
            }
            return true;
        }
        
        EdgeNode* p = G.adjlist[v].link;
        bool foundUnvisited = false;
        
       
        while (p != nullptr) {
            if (!G.visited[p->adjvex]) {
                foundUnvisited = true;
                break;
            }
            p = p->next;
        }
        
        if (foundUnvisited) {
           
            int w = p->adjvex;
            G.visited[w] = true;
            s.push(w);
        } else {
           
            s.pop();
        }
    }
    
   
    for (int i = 0; i <= G.vexnum; i++) {
        G.visited[i] = false;
    }
    return false;
}

int main() {
    int n = 5;  
    Graph G;
    initGraph(G, n);
    
    
    addEdge(G, 1, 2);
    addEdge(G, 1, 3);
    addEdge(G, 2, 4);
    addEdge(G, 3, 4);
    addEdge(G, 4, 5);
    
    
    std::cout << "path1->5: " << hasPathDFS(G, 1, 5) << std::endl;  
    std::cout << "path2->3: " << hasPathDFS(G, 2, 3) << std::endl; 

    
    return 0;
}