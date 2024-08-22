#include <stdio.h>
#include <stdlib.h>

int main() {
    //const char *file_path = "openit.txt";
    FILE *file = fopen("/home/kiit/22053733/lab2/openit.txt", "r");

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
    return 0;}
