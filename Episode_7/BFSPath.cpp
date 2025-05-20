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


class Queue {
private:
    int* data;          
    int front;           
    int rear;            
    int capacity;       
public:
    Queue(int size = 100) {
        data = new int[size];
        front = rear = -1;
        capacity = size;
    }
    
    ~Queue() {
        delete[] data;
    }
    
    void enqueue(int x) {
        if (isFull()) {
            std::cout << "Queue overflow!" << std::endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        data[++rear] = x;
    }
    
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue underflow!" << std::endl;
            return -1;
        }
        int x = data[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        return x;
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return rear == capacity - 1;
    }
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


bool hasPathBFS(Graph& G, int vi, int vj) {
    if (vi == vj) return true;  

    Queue q;                
    q.enqueue(vi);         
    G.visited[vi] = true;
    
    while (!q.isEmpty()) {
        int v = q.dequeue();
        
        EdgeNode* p = G.adjlist[v].link;
        while (p != nullptr) {
            int w = p->adjvex;
            if (w == vj) { 

                for (int i = 0; i <= G.vexnum; i++) {
                    G.visited[i] = false;
                }
                return true;
            }
            if (!G.visited[w]) {
                G.visited[w] = true;
                q.enqueue(w);
            }
            p = p->next;
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
    
    
    std::cout << "path1->5: " << (hasPathBFS(G, 1, 5) ? "true" : "false") << std::endl;  
    std::cout << "path2->3: " << (hasPathBFS(G, 2, 3) ? "true" : "false") << std::endl;  
   
    
    return 0;
}