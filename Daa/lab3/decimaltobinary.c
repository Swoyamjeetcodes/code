#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int n, FILE *destFile) {
    if (n == 0) {
        fputc('0', destFile);
        return;
    } else if (n == 1) {
        fputc('1', destFile);
        return;
    }
    decimalToBinary(n / 2, destFile);
    fputc((n % 2) ? '1' : '0', destFile);
}

void convertAndStore(FILE *sourceFile, FILE *destFile, int count) {
    int number;
    for (int i = 0; i < count; ++i) {
        if (fscanf(sourceFile, "%d", &number) != 1) {
            fprintf(stderr, "Error reading number %d from source file\n", i + 1);
            exit(EXIT_FAILURE);
        }
        fprintf(destFile, "%d in binary: ", number);
        decimalToBinary(number, destFile);
        fputc('\n', destFile);
    }
}

void displayOutputFile(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <n> <source file> <destination file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int n = atoi(argv[1]);
    const char *sourceFileName = argv[2];
    const char *destFileName = argv[3];

    FILE *sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        fprintf(stderr, "Error opening source file %s\n", sourceFileName);
        return EXIT_FAILURE;
    }

    FILE *destFile = fopen(destFileName, "w");
    if (destFile == NULL) {
        fprintf(stderr, "Error opening destination file %s\n", destFileName);
        fclose(sourceFile);
        return EXIT_FAILURE;
    }

    convertAndStore(sourceFile, destFile, n);

    fclose(sourceFile);
    fclose(destFile);

    displayOutputFile(destFileName);

    return EXIT_SUCCESS;
}
