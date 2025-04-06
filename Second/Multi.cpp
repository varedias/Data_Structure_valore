#include <iostream>

typedef struct node {
    int exp;  
    float coef;  
    node* next;  
    node(int ex, float coe) : exp(ex), coef(coe), next(nullptr) {}
} ploynode;


void PrintPolynomial(ploynode* head) {
    while (head) {
        std::cout << head->coef << "x^" << head->exp;
        if (head->next) std::cout << " + ";
        head = head->next;
    }
    std::cout << std::endl;
}


ploynode* Sum(ploynode* A, ploynode* B) {
    ploynode* head = nullptr;  
    ploynode* tail = nullptr;  

    ploynode* temp1 = A;
    ploynode* temp2 = B;
    ploynode* Result = nullptr;

    while (temp1 || temp2) {
        if (temp1 && temp2) {
            if (temp1->exp == temp2->exp) {
                Result = new ploynode(temp1->exp, temp1->coef + temp2->coef);
                temp1 = temp1->next;
                temp2 = temp2->next;
            } else if (temp1->exp > temp2->exp) {
                Result = new ploynode(temp1->exp, temp1->coef);
                temp1 = temp1->next;
            } else {
                Result = new ploynode(temp2->exp, temp2->coef);
                temp2 = temp2->next;
            }
        }
         else if (temp1) {
            Result = new ploynode(temp1->exp, temp1->coef);
            temp1 = temp1->next;
        } else {
            Result = new ploynode(temp2->exp, temp2->coef);
            temp2 = temp2->next;
        }

        if (!head) {
            head = tail = Result;
        } else {
            tail->next = Result;
            tail = Result;
        }
    }

    return head;
}

int main() {
    //3x^2 + 2x + 1
    ploynode* A = new ploynode(2, 3);
    A->next = new ploynode(1, 2);
    A->next->next = new ploynode(0, 1);

    //  2x^2 + 4x + 5
    ploynode* B = new ploynode(2, 2);
    B->next = new ploynode(1, 4);
    B->next->next = new ploynode(0, 5);

    std::cout << "multi A: ";
    PrintPolynomial(A);

    std::cout << "multi B: ";
    PrintPolynomial(B);

    
    ploynode* C = Sum(A, B);

    std::cout << " A + B: ";
    PrintPolynomial(C);

    return 0;
}
