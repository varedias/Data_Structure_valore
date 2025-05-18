#include <iostream>
#include <vector>

class queue {
private:
    int* queues;
    int front;
    int rear;
    int capacity;
public:
    queue() : front(0), rear(0), capacity(0), queues(nullptr) {}
    queue(int value) : front(0), rear(0), capacity(value) {
        queues = new int[capacity];
    }
    ~queue() {
        delete[] queues;
    }
    
    bool full() const {
        return (rear + 1) % capacity == front;
    }

    bool empty() const {
        return front == rear;
    }

    void push(int value) {
        if (!full()) {
            queues[rear] = value;
            rear = (rear + 1) % capacity;
        }
    }

    int pop() {
        if (!empty()) {
            int value = queues[front];
            front = (front + 1) % capacity;
            return value;
        }
        return -1; 
    }
};

struct Edge {
    int front;
    int behind;
    Edge(int fir, int sec) : front(fir), behind(sec) {}
};

void printAll(const std::vector<std::vector<int>>& Graphic) {
    for (size_t i = 1; i < Graphic.size(); ++i) {
        for (size_t j = 1; j < Graphic[i].size(); ++j) {
            std::cout << Graphic[i][j] << " ";
        }
        std::cout << std::endl;
    }
}



void BFS(std::vector<std::vector<int>>& Graphic, int start) {
    const int n = Graphic.size() - 1; 
    if (start < 1 || start > n) {
        std::cout << "Invalid start node" << std::endl;
        return;
    }

    std::vector<bool> visited(n + 1, false); 
    queue q(n);
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int v = q.pop();
        std::cout << v << " ";
        

        for (int i = 1; i <= n; ++i) {
            if (Graphic[v][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    std::vector<std::vector<int>> adjacent(9, std::vector<int>(9, 0));

    adjacent[1][2] = 1; adjacent[2][1] = 1;
    adjacent[1][3] = 1; adjacent[3][1] = 1;
    adjacent[1][4] = 1; adjacent[4][1] = 1;

    adjacent[2][4] = 1; adjacent[4][2] = 1;
    adjacent[2][5] = 1; adjacent[5][2] = 1;
    adjacent[2][3] = 1; adjacent[3][2] = 1;

    adjacent[3][6] = 1; adjacent[6][3] = 1;
    adjacent[3][8] = 1; adjacent[8][3] = 1;

    adjacent[4][6] = 1; adjacent[6][4] = 1;
    adjacent[4][5] = 1; adjacent[5][4] = 1;

    adjacent[5][7] = 1; adjacent[7][5] = 1;
    adjacent[5][8] = 1; adjacent[8][5] = 1;

    std::cout << "Adjacency Matrix (nodes 1-8):\n";
    printAll(adjacent);
    
   

    std::cout << "BFS starting from node 1: ";
    BFS(adjacent, 1);
    std::cout << std::endl;

    return 0;
}
