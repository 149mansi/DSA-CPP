// merge sort code
#include<iostream>
using namespace std;

void merge(int* arr, int s, int e) {
    int mid = (s + e) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    // Create arrays for len1 and len2 length
    int* left = new int[len1];
    int* right = new int[len2];

    // Copy values
    int k = s;
    for (int i = 0; i < len1; i++) {
        left[i] = arr[k];
        k++;
    }
    k = mid + 1;
    for (int i = 0; i < len2; i++) {
        right[i] = arr[k];
        k++;
    }

    // Merge logic
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;
    while (leftIndex < len1 && rightIndex < len2) {
        if (left[leftIndex] < right[rightIndex]) {
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        } else {
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }

    // Copy remaining elements from left array, if any
    while (leftIndex < len1) {
        arr[mainArrayIndex++] = left[leftIndex++];
    }

    // Copy remaining elements from right array, if any
    while (rightIndex < len2) { // corrected from len1 to len2
        arr[mainArrayIndex++] = right[rightIndex++];
    }

    // Free the dynamically allocated memory
    delete[] left;
    delete[] right;
}

void mergeSort(int* arr, int s, int e) {
    // Base case: s==e If single element or   s>e invalid range
    if (s >= e)
        return;

    int mid = (s + e) / 2;
    // Recursively sort left part sort 
    mergeSort(arr, s, mid);
    // // Recursively sort right part sort 
    mergeSort(arr, mid + 1, e);

    // Merge the sorted halves
    merge(arr, s, e);
}

int main() {
    int arr[] = {4, 5, 13, 2, 12};
    int n = 5;
    int s = 0;
    int e = n - 1;
    mergeSort(arr, s, e);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
