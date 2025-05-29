// #include <iostream>
// #include <cstdlib>
// #include <ctime>

// void DirectInsertSort(int* arr, int n) {
//     for (int i = 1; i < n; i++) {
//         int temp = arr[i];
//         int j = i - 1;
        
//         while (j >= 0 && arr[j] > temp) {
//             arr[j + 1] = arr[j];
//             j--;
//         }
        
//         arr[j + 1] = temp;
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

    
//     DirectInsertSort(arr, n);

    
//     std::cout << "after: ";
//     for (int i = 0; i < n; i++) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;


//     return 0;
// }    