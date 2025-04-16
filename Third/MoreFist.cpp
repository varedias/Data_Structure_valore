#include <iostream>

struct link {
    int m_data;
    link* next;
    link(): m_data(0), next(nullptr) {}
    link(int value): m_data(value), next(nullptr) {}
};

class STACK {
private:
    int* m_data;
    int m_top;
public:
    int m_capacity; 
    STACK(int capacity = 100) : m_capacity(capacity), m_top(-1) {
        m_data = new int[m_capacity]; 
    }
    void EnStack(int value) {
        if (m_top >= m_capacity - 1) {
            std::cerr << "Stack overflow!" << std::endl;
            return;
        }
        m_data[++m_top] = value;
    }

    int Pop() {
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

void Create(link*& head, link*& tail, int value) {
    link* temp = new link(value);
    if (tail == nullptr) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void Envalue(STACK& stack, link*& head) {
    link* temp = head;
    while (temp != nullptr) {
        stack.EnStack(temp->m_data);
        temp = temp->next;
    }
}

int* PopValue(STACK& stack, int& count) {
    count = 0;
    int* Arr = new int[stack.m_capacity]; 
    while (!stack.empty()) {
        Arr[count++] = stack.Pop();
    }
    return Arr;
}

int main() {
    link* head = nullptr;
    link* tail = nullptr;
    STACK stack;
    int* Save;
    int count = 0;

    Create(head, tail, 1);
    Create(head, tail, 20);
    Create(head, tail, 30);
    Create(head, tail, 4);

    Envalue(stack, head);

    Save = PopValue(stack, count);
    for (int i = 0; i < count; i++) {
        std::cout << Save[i] << std::endl;
    }
    return 0;
}
