#include <iostream>
#include <cctype>

struct Link {
    char m_data;
    Link* next;
    Link(): m_data(0), next(nullptr) {}
    Link(char data): m_data(data), next(nullptr) {}
};

class Stack {
private:
    Link* m_head; 
    Link* m_top;  
public:
    Stack(): m_head(new Link()), m_top(m_head) {} 

    void Enstack(char data) {
        if (std::isalnum(data)) {
            Link* temp = new Link(std::tolower(data)); 
            temp->next = m_top->next; 
            m_top->next = temp;       
            m_top = temp;
    }

    bool empty() {
        return m_top == m_head; 
    }

    char Pop() {
        char save = '\0'; 
        if (empty()) {
            std::cerr << "Stack underflow!" << std::endl;
        } else {
            Link* temp = m_top;
            save = temp->m_data;
            m_top = m_head; 
            Link* current = m_head->next;
            Link* previous = m_head;
            while (current != temp) {
                previous = current;
                current = current->next;
            }
            m_top = previous; 
            m_top->next = nullptr; 
            delete temp; 
        }
        return save;
    }
};

bool isCircle(char* Passage, Stack& stack, int length) {
    for (int i = 0; i < length; i++) {
        stack.Enstack(Passage[i]);
    }

    for (int i = 0; i < length; i++) {
        if (std::isalnum(Passage[i])) {
            char popped = stack.Pop();
            if (std::tolower(Passage[i]) != popped) { 
                return false;
            }
        }
    }

    return true;
}

int main() {
    char Passage[] = "was it a cat i saw ";
    int length = sizeof(Passage) / sizeof(Passage[0]) - 1; 

    Stack stack;
    if (isCircle(Passage, stack, length)) {
        std::cout << "yes." << std::endl;
    } else {
        std::cout << "no." << std::endl;
    }

    return 0;
}
