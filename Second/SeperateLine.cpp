#include <iostream>

struct Result {
    int *A;
    int LengthA;
    int *B;
    int LengthB;

    Result() : A(nullptr), LengthA(0), B(nullptr), LengthB(0) {}

    ~Result() {
        delete[] A;
        delete[] B;
    }
};

Result Seperate(int *Ori, int &length) {
    Result save;
    save.A = new int[length];
    save.B = new int[length];

    for (int i = 0; i < length; i++) {
        if (Ori[i] > 0) {
            save.A[save.LengthA] = Ori[i];
            save.LengthA++;
        } else if (Ori[i] < 0) {
            save.B[save.LengthB] = Ori[i];
            save.LengthB++;
        }
    }
    return save;
}

int main() {
    int length = 6;
    int a[6] = {1, -1, 2, -2, 3, -3};
    Result New = Seperate(a, length);

    std::cout << "Positive :" << std::endl;
    for (int i = 0; i < New.LengthA; i++) {
        std::cout << New.A[i] << std::endl;
    }

    std::cout << "Negative :" << std::endl;
    for (int i = 0; i < New.LengthB; i++) {
        std::cout << New.B[i] << std::endl;
    }

    return 0;
}
