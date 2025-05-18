// #include <iostream>
// #include <vector>


// struct ListNode {
//     int vertex;        
//     ListNode* next;     
    
//     ListNode(int v) : vertex(v), next(nullptr) {}
// };


// class LinkedList {
// private:
//     ListNode* head;     
    
// public:
//     LinkedList() : head(nullptr) {}
    
//     void append(int vertex) {
//         ListNode* newNode = new ListNode(vertex);
//         if (head == nullptr) {
//             head = newNode;
//         } else {
//             ListNode* current = head;
//             while (current->next != nullptr) {
//                 current = current->next;
//             }
//             current->next = newNode;
//         }
//     }
    
   
//     void print() const {
//         ListNode* current = head;
//         while (current != nullptr) {
//             std::cout << current->vertex << " ";
//             current = current->next;
//         }
//     }
    
    
//     ListNode* getHead()  { return head; }
// };



// void printAdjacencyList(const std::vector<LinkedList>& list) {
//     for (size_t i = 1; i < list.size(); ++i) {
//         std::cout << "vertex " << i << " connect to : ";
//         list[i].print();
//         std::cout << std::endl;
//     }
// }

// int main() {
//     std::vector<LinkedList> Link(5);

//     Link[0].append(2);
//     Link[0].append(3);
//     Link[0].append(4);

//     Link[1].append(1);
//     Link[1].append(3);
//     Link[1].append(5);

//     Link[2].append(1);
//     Link[2].append(2);
//     Link[2].append(4);
//     Link[2].append(5);

//     Link[3].append(1);
//     Link[3].append(3);
//     Link[3].append(5);

//     Link[4].append(2);
//     Link[4].append(3);
//     Link[4].append(4);

//     printAdjacencyList(Link);
// }