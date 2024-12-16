#include <stdio.h>
void EXCHANGE(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}
void ROTATE_RIGHT(int p1[], int p2) {

    if (p2 > 0) {
        int last = p1[p2 - 1];  
        

        for (int i = p2 - 1; i > 0; i--) {
            EXCHANGE(&p1[i], &p1[i - 1]);
        }
        

        p1[0] = last;
    }
}

int main() {
    int n, p2;


    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int p1[n];
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p1[i]);
    }

    printf("Enter the number of elements to rotate: ");
    scanf("%d", &p2);

    ROTATE_RIGHT(p1, p2);

    printf("Rotated array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", p1[i]);
    }
    printf("\n");

    return 0;
}
