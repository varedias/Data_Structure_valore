// #include <iostream>
// #include <cstdlib>
// #include <ctime>

// void SelectionSort(int* arr, int n) {
//     for (int i = 0; i < n - 1; i++) {
//         int minIndex = i;
//         for (int j = i + 1; j < n; j++) {
//             if (arr[j] < arr[minIndex]) {
//                 minIndex = j;
//             }
//         }
//         if (minIndex != i) {
//             std::swap(arr[i], arr[minIndex]);
//         }
//     }
// }

// int main() {
//     std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
//     int n = 100; 
//     int* arr = new int[n];
    
//     for (int i = 0; i < n; i++) {
//         arr[i] = std::rand() % 1000; 
//     }

//     std::cout << "before: ";
//     for (int i = 0; i < n; i++) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;

    
//     SelectionSort(arr, n);

    
//     std::cout << "after: ";
//     for (int i = 0; i < n; i++) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }    