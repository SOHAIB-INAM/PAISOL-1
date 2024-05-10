#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int kthSmallest(int arr[], int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int pivotIndex = partition(arr, low, high);
        if (pivotIndex - low == k - 1)
            return arr[pivotIndex];
        else if (pivotIndex - low > k - 1)
            return kthSmallest(arr, low, pivotIndex - 1, k);
        else
            return kthSmallest(arr, pivotIndex + 1, high, k - pivotIndex + low - 1);
    }
    return -1;}

int main() {
    int arr[] = {12, 3, 5, 7, 19};
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 2;

    int result = kthSmallest(arr, 0, N - 1, K);
    if (result != -1)
        cout << "K'th smallest element is " << result;
    else
        cout << "Invalid value of k";
    return 0;
}
