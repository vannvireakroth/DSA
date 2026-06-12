#include <iostream>
using namespace std;

// Insertion Sort for small subarrays
void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Median-of-Three pivot selection
int medianOfThree(int arr[], int left, int right) {
    int mid = (left + right) / 2;

    if (arr[left] > arr[mid])
        swap(arr[left], arr[mid]);

    if (arr[left] > arr[right])
        swap(arr[left], arr[right]);

    if (arr[mid] > arr[right])
        swap(arr[mid], arr[right]);

    // Move pivot to right - 1
    swap(arr[mid], arr[right - 1]);

    return arr[right - 1];
}

// QuickSort function
void quickSort(int arr[], int left, int right) {

    // Use insertion sort if subarray has 2 or 3 elements
    if (right - left + 1 <= 3) {
        insertionSort(arr, left, right);
        return;
    }

    int pivot = medianOfThree(arr, left, right);

    int i = left;
    int j = right - 1;

    while (true) {
        while (arr[++i] < pivot);
        while (arr[--j] > pivot);

        if (i < j)
            swap(arr[i], arr[j]);
        else
            break;
    }

    swap(arr[i], arr[right - 1]);

    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}

int main() {
    int arr[] = {25, 10, 30, 15, 5, 20, 35, 40, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}