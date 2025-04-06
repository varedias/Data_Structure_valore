#include <iostream>



void FindMaxMin(int* Arr, int left, int right, int &MAX, int &MIN) {
        if ((right - left) == 1) {
        if (Arr[right] > Arr[left]) {
            MAX = Arr[right];
            MIN = Arr[left];
        } else {
            MAX = Arr[left];
            MIN = Arr[right];
        }
    } else {
        int mid = (left + right) / 2;
        int leftMax, leftMin, rightMax, rightMin;

     
        FindMaxMin(Arr, left, mid, leftMax, leftMin);
        FindMaxMin(Arr, mid + 1, right, rightMax, rightMin);

        MAX = (leftMax > rightMax) ? leftMax : rightMax;
        MIN = (leftMin < rightMin) ? leftMin : rightMin;
    }
}


int main()
{
    int Arr[8] = {3, 5, 1, 8, 4, 2, 7, 6};
    int MAX, MIN;

    FindMaxMin(Arr, 0, 7, MAX, MIN);

    std::cout << "MAX: " << MAX << std::endl;
    std::cout << "MIN: " << MIN << std::endl;

    return 0;
}
