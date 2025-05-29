// #include <iostream>
// #include <cstdlib>
// #include <ctime>

// void BubbleSort(int* arr, int n) {
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j < n - i - 1; j++) {
//             if (arr[j] > arr[j + 1]) {
//                 std::swap(arr[j], arr[j + 1]);
//             }
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

//     BubbleSort(arr, n);

    
//     std::cout << "after: ";
//     for (int i = 0; i < n; i++) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;


//     return 0;
// }    