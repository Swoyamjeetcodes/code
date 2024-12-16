// C program for the implementation of merge sort
#include <stdio.h>
#include <stdlib.h>

// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void merge(int arr[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = 0;
    int temp[high-low+1];
    while (i <= mid && j <= high) {
        if (arr[i]<arr[j]) {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    // Copy the remaining elements of leftArr[], if any
    while (i <= mid) {
        temp[k++] = arr[i];
        i++;
    }
    // Copy the remaining elements of rightArr[], if any
    while (j <= high) {
        temp[k++] = arr[j];
        j++;
    }
    for (i = low, k = 0; i <= high; i++, k++) {
        arr[i] = temp[k];
    }
}

// The subarray to be sorted is in the index range [left-right]
void mergeSort(int arr[], int low, int high) {
    if (low< high) {
      
        // Calculate the midpoint
        int mid = low + (high - low) / 2;

        // Sort first and second halves
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // Merge the sorted halves
        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    
      // Sorting arr using mergesort
    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
