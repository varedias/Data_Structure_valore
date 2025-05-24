// #include <iostream>
// #include <algorithm>
// #define SIZE 100

// bool searchValue(int* arr, int key)
// {
//     std::sort(arr, arr + SIZE);
//     int begin = 0;
//     int end = SIZE - 1;

//     while(begin <= end)
//     {
//         int mid = begin + (end - begin) / 2;  
        
//         if(arr[mid] == key)
//         {
//             std::cout << "Found at position " << mid << std::endl;
//             return true;
//         }
//         else if(arr[mid] > key)
//         {
//             end = mid - 1;
//         }
//         else
//         {
//             begin = mid + 1;
//         }
//     }
//     std::cout << "Not found" << std::endl;
//     return false;
// }

// int main()
// {
//     int arr[SIZE];
//     for(int i = 0; i < SIZE; i++)
//     {
//         arr[i] = rand() % 100;
//     }
//   //  arr[60] = 50;
//     searchValue(arr, 50);
//     return 0;
// }
