#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 500

int comparisons = 0;
int isWorstCase = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pivot element is the last element
    int i = (low - 1);  // Index of smaller element
    
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        // Determine if the current partitioning is worst-case
        if (pi - low <= 1 || high - pi <= 1) {
            isWorstCase = 1;
        }

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
            strcpy(outputFilename, "outQuickAsce.dat");
            break;
        case 2:
            strcpy(inputFilename, "inDesc.dat");
            strcpy(outputFilename, "outQuickDesc.dat");
            break;
        case 3:
            strcpy(inputFilename, "inRand.dat");
            strcpy(outputFilename, "outQuickRand.dat");
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
    isWorstCase = 0; // Reset worst-case flag
    quickSort(arr, 0, size - 1);

    clock_t end_time = clock();
    double executionTime = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    writeArrayToFile(outputFilename, arr, size);

    printf("After Sorting: Content of the output file\n");
    printArray(arr, size);

    printf("Number of Comparisons: %d\n", comparisons);
    if (isWorstCase) {
        printf("Partitioning Scenario: Worst-case\n");
    } else {
        printf("Partitioning Scenario: Best-case\n");
    }
    printf("Execution Time: %.6f seconds\n", executionTime);
}

int main() {
    int option;

    while (1) {
        printf("MAIN MENU (QUICK SORT)\n");
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

