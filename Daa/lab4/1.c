#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_SIZE 500

int comparisons = 0;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    
    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    int i = 0, j = 0;
    int k = l;
    
    while (i < n1 && j < n2) {
        comparisons++;
        
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
        
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k++] = L[i++];
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void readArrayFromFile(const char *filename, int arr[], int *size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (fscanf(file, "%d", &arr[i]) != EOF) {
        i++;
    }
    *size = i;

    fclose(file);
}

void writeArrayToFile(const char *filename, int arr[], int size) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);
}

void sortAndPrint(int option) {
    char inputFilename[20], outputFilename[20];
    int arr[MAX_SIZE], size;

    switch (option) {
        case 1:
            strcpy(inputFilename, "inAsce.dat");
            strcpy(outputFilename, "outMergeAsce.dat");
            break;
        case 2:
            strcpy(inputFilename, "inDesc.dat");
            strcpy(outputFilename, "outMergeDesc.dat");
            break;
        case 3:
            strcpy(inputFilename, "inRand.dat");
            strcpy(outputFilename, "outMergeRand.dat");
            break;
        default:
            printf("Invalid option.\n");
            return;
    }

    readArrayFromFile(inputFilename, arr, &size);
    
    printf("Before Sorting: Content of the input file\n");
    printArray(arr, size);

    clock_t start_time = clock();
    
    comparisons = 0; // Reset comparisons count
    mergeSort(arr, 0, size - 1);
    
    clock_t end_time = clock();
    
    double executionTime = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    writeArrayToFile(outputFilename, arr, size);

    printf("After Sorting: Content of the output file\n");
    printArray(arr, size);
    
    printf("Number of Comparisons: %d\n", comparisons);
    printf("Execution Time: %.6f seconds\n", executionTime);
}

int main() {
    int option;

    while (1) {
        printf("MAIN MENU (MERGE SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. ERROR (EXIT)\n");
        printf("Enter option: ");
        scanf("%d", &option);

        if (option == 4) {
            break;
        }

        sortAndPrint(option);
    }

    return 0;
}

