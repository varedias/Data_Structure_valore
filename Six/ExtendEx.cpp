#include <iostream>
#include <vector>

struct Node {
    int data;
    Node* next;
    int in_degree; 
    Node(int value) : data(value), next(nullptr), in_degree(0) {}
};

class Queue {
private:
    struct QueueNode {
        int data;
        QueueNode* next;
        QueueNode(int val) : data(val), next(nullptr) {}
    };
    
    QueueNode* front;
    QueueNode* rear;
    
public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int value) {
        QueueNode* newNode = new QueueNode(value);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    
    void dequeue() {
        if (isEmpty()) {
            return;
        }
        QueueNode* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }
    
    int peek() const {
        if (isEmpty()) {
            return -1; 
        }
        return front->data;
    }
    
    bool isEmpty() const {
        return front == nullptr;
    }
};

class AdjacencyList {
private:
    Node* head;
public:
    AdjacencyList() : head(nullptr) {}  
    AdjacencyList(Node* heads) : head(heads) {}

    void addEdge(int to) {
        if (head == nullptr) return;
        
        Node* newNode = new Node(to);
        newNode->next = head->next;
        head->next = newNode;

        Node* current = head;
        while (current != nullptr && current->data != to) {
            current = current->next;
        }
        if (current != nullptr) {
            current->in_degree++;
        }
    }

    Node* getHead() const {
        return head;
    }

    void print() {
        if (head == nullptr) {
            std::cout << "empty Link!" << std::endl;
            return;
        }
        std::cout << "Node: " << head->data << " -> ";
        Node* neighbor = head->next;
        while (neighbor != nullptr) {
            std::cout << neighbor->data << " ";
            neighbor = neighbor->next;
        }
        std::cout << std::endl;
    }
};

void topologicalSort(const std::vector<AdjacencyList>& Graphics) {
    Queue q;
    std::vector<int> in_degree(7, 0); 
    
    
    for (const auto& list : Graphics) {
        Node* current = list.getHead();
        if (current == nullptr) continue;
        
        Node* neighbor = current->next;
        while (neighbor != nullptr) {
            in_degree[neighbor->data]++;
            neighbor = neighbor->next;
        }
    }

   
    for (const auto& list : Graphics) {
        Node* current = list.getHead();
        if (current != nullptr && in_degree[current->data] == 0) {
            q.enqueue(current->data);
        }
    }

  
    while (!q.isEmpty()) {
        int current_data = q.peek();
        q.dequeue();
        std::cout << current_data << " ";
        
       
        for (const auto& list : Graphics) {
            Node* current = list.getHead();
            if (current != nullptr && current->data == current_data) {
                Node* neighbor = current->next;
                while (neighbor != nullptr) {
                    in_degree[neighbor->data]--;
                    if (in_degree[neighbor->data] == 0) {
                        q.enqueue(neighbor->data);
                    }
                    neighbor = neighbor->next;
                }
                break;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    std::vector<AdjacencyList> Graphics(6);

    
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);

   
    Graphics[0] = AdjacencyList(node1);
    Graphics[1] = AdjacencyList(node2);
    Graphics[2] = AdjacencyList(node3);
    Graphics[3] = AdjacencyList(node4);
    Graphics[4] = AdjacencyList(node5);
    Graphics[5] = AdjacencyList(node6);

    
    Graphics[0].addEdge(2);  
    Graphics[0].addEdge(3);  
    Graphics[0].addEdge(4);  

    Graphics[2].addEdge(5);  
    Graphics[2].addEdge(2); 

    Graphics[3].addEdge(5);  
    

    Graphics[5].addEdge(4);  
    Graphics[5].addEdge(5);  

   
    std::cout << "Graphics:" << std::endl;
    for (auto& list : Graphics) {
        list.print();
    }

    
    std::cout << "Topological order:" << std::endl;
    topologicalSort(Graphics);

    
  

    return 0;
}