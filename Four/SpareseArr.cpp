#include <iostream>
#include <vector>

struct Triple {
    int row;
    int col;
    int value;
    Triple(int Rows, int COls, int Values) : row(Rows), col(COls), value(Values) {}
};


std::vector<Triple> ChangeIntoTriByRow(int * Matrix, int row, int col) {
    std::vector<Triple> triples;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (Matrix[i * col + j] != 0) {
                Triple temp(i, j, Matrix[i * col + j]);
                triples.push_back(temp);
            }
        }
    }
    return triples;
}


std::vector<Triple> Additionm(std::vector<Triple>& first, std::vector<Triple>& second) {
    std::vector<Triple> result;
    int i = 0, j = 0;
    while (i < first.size() && j < second.size()) {
        if (first[i].row == second[j].row && first[i].col == second[j].col) {
            int sum = first[i].value + second[j].value;
            if (sum != 0) {
                result.push_back(Triple(first[i].row, first[i].col, sum));
            }
            i++;
            j++;
        } else if (first[i].row < second[j].row || (first[i].row == second[j].row && first[i].col < second[j].col)) {
            result.push_back(first[i]);
            i++;
        } else {
            result.push_back(second[j]);
            j++;
        }
    }

 
    while (i < first.size()) {
        result.push_back(first[i]);
        i++;
    }

    while (j < second.size()) {
        result.push_back(second[j]);
        j++;
    }

    return result;
}


std::vector<Triple> Subtract(std::vector<Triple>& first, std::vector<Triple>& second) {
    std::vector<Triple> result;
    int i = 0, j = 0;
    while (i < first.size() && j < second.size()) {
        if (first[i].row == second[j].row && first[i].col == second[j].col) {
            int sub = first[i].value - second[j].value;
            if (sub != 0) {
                result.push_back(Triple(first[i].row, first[i].col, sub));
            }
            i++;
            j++;
        } else if (first[i].row < second[j].row || (first[i].row == second[j].row && first[i].col < second[j].col)) {
            result.push_back(first[i]);
            i++;
        } else {
            result.push_back(Triple(second[j].row, second[j].col, -second[j].value));
            j++;
        }
    }

 
    while (i < first.size()) {
        result.push_back(first[i]);
        i++;
    }

    while (j < second.size()) {
        result.push_back(Triple(second[j].row, second[j].col, -second[j].value));
        j++;
    }

    return result;
}


std::vector<Triple> Multiple(std::vector<Triple>& first, std::vector<Triple>& second, int firstRows, int firstCols, int secondRows, int secondCols) {
    std::vector<Triple> result;
    if (firstCols != secondRows) {
        std::cerr << "Error former." << std::endl;
        return result;
    }

    std::vector<std::vector<int>> sumMatrix(firstRows, std::vector<int>(secondCols, 0));

    for (const auto& t1 : first) {
        for (const auto& t2 : second) {
            if (t1.col == t2.row) {
                sumMatrix[t1.row][t2.col] += t1.value * t2.value;
            }
        }
    }

    for (int i = 0; i < firstRows; i++) {
        for (int j = 0; j < secondCols; j++) {
            if (sumMatrix[i][j] != 0) {
                result.push_back(Triple(i, j, sumMatrix[i][j]));
            }
        }
    }

    return result;
}


void Print(const std::vector<Triple>& tri) {
    for (const auto& t : tri) {
        std::cout << t.row << " " << t.col << " " << t.value << std::endl;
    }
}

int main() {

    int matrix1[4][5] = {
        {0, 0, 3, 0, 0},
        {0, 0, 0, 4, 0},
        {5, 0, 0, 0, 6},
        {0, 7, 0, 0, 0}
    };

    int matrix2[5][3] = {
        {1, 0, 0},
        {0, 2, 0},
        {0, 0, 0},
        {0, 0, 9},
        {0, 0, 8}
    };

    int firstRows = 4;
    int firstCols = 5;
    int secondRows = 5;
    int secondCols = 3;


    std::vector<Triple> sparseMatrix1 = ChangeIntoTriByRow((int*)matrix1, firstRows, firstCols);
    std::vector<Triple> sparseMatrix2 = ChangeIntoTriByRow((int*)matrix2, secondRows, secondCols);

   
    std::cout << "Sparse Matrix 1:\n";
    Print(sparseMatrix1);

    std::cout << "\nSparse Matrix 2:\n";
    Print(sparseMatrix2);


    std::vector<Triple> additionResult = Additionm(sparseMatrix1, sparseMatrix2);


    std::cout << "\nAddition :\n";
    Print(additionResult);


    std::vector<Triple> subtractionResult = Subtract(sparseMatrix1, sparseMatrix2);

   
    std::cout << "\nSubtraction :\n";
    Print(subtractionResult);


    int matrix3[4][3] = {
        {0, 0, 3},
        {0, 4, 0},
        {5, 0, 0},
        {0, 7, 0}
    };

    int matrix4[3][5] = {
        {1, 0, 0, 0, 0},
        {0, 2, 0, 0, 0},
        {0, 0, 0, 9, 8}
    };

    int thirdRows = 4;
    int thirdCols = 3;
    int fourthRows = 3;
    int fourthCols = 5;


    std::vector<Triple> sparseMatrix3 = ChangeIntoTriByRow((int*)matrix3, thirdRows, thirdCols);
    std::vector<Triple> sparseMatrix4 = ChangeIntoTriByRow((int*)matrix4, fourthRows, fourthCols);


    std::cout << "\nSparse Matrix 3:\n";
    Print(sparseMatrix3);

    std::cout << "\nSparse Matrix 4:\n";
    Print(sparseMatrix4);


    std::vector<Triple> multiplicationResult = Multiple(sparseMatrix3, sparseMatrix4, thirdRows, thirdCols, fourthRows, fourthCols);


    std::cout << "\nMultiplication Resultant :\n";
    Print(multiplicationResult);

    return 0;
}
