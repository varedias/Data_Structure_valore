// #include <iostream>
// #include <vector>

// class stack {
// private:
//     int* stacks;
//     int top;
//     int capacity;
// public:
//     stack() : top(0), capacity(0), stacks(nullptr) {}  
//         stack(int value) : top(0), capacity(value) {
//         stacks = new int[capacity];
//     }
//     ~stack() {  
//         delete[] stacks;
//     }
    
//     bool full() const {
//         return top == capacity;
//     }

//     bool empty() const {
//         return top == 0;
//     }

//     void push(int value) {
//         if (!full()) {
//             stacks[top++] = value;
//         }
//     }

//     int pop() {
//         if (!empty()) {
//             return stacks[--top];
//         }
//         return -1; 
//     }
// };

// void printAll(const std::vector<std::vector<int>>& Graphic) {
//     for (size_t i = 1; i < Graphic.size(); ++i) {
//         for (size_t j = 1; j < Graphic[i].size(); ++j) {
//             std::cout << Graphic[i][j] << " ";
//         }
//         std::cout << std::endl;
//     }
// }

// void DFS(std::vector<std::vector<int>>& Graphic, int start) {
//     const int n = Graphic.size() - 1; 
//     if (start < 1 || start > n) {
//         std::cout << "Invalid start node" << std::endl;
//         return;
//     }

//     std::vector<bool> visited(n + 1, false); 
//     stack s(n);
//     s.push(start);
//     visited[start] = true;

//     while (!s.empty()) {
//         int v = s.pop();
//         std::cout << v << " ";
        

//         for (int i = 1; i <= n; ++i) {
//             if (Graphic[v][i] == 1 && !visited[i]) {
//                 s.push(i);
//                 visited[i] = true;
//             }
//         }
//     }
// }

// int main() {
//     std::vector<std::vector<int>> adjacent(9, std::vector<int>(9, 0));

//     adjacent[1][2] = 1; adjacent[2][1] = 1;
//     adjacent[1][3] = 1; adjacent[3][1] = 1;
//     adjacent[1][4] = 1; adjacent[4][1] = 1;

//     adjacent[2][4] = 1; adjacent[4][2] = 1;
//     adjacent[2][5] = 1; adjacent[5][2] = 1;
//     adjacent[2][3] = 1; adjacent[3][2] = 1;

//     adjacent[3][6] = 1; adjacent[6][3] = 1;
//     adjacent[3][8] = 1; adjacent[8][3] = 1;

//     adjacent[4][6] = 1; adjacent[6][4] = 1;
//     adjacent[4][5] = 1; adjacent[5][4] = 1;

//     adjacent[5][7] = 1; adjacent[7][5] = 1;
//     adjacent[5][8] = 1; adjacent[8][5] = 1;

//     std::cout << "Adjacency Matrix (nodes 1-8):\n";
//     printAll(adjacent);
    
//     std::cout << "DFS starting from node 1: ";
//     DFS(adjacent, 1);
//     std::cout << std::endl;

//     return 0;
// }