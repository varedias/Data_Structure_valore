#include <iostream>

struct Node {
    int Data;
    Node* next;
    Node* prev;
    Node(int Key = 0) : Data(Key), next(nullptr), prev(nullptr) {}
};


Node* InitList() {
    return new Node();
}


void InsertNode(Node* head, int value) {
    Node* NewNode = new Node(value);
    if (head->next==nullptr) {
        head->next = NewNode;
        NewNode->prev = head;
        NewNode->next = head;
        head->prev = NewNode;
    } else {
        NewNode->next = head;
        NewNode->prev = head->prev;
        head->prev->next = NewNode;
        head->prev = NewNode;
    }
}


void PrintList(Node* head) {
    Node* Current = head->next;
    do {
        std::cout << Current->Data << std::endl;
        Current = Current->next;
    } while (Current != head);
}


void InitListData(Node* head) {
    Node* Current = head->next;
    while (Current != head) {
        Current->Data = 0;
        Current = Current->next;
    }
}


void AddInPos(Node* head, int position, int Key) {
    Node* Current = head->next;
    Node* NewNode = new Node(Key);
    int counter = 0;
    if (position == 0) { 
        NewNode->next = head->next;
        NewNode->prev = head;
        if (head->next) head->next->prev = NewNode;
        head->next = NewNode;
        if (!head->prev) head->prev = NewNode;
    } else {
        while (Current != head) {
            if (counter == position) {
                NewNode->next = Current;
                NewNode->prev = Current->prev;
                Current->prev->next = NewNode;
                Current->prev = NewNode;
                break;
            }
            else {
                counter++;
                Current = Current->next;
            }
        }
    }
}


void DeleWithPos(Node* head, int Position) {
    Node* Current = head->next;
    int counter = 0;
    if (Position == 0) { 
        Node* temp = head->next;
        if (temp->next) temp->next->prev = head;
        head->next = temp->next;
        delete temp;
    } else {
        while (Current != head) {
            if (counter == Position) {
                Node* temp = Current;
                temp->prev->next = temp->next;
                if (temp->next) temp->next->prev = temp->prev;
                delete temp;
                break;
            }
            else {
                counter++;
                Current = Current->next;
            }
        }
    }
}


void DeleWithKey(Node* head, int key) {
    Node* Current = head->next;
    if (head->next && head->next->Data == key) { 
        Node* temp = head->next;
        if (temp->next) temp->next->prev = head;
        head->next = temp->next;
        delete temp;
    } else {
        while (Current != head) {
            if (Current->Data == key) {
                Node* temp = Current;
                temp->prev->next = temp->next;
                if (temp->next) temp->next->prev = temp->prev;
                delete temp;
                break;
            }
            else {
                Current = Current->next;
            }
        }
    }
}


bool SearchWithKey(Node* head, int key) {
    Node* Current = head->next;
    if (!Current) return false; 
    while (Current != head) {
        if (Current->Data == key) return true;
        else {
            Current = Current->next;
        }
    }
    return false;
}


int GetKeyWithPoi(Node* head, int Position) {
    Node* Current = head->next;
    int counter = 0;
    if (!Current) return -1; 
    while (Current != head) {
        if (counter == Position) return Current->Data;
        else {
            counter++;
            Current = Current->next;
        }
    }
    return -1;
}

int main() {
    Node* head = InitList(); 

    
    InsertNode(head, 1);
    InsertNode(head, 2);
    InsertNode(head, 3);

    std::cout << "Initialize:" << std::endl;
    PrintList(head);

    
    std::cout << "position 1 : " << GetKeyWithPoi(head, 1) << std::endl;

    
    std::cout << "include 2?: " << (SearchWithKey(head, 2) ? "yes" : "no") << std::endl;

    
    AddInPos(head, 2, 10);
    std::cout << "insert 10 in 2 :" << std::endl;
    PrintList(head);

    
    DeleWithPos(head, 2);
    std::cout << "delete position 2 :" << std::endl;
    PrintList(head);

    
    DeleWithKey(head, 2);
    std::cout << "delete key  2:" << std::endl;
    PrintList(head);

    
    InitListData(head);
    std::cout << "initialize:" << std::endl;
    PrintList(head);



    return 0;
}
