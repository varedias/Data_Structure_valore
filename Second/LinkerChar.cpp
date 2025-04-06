#include <iostream>

struct LinkNode {
    char data;
    LinkNode* next;
};

LinkNode* CreateaNODE(char Data) {
    LinkNode* NewNode = new LinkNode;
    NewNode->data = Data;
    NewNode->next = nullptr;
    return NewNode;
}

void CreateInTail(LinkNode*& head, LinkNode*& tail, char Data) {
    LinkNode* NewNode = CreateaNODE(Data);
    if (head == nullptr) {
        head = tail = NewNode;
    } else {
        tail->next = NewNode;
        tail = NewNode;
    }
}

void Init(LinkNode* head) {
    LinkNode* temp = head;
    while (temp != nullptr) {
        temp->data = '0';
        temp = temp->next;
    }
}

void PrintNode(LinkNode* head) {
    LinkNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
}

char GetKeyWithPo(LinkNode* head, int position) {
    LinkNode* temp = head;
    int counter = 0;
    while (temp != nullptr) {
        if (counter == position) return temp->data;
        else {
            counter++;
            temp = temp->next;
        }
    }
    return '?';
}

void DeleteWithPos(LinkNode* head, int position) {
    LinkNode* temp = head, *Dele;
    int counter = 0;
    while (temp != nullptr) {
        if (counter + 1 == position) {
            Dele = temp->next;
            temp->next = Dele->next;
            delete Dele;
            break; 
        } else {
            counter++;
            temp = temp->next;
        }
    }
}

void DeleteKey(LinkNode* head, char& Key) {
    LinkNode* temp = head, *Dele;
    while (temp != nullptr && temp->next != nullptr) {
        if (temp->next->data == Key) {
            Dele = temp->next;
            temp->next = Dele->next;
            delete Dele;
        } else {
            temp = temp->next;
        }
    }
}

void InsertInHead(LinkNode*& head, char& Key) {
    LinkNode* NewNode = CreateaNODE(Key);
    NewNode->next = head;
    head = NewNode;
}

void InsertInTail(LinkNode*& head, LinkNode*& tail, char& Key) {
    LinkNode* NewNode = CreateaNODE(Key);
    if (head == nullptr) {
        head = tail = NewNode;
    } else {
        tail->next = NewNode;
        tail = NewNode;
    }
}

void InsertKeyWithPo(LinkNode*& head, int position, char& Key) {
    if (position == 0) {
        InsertInHead(head, Key);
        return;
    }

    LinkNode* temp = head, *NewNode;
    NewNode = CreateaNODE(Key);
    int counter = 0;
    while (temp != nullptr && counter < position - 1) {
        temp = temp->next;
        counter++;
    }

    if (temp != nullptr) {
        NewNode->next = temp->next;
        temp->next = NewNode;
    }
}

bool SearchKey(LinkNode* head, char& Key) {
    LinkNode* temp = head;
    while (temp != nullptr) {
        if (temp->data == Key)
            return true;
        else {
            temp = temp->next;
        }
    }
    return false;
}

int main() {
    LinkNode* head = nullptr;
    LinkNode* tail = nullptr;

    std::cout << "Testing tail insertion:" << std::endl;
    char data = 'A';
    CreateInTail(head, tail, data);
    data = 'B';
    CreateInTail(head, tail, data);
    data = 'C';
    CreateInTail(head, tail, data);
    PrintNode(head);

    std::cout << "Testing head insertion:" << std::endl;
    data = '0';
    InsertInHead(head, data);
    PrintNode(head);

    std::cout << "Testing insertion at specific position:" << std::endl;
    data = 'Z';
    InsertKeyWithPo(head, 2, data);
    PrintNode(head);

    std::cout << "Testing search key:" << std::endl;
    char key = 'B';
    bool found = SearchKey(head, key);
    std::cout << "Key '" << key << "' found: " << (found ? "true" : "false") << std::endl;

    std::cout << "Testing delete at specific position:" << std::endl;
    DeleteWithPos(head, 2);
    PrintNode(head);

    std::cout << "Testing delete key:" << std::endl;
    key = 'A';
    DeleteKey(head, key);
    PrintNode(head);

    std::cout << "Testing initialization of node values:" << std::endl;
    Init(head);
    PrintNode(head);

    return 0;
}
