#include <iostream>
using namespace std;

struct EdgeNode {
    int adjvex;         
    EdgeNode* next;     
};

struct VexNode {
    EdgeNode* link;      
};

struct Graph {
    VexNode adjlist[9];  
    bool visited[9];    
};

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
    
   
    void push(int x) {
        if (top >= capacity - 1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        data[++top] = x;
    }
    
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        return data[top--];
    }
    
    bool isEmpty() {
        return top == -1;
    }
    
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return data[top];
    }
};


void initGraph(Graph& G) {
   
    EdgeNode* e13 = new EdgeNode{3, nullptr};
    EdgeNode* e12 = new EdgeNode{2, e13};
    EdgeNode* e11 = new EdgeNode{1,e12};
    G.adjlist[1].link = e11;
    
  
    EdgeNode* e24 = new EdgeNode{5, nullptr};
    EdgeNode* e23 = new EdgeNode{4, e24};
    EdgeNode* e22 = new EdgeNode{1, e23};
    EdgeNode* e21 = new EdgeNode{2, e22};
    G.adjlist[2].link = e21;
    
 
    EdgeNode* e34 = new EdgeNode{7, nullptr};
    EdgeNode* e33 = new EdgeNode{6, e34};
    EdgeNode* e32 = new EdgeNode{1, e33};
    EdgeNode* e31 = new EdgeNode{3, e32};
    G.adjlist[3].link = e31;
 
    EdgeNode* e43 = new EdgeNode{8, nullptr};
    EdgeNode* e42 = new EdgeNode{2, e43};
    EdgeNode* e41 = new EdgeNode{4, e42};
    G.adjlist[4].link = e41;
    
   
    EdgeNode* e53 = new EdgeNode{8, nullptr};
    EdgeNode* e52 = new EdgeNode{2, e53};
    EdgeNode* e51 = new EdgeNode{4, e52};
    G.adjlist[5].link = e51;
    
   
    EdgeNode* e63 = new EdgeNode{8, nullptr};
    EdgeNode* e62 = new EdgeNode{3, e63};
    EdgeNode* e61 = new EdgeNode{6, e62}; 
    G.adjlist[6].link = e61;
    
  
    EdgeNode* e73 = new EdgeNode{8, nullptr};
    EdgeNode* e72 = new EdgeNode{3, e73};
    EdgeNode* e71 = new EdgeNode{7, e72};
    G.adjlist[7].link = e71;
    
    
    EdgeNode* e85 = new EdgeNode{7, nullptr};
    EdgeNode* e84 = new EdgeNode{6, e85};
    EdgeNode* e83 = new EdgeNode{5, e84};
    EdgeNode* e82 = new EdgeNode{4, e83};
    EdgeNode* e81 = new EdgeNode{8, e82};
    G.adjlist[8].link = e81;
    
    
    for (int i = 0; i < 9; i++) {
        G.visited[i] = false;
    }
}


void DFS(Graph& G, int start) {
    Stack s;              
    s.push(start);        
    G.visited[start] = true;
    cout << "DFS: " << start << " ";
    
    while (!s.isEmpty()) {
        int v = s.peek();  
        EdgeNode* p = G.adjlist[v].link;
        
       
        while (p != nullptr && G.visited[p->adjvex]) {
            p = p->next;
        }
        
        if (p != nullptr) {
          
            int w = p->adjvex;
            G.visited[w] = true;
            cout << w << " ";
            s.push(w);
        } else {
            
            s.pop();
        }
    }
    cout << endl;
}

int main() {
    Graph G;
    initGraph(G);
    
    cout << "DFS from vertex 8 :" << endl;
    DFS(G, 8);
    
    return 0;
}