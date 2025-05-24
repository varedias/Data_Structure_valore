// #include <iostream>
// #define BLOCK_SIZE 6  
// #define BLOCK_NUM 3   
// #define TOTAL_SIZE 18 


// struct Index {
//     int maxKey;     
//     int startAddr;  
// };


// void blockSearch(int key, int* arr, Index* indexTable) {
//     int low = 0, high = BLOCK_NUM - 1, mid;
//     while (low <= high) {
//         mid = (low + high) / 2;
//         if (key <= indexTable[mid].maxKey) {//先通过最大值来确定这个数值可能在的位置
//             high = mid - 1;
//         } else {
//             low = mid + 1;
//         }
//     }
    
//     int blockId = high + 1;
//     if (blockId >= BLOCK_NUM) {//超出块的大小了所以肯定不存在
//         std::cout << "key " << key << " nonexist!" << std::endl;
//         return;
//     }
    
//     int start = indexTable[blockId].startAddr;
//     int end = (blockId == BLOCK_NUM-1) ? TOTAL_SIZE : indexTable[blockId+1].startAddr;//确定好位置
    
//     for(int i = start; i < end; i++) {
//         if(arr[i] == key) {
//             std::cout << "key " << key << " at " << blockId + 1 
//                       << " the location is : " << i << std::endl;
//             return;
//         }
//     }
//     std::cout << "key " << key << " nonexist!" << std::endl;
// }

// int main() {
    
//     int arr[] = {22,12,13,8,9,20,33,42,44,38,24,48,60,58,74,49,86,53};
    
    
//     Index indexTable[BLOCK_NUM];
    
    
//     for(int i = 0; i < BLOCK_NUM; i++) {
//         indexTable[i].startAddr = i * BLOCK_SIZE;
//         int maxVal = arr[i * BLOCK_SIZE];
//         for(int j = 0; j < BLOCK_SIZE && (i * BLOCK_SIZE + j) < TOTAL_SIZE; j++) {
//             if(arr[i * BLOCK_SIZE + j] > maxVal) {
//                 maxVal = arr[i * BLOCK_SIZE + j];//找出第i块中的最大值
//             }
//         }
//         indexTable[i].maxKey = maxVal;
//     }
    
    
//     blockSearch(42, arr, indexTable);
//     blockSearch(86, arr, indexTable);
//     blockSearch(100, arr, indexTable);
    
//     return 0;
// }
