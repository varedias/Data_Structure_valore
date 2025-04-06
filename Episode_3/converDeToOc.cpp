#include <iostream>

class Stack {
private:
    int m_top;
    int m_capacity;
public:
    int* m_value;
    Stack(int value) {
        m_capacity = value;
        m_value = new int[value];
        m_top = -1;
    }



    bool empty() {
        return m_top == -1;
    }

    bool full() {
        return m_top + 1 == m_capacity;
    }

    void push(int value) {
        if (!full())
            m_value[++m_top] = value;
    }

    int pop() {
        if (!empty())
            return m_value[m_top--];
        return -1;
    }

    int GetCapacity() {
        return m_capacity;
    }
};

void Convert(int* A, int* B, int n) {
    for (int i = 0; i < n; i++) {
        int decimal = A[i];
        Stack stack(32); 
        if (decimal == 0) {
            stack.push(0);
        } else {
            while (decimal > 0) {
                stack.push(decimal % 8);
                decimal /= 8;
            }
        }


        B[i] = 0;
        int power = 1;
        while (!stack.empty()) {
            B[i] += stack.pop() * power;
            power *= 10;
        }
    }
}

int main() {
    int A[5] = {10, 20, 30, 40, 50};
    int B[5];

    Convert(A, B, 5);

    std::cout << "Original decimal numbers in A: ";
    for (int i = 0; i < 5; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Converted octal numbers in B: ";
    for (int i = 0; i < 5; i++) {
        std::cout << B[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
