#include <math.h>
#include <stdio.h>
#include<time.h>

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{	
    
    FILE *file = fopen("C:/MyFiles/FILES/study/code/Daa/random.txt", "r");

    int n;
    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);
    
    clock_t end;
    clock_t start = clock(); 
    insertionSort(arr, n);
    printArray(arr, n);
    end = clock() - start;
    double time_taken = ((double) end) /CLOCKS_PER_SEC;
    printf("time taken:%f\n",time_taken);

    return 0;
}

