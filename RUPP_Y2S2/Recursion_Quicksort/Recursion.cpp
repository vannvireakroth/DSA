#include <iostream>
using namespace std;

// Recursive Binary Search Function
int binarySearch(int arr[], int left, int right, int target) {
    if (left > right)
        return -1; // Element not found

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid; // Element found

    if (target < arr[mid])
        return binarySearch(arr, left, mid - 1, target);

    return binarySearch(arr, mid + 1, right, target);
}

int main() {
    int arr[] = {5, 10, 15, 20, 25, 30, 35, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target;

    cout << "Enter the number to search: ";
    cin >> target;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}