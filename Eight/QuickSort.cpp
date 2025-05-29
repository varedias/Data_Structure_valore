// #include <iostream>
// #include <cstdlib>
// #include <ctime>

// int partition(int* arr, int low, int high) {
//     int pivot = arr[high];
//     int i = low - 1;
    
//     for (int j = low; j < high; j++) {
//         if (arr[j] < pivot) {
//             i++;
//             std::swap(arr[i], arr[j]);
//         }
//     }
//     std::swap(arr[i + 1], arr[high]);
//     return i + 1;
// }

// void quickSort(int* arr, int low, int high) {
//     if (low < high) {
//         int pi = partition(arr, low, high);
        
//         quickSort(arr, low, pi - 1);
//         quickSort(arr, pi + 1, high);
//     }
// }

// void QuickSort(int* arr, int n) {
//     quickSort(arr, 0, n - 1);
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

    
//     QuickSort(arr, n);

    
//     std::cout << "after: ";
//     for (int i = 0; i < n; i++) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;


//     return 0;
// }    