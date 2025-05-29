#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;    
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 

    
    if (left < n && arr[left] > arr[largest])
        largest = left;

    
    if (right < n && arr[right] > arr[largest])
        largest = right;

    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);


    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);


        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    srand(time(0));
    int n = rand() % 101; 
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                i--;
                break;
            }
        }
    }

    cout << "original: ";
    printArray(arr, n);

    
    heapSort(arr, n);

    cout << "heap_sort: ";
    printArray(arr, n);

 

    return 0;
}    