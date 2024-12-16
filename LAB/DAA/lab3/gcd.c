#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    char *sourceFile = argv[1];
    char *destinationFile = argv[2];

    FILE *src = fopen(sourceFile, "r");
    if (src == NULL) {
        perror("Error opening source file");
        return 1;
    }

    FILE *dest = fopen(destinationFile, "w");
    if (dest == NULL) {
        perror("Error opening destination file");
        fclose(src);
        return 1;
    }

    int num1, num2;
    int pairCount = 0;

    while (fscanf(src, "%d %d", &num1, &num2) == 2) {
        int result = gcd(num1, num2);
        fprintf(dest, "GCD of %d and %d is %d\n", num1, num2, result);
        pairCount++;
    }

    if (pairCount < 20) {
        printf("Error: Source file must contain at least 20 pairs of numbers\n");
        fclose(src);
        fclose(dest);
        return 1;
    }

    fclose(src);
    fclose(dest);

    printf("GCD results have been written to %s\n", destinationFile);
    return 0;
}
