#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        // Change the comparison to '<=' to partition for the kth largest
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);
        int count = pivotIndex - low + 1;

        if (count == k) {
            return arr[pivotIndex];
        } else if (count > k) {
            return quickSelect(arr, low, pivotIndex - 1, k);
        } else {
            return quickSelect(arr, pivotIndex + 1, high, k - count);
        }
    }

    return -1;
}

int findKthLargest(int arr[], int size, int k) {
    if (k > 0 && k <= size) {
        return quickSelect(arr, 0, size - 1, size - k + 1);  // Adjust k to find the kth largest
    }
    return -1;
}

int main() {
    // Open the file for reading
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read the size of the array
    int size;
    fscanf(file, "%d", &size);

    // Read the elements of the array
    int arr[size];
    for (int i = 0; i < size; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);  // Close the file

    // Ask the user for the value of k
    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);

    int result = findKthLargest(arr, size, k);
    if (result != -1) {
        printf("The %dth largest element is %d\n", k, result);
    } else {
        printf("k is out of bounds\n");
    }

    return 0;
}
