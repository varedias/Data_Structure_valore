#include <iostream>
#include <string>

class Node {
public:
    char data;
    Node* next;
    Node(char val) : data(val), next(nullptr) {}
};

class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}

    bool empty() {
        return top == nullptr;
    }

    void push(char value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (empty()) {
            return -1; 
        }
        char value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }
};

bool issame(const std::string& str) {
    Stack stack;
    for (char ch : str) {
        if (ch == '@') {
            break;
        }
        stack.push(ch);
    }

    for (char ch : str) {
        if (ch == '@') {
            break;
        }
        if (ch != stack.pop()) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string input;
    std::cout << "get a string end with @: ";
    std::getline(std::cin, input);

    if (issame(input)) {
        std::cout << "same" << std::endl;
    } else {
        std::cout << "not same" << std::endl;
    }

    return 0;
}
