#include <stdio.h>
#include <stdlib.h>

int countDuplicates(int arr[], int n) {
    int count = 0;
    int *visited = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        if (visited[i] == 1) {
            continue;
        }
        int found_duplicate = 0;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                found_duplicate = 1;
                visited[j] = 1;
            }
        }
        if (found_duplicate) {
            count++;
        }
    }

    free(visited);
    return count;
}

int mostRepeatingElement(int arr[], int n) {
    int max_count = 0, element = -1;

    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            element = arr[i];
        }
    }

    return element;
}

int main() {
    const char *file_path = "openfor3.txt";
    FILE *file = fopen(file_path, "r");

    int n;
    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &n);


    int arr[n];
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);

    printf("The content of the array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int total_duplicates = countDuplicates(arr, n);
    int most_repeating = mostRepeatingElement(arr, n);

    printf("Total number of duplicate values = %d\n", total_duplicates);
    printf("The most repeating element in the array = %d\n", most_repeating);

    return 0;
}
