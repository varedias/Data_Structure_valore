#include <iostream>

void ChangeOd(int * Arr, int n) {
    int left = 0;
    int right = n - 1;
    int temp;

    while (left < right) {
        while (left < right && Arr[left] % 2 != 0) {
            left++;
        }
        while (left < right && Arr[right] % 2 == 0) {
            right--;
        }
        if (left < right) {
            temp = Arr[left];
            Arr[left] = Arr[right];
            Arr[right] = temp;
            left++;
            right--;
        }
    }
}

int main() {
    int arr[] = {2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    ChangeOd(arr, n);

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
