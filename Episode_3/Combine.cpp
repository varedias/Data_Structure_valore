#include <iostream>

class Stack {
private:
    int m_top;
    int m_capacity;
public:
    int* m_value;
    Stack() {}
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

    int peek() {
        if (!empty())
            return m_value[m_top];
        return -1;
    }

    int GetCapacity() {
        return m_capacity;
    }

    int GetTop() {
        return m_top;
    }
};

//由于栈遵循先进后出，所以要给他倒置
void ReverseStack(Stack& stack) {
    Stack temp(stack.GetCapacity());
    while (!stack.empty()) {
        temp.push(stack.pop());
    }
    stack = temp;
}

Stack* Combine(Stack& stack1, Stack& stack2) {

    ReverseStack(stack1);
    ReverseStack(stack2);

    Stack* NewStack = new Stack(stack1.GetCapacity() + stack2.GetCapacity());

    while (!stack1.empty() || !stack2.empty()) {
        if (!stack1.empty() && !stack2.empty()) {
            if (stack1.peek() < stack2.peek()) {
                NewStack->push(stack1.pop());
            } else {
                NewStack->push(stack2.pop());
            }
        } else if (!stack1.empty()) {
            NewStack->push(stack1.pop());
        } else {
            NewStack->push(stack2.pop());
        }
    }


    ReverseStack(*NewStack);

    return NewStack;
}

int main() {
    Stack stack1(5);
    Stack stack2(5);

    stack1.push(1);
    stack1.push(3);
    stack1.push(5);
    stack1.push(7);
    stack1.push(9);

    stack2.push(2);
    stack2.push(4);
    stack2.push(6);
    stack2.push(8);
    stack2.push(10);

    std::cout << "Before combining:" << std::endl;
    std::cout << "Stack1: ";
    for (int i = stack1.GetTop(); i >= 0; i--) {
        std::cout << stack1.m_value[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Stack2: ";
    for (int i = stack2.GetTop(); i >= 0; i--) {
        std::cout << stack2.m_value[i] << " ";
    }
    std::cout << std::endl;

    Stack* combinedStack = Combine(stack1, stack2);

    std::cout << "After combining:" << std::endl;
    while (!combinedStack->empty()) {
        std::cout << combinedStack->pop() << " ";
    }
    std::cout << std::endl;

    delete combinedStack;

    return 0;
}