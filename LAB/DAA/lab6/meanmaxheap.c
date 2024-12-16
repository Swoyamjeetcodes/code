#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    int id;
    char *name;
    int age;
    int height;  // in cm
    int weight;  // in pounds
};

void readData(struct person **people, int *n);
void createMinHeap(struct person *people, int n);
void createMaxHeap(struct person *people, int n);
void displayYoungestWeight(struct person *people, int n);
void insertMinHeap(struct person **people, int *n, struct person newPerson);
void deleteOldestPerson(struct person *people, int *n);
void heapifyMin(struct person *people, int n, int i);
void heapifyMax(struct person *people, int n, int i);
void swap(struct person *a, struct person *b);
void printPeople(struct person *people, int n);

int main() {
    struct person *people = NULL;
    int n = 0;
    int choice;
    
    do {
        printf("\nMAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                readData(&people, &n);
                break;
            case 2:
                createMinHeap(people, n);
                break;
            case 3:
                createMaxHeap(people, n);
                break;
            case 4:
                displayYoungestWeight(people, n);
                break;
            case 5: {
                struct person newPerson;
                newPerson.name = (char *)malloc(100 * sizeof(char));
                printf("Enter ID: ");
                scanf("%d", &newPerson.id);
                printf("Enter Name: ");
                scanf("%s", newPerson.name);
                printf("Enter Age: ");
                scanf("%d", &newPerson.age);
                printf("Enter Height (cm): ");
                scanf("%d", &newPerson.height);
                printf("Enter Weight (pounds): ");
                scanf("%d", &newPerson.weight);
                insertMinHeap(&people, &n, newPerson);
                break;
            }
            case 6:
                deleteOldestPerson(people, &n);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 7);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(people[i].name);
    }
    free(people);

    return 0;
}

void readData(struct person **people, int *n) {
    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fscanf(file, "%d", n);
    *people = (struct person *)malloc(*n * sizeof(struct person));

    for (int i = 0; i < *n; i++) {
        (*people)[i].name = (char *)malloc(100 * sizeof(char));
        fscanf(file, "%d %s %d %d %d", &(*people)[i].id, (*people)[i].name, &(*people)[i].age, &(*people)[i].height, &(*people)[i].weight);
    }

    fclose(file);
    printf("Data read successfully!\n");
}

void createMinHeap(struct person *people, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyMin(people, n, i);
    }
    printf("Min-heap created based on age!\n");
}

void createMaxHeap(struct person *people, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyMax(people, n, i);
    }
    printf("Max-heap created based on weight!\n");
}

void displayYoungestWeight(struct person *people, int n) {
    if (n == 0) {
        printf("No data available!\n");
        return;
    }

    int minAgeIndex = 0;
    for (int i = 1; i < n; i++) {
        if (people[i].age < people[minAgeIndex].age) {
            minAgeIndex = i;
        }
    }

    double weightInKg = people[minAgeIndex].weight * 0.453592; // Convert pounds to kg
    printf("Weight of youngest student: %.2f kg\n", weightInKg);
}

void insertMinHeap(struct person **people, int *n, struct person newPerson) {
    *people = realloc(*people, (*n + 1) * sizeof(struct person));
    (*people)[*n] = newPerson;
    (*n)++;
    
    int i = *n - 1;
    while (i > 0 && (*people)[(i - 1) / 2].age > (*people)[i].age) {
        swap(&(*people)[i], &(*people)[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    printf("New person inserted into Min-heap!\n");
}

void deleteOldestPerson(struct person *people, int *n) {
    if (*n == 0) {
        printf("Heap is empty!\n");
        return;
    }

    // Find the oldest person
    int oldestIndex = 0;
    for (int i = 1; i < *n; i++) {
        if (people[i].age > people[oldestIndex].age) {
            oldestIndex = i;
        }
    }

    // Swap the oldest person with the last person
    swap(&people[oldestIndex], &people[*n - 1]);
    (*n)--;

    // Restore heap properties (Min-heap)
    heapifyMin(people, *n, oldestIndex);
    printf("Oldest person deleted from the Min-heap!\n");
}

void heapifyMin(struct person *people, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && people[left].age < people[smallest].age)
        smallest = left;

    if (right < n && people[right].age < people[smallest].age)
        smallest = right;

    if (smallest != i) {
        swap(&people[i], &people[smallest]);
        heapifyMin(people, n, smallest);
    }
}

void heapifyMax(struct person *people, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && people[left].weight > people[largest].weight)
        largest = left;

    if (right < n && people[right].weight > people[largest].weight)
        largest = right;

    if (largest != i) {
        swap(&people[i], &people[largest]);
        heapifyMax(people, n, largest);
    }
}

void swap(struct person *a, struct person *b) {
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

void printPeople(struct person *people, int n) {
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Age: %d, Height: %d cm, Weight: %d lbs\n",
               people[i].id, people[i].name, people[i].age, people[i].height, people[i].weight);
    }
}