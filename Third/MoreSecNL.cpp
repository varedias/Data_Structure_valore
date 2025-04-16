#include <iostream>
#include <cctype> 

class STACK {
private:
    char* m_data;
    int m_top;
public:
    int m_capacity; 
    STACK(int capacity = 100) : m_capacity(capacity), m_top(-1) {
        m_data = new char[m_capacity]; 
    }


    void EnStack(char value) {
        if (m_top >= m_capacity - 1) {
            std::cerr << "Stack overflow!" << std::endl;
            return;
        }
        m_data[++m_top] = value;
    }

    char Pop() {
        if (m_top < 0) {
            std::cerr << "Stack underflow!" << std::endl;
            return -1; 
        }
        return m_data[m_top--];
    }

    bool empty() {
        return m_top == -1;
    }
};

bool isCircle(char* Passage, STACK& stack, int length) {
    for (int i = 0; i < length; i++) {
        char c = Passage[i];
        if (std::isalnum(c)) { 
            stack.EnStack(std::tolower(c)); 
        }
    }

    for (int i = 0; i < length; i++) {
        char c = Passage[i];
        if (std::isalnum(c)) { 
            char popped = stack.Pop();
            if (std::tolower(c) != popped) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    char Passage[] = "was it a cat i saw ";
    int length = sizeof(Passage) / sizeof(Passage[0]) - 1; 

    STACK stack;
    if (isCircle(Passage, stack, length)) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    return 0;
}
