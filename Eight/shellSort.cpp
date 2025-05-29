// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// #include <vector>
// using namespace std;


// void shellSort(vector<int>& arr) {
//     int n = arr.size();
//     for (int gap = n / 2; gap > 0; gap /= 2) {
//         for (int i = gap; i < n; i++) {
//             int temp = arr[i];
//             int j;
//             for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
//                 arr[j] = arr[j - gap];
//             arr[j] = temp;
//         }
//     }
// }

// void printArray(const vector<int>& arr) {
//     for (int num : arr)
//         cout << num << " ";
//     cout << endl;
// }

// int main() {
//     srand(time(0));
//     int n = rand() % 101; 
//     vector<int> arr(n);
    
   
//     for (int i = 0; i < n; i++) {
//         arr[i] = rand() % 1000;
      
//         for (int j = 0; j < i; j++) {
//             if (arr[i] == arr[j]) {
//                 i--;
//                 break;
//             }
//         }
//     }
    
//     cout << "origianl: ";
//     printArray(arr);
    
    
//     vector<int> shellArr = arr;
//     shellSort(shellArr);
//     cout << "Shell sort: ";
//     printArray(shellArr);
   
    
//     return 0;
// }    