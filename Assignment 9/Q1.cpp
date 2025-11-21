#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i, bool maxHeap) {
    int left = 2*i + 1;
    int right = 2*i + 2;
    int extreme = i;

    if (maxHeap) {
        if (left < n && arr[left] > arr[extreme])
            extreme = left;
        if (right < n && arr[right] > arr[extreme])
            extreme = right;
    }
    else {
        if (left < n && arr[left] < arr[extreme])
            extreme = left;
        if (right < n && arr[right] < arr[extreme])
            extreme = right;
    }
    if (extreme != i) {
        swap(arr[i], arr[extreme]);
        heapify(arr, n, extreme, maxHeap);
    }
}
void buildHeap(int arr[], int n, bool maxHeap) {
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i, maxHeap);
    }
}
void heapSort(int arr[], int n, bool increasing) {

    buildHeap(arr, n, increasing);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, increasing);
    }

}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    int arr[] = {12, 3, 19, 7, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    printArray(arr, n);
    heapSort(arr, n, true);
    cout << "Sorted Increasing (Ascending): ";
    printArray(arr, n);
    int arr2[] = {12, 3, 19, 7, 2, 25};
    heapSort(arr2, n, false);
    cout << "Sorted Decreasing (Descending): ";
    printArray(arr2, n);
    return 0;
}
