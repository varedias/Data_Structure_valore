#include <iostream>
#include <vector>

struct Edge {
    int front;
    int behind;
    Edge(int fir, int sec) : front(fir), behind(sec) {}
};

class Queue {
private:
    int* queue;
    int front;
    int rear;
    int capacity;
    int size;

public:
    Queue(int value) : front(0), rear(0), capacity(value), size(0) {
        queue = new int[capacity];
    }


    bool full() {
        return size == capacity;
    }

    bool empty() {
        return size == 0;
    }

    void enqueue(int value) {
        if (!full()) {
            queue[rear] = value;
            rear = (rear + 1) % capacity;
            size++;
        }
    }

    int dequeue() {
        if (!empty()) {
            int value = queue[front];
            front = (front + 1) % capacity;
            size--;
            return value;
        }
        return -1; 
    }
};

void InsertLine(std::vector<std::vector<int>>& Graphic, Edge E) {
    if (E.front > 6 || E.behind > 6 || E.front < 0 || E.behind < 0) {
        std::cout << "Error edge!" << std::endl;
        return;
    }
    Graphic[E.front][E.behind] = 1;
}

void DeleteLine(std::vector<std::vector<int>>& Graphic, Edge E) {
    if (E.front > 6 || E.behind > 6 || E.front < 0 || E.behind < 0) {
        std::cout << "Error edge!" << std::endl;
        return;
    }
    Graphic[E.front][E.behind] = 0;
}

void printAll(std::vector<std::vector<int>>& Graphic) {
    for (const auto& row : Graphic) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

void BFS(std::vector<std::vector<int>>& Graphic, int start) {
    std::vector<bool> visited(Graphic.size(), false);
    Queue q(Graphic.size());

    q.enqueue(start);
    visited[start] = true;

    while (!q.empty()) {
        int v = q.dequeue();
        std::cout << v << " ";


        for (int i = 0; i < Graphic.size(); ++i) {
            if (Graphic[v][i] == 1 && !visited[i]) {
                q.enqueue(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    std::vector<std::vector<int>> adjacent(7, std::vector<int>(7, 0));
    adjacent[1][2] = 1;
    adjacent[1][3] = 1;
    adjacent[1][4] = 1;
    adjacent[6][4] = 1;
    adjacent[6][5] = 1;
    adjacent[3][5] = 1;
    adjacent[3][2] = 1;
    adjacent[4][5] = 1;

    printAll(adjacent);

    std::cout << "BSF from 1  : ";
    BFS(adjacent, 1);
    std::cout << std::endl;


    return 0;
}
