#include <iostream>

typedef struct node {
    int data;
    node* next;
    node() : data(0), next(nullptr) {}
    node(int x) : data(x), next(nullptr) {}
} Node;

class Queue {
private:
    Node* front;  
    Node* rear;  
    
public:
    Queue() : front(nullptr), rear(nullptr) {}
    

    
    void enque(int x) {
        Node* newNode = new Node(x);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    
    int deque() {
        if (empty()) {
            std::cerr << "Queue is empty!" << std::endl;
            return -1; 
        }
        
        Node* temp = front;
        int result = temp->data;
        
        front = front->next;
        if (front == nullptr) {
            rear = nullptr; 
        }
        
        delete temp;
        return result;
    }
    
    bool empty() const {
        return front == nullptr;
    }
};

int main() {
    Queue q;
    q.enque(10);
    q.enque(20);
    q.enque(30);

    std::cout << "Dequeued: " << q.deque() << std::endl;  // 输出 10
    std::cout << "Dequeued: " << q.deque() << std::endl;  // 输出 20

    std::cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << std::endl;  // 输出 No

    std::cout << "Dequeued: " << q.deque() << std::endl;  // 输出 30

    std::cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << std::endl;  // 输出 Yes

    return 0;
}