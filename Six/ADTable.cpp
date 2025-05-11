#include <iostream>
#include <vector>


struct ListNode {
    int vertex;        
    ListNode* next;     
    
    ListNode(int v) : vertex(v), next(nullptr) {}
};


class LinkedList {
private:
    ListNode* head;     
    
public:
    LinkedList() : head(nullptr) {}
    
    void append(int vertex) {
        ListNode* newNode = new ListNode(vertex);
        if (head == nullptr) {
            head = newNode;
        } else {
            ListNode* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    
   
    void print() const {
        ListNode* current = head;
        while (current != nullptr) {
            std::cout << current->vertex << " ";
            current = current->next;
        }
    }
    
    
    ListNode* getHead()  { return head; }
};


using AdjacencyList = std::vector<LinkedList>;


AdjacencyList convertToAdjacencyList(const std::vector<std::vector<int>>& matrix) {
    AdjacencyList list(matrix.size());
    
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] == 1) {
                list[i].append(j);
            }
        }
    }
    
    return list;
}


void printAdjacencyList(const AdjacencyList& list) {
    for (size_t i = 0; i < list.size(); ++i) {
        std::cout << "vertex " << i << " connect to : ";
        list[i].print();
        std::cout << std::endl;
    }
}

int main() {

    std::vector<std::vector<int>> adjacent(8, std::vector(8, 0));
    adjacent[0][1] = 1; adjacent[1][0] = 1;
    adjacent[1][4] = 1; adjacent[4][1] = 1;
    adjacent[4][3] = 1; adjacent[3][4] = 1;
    adjacent[3][2] = 1; adjacent[2][3] = 1;
    adjacent[1][2] = 1; adjacent[2][1] = 1;
    adjacent[0][5] = 1; adjacent[5][0] = 1;
    adjacent[5][7] = 1; adjacent[7][5] = 1;
    adjacent[7][6] = 1; adjacent[6][7] = 1;
    adjacent[5][6] = 1; adjacent[6][5] = 1;
    

    
    AdjacencyList adjacencyList = convertToAdjacencyList(adjacent);
    

    printAdjacencyList(adjacencyList);
    
    return 0;
}