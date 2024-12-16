#include <stdio.h>
#include <stdlib.h>

// Structure for items
struct ITEM {
    int item_id;
    float item_profit;
    float item_weight;
    float profit_weight_ratio;
};

// Function to swap two items
void swap(struct ITEM *a, struct ITEM *b) {
    struct ITEM temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function for max heap based on profit/weight ratio
void heapify(struct ITEM arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = left;
    if (right < n && arr[right].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort on items based on profit/weight ratio
void heapSort(struct ITEM arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Function to perform the fractional knapsack algorithm
void fractionalKnapsack(struct ITEM items[], int n, float capacity) {
    heapSort(items, n); // Sort items based on profit/weight ratio in non-increasing order

    float totalProfit = 0.0;
    printf("Item No\tProfit\t\tWeight\t\tAmount to be taken\n");

    for (int i = n - 1; i >= 0; i--) {
        if (items[i].item_weight <= capacity) {
            totalProfit += items[i].item_profit;
            capacity -= items[i].item_weight;
            printf("%d\t%.6f\t%.6f\t1.000000\n", items[i].item_id, items[i].item_profit, items[i].item_weight);
        } else {
            float fraction = capacity / items[i].item_weight;
            totalProfit += items[i].item_profit * fraction;
            printf("%d\t%.6f\t%.6f\t%.6f\n", items[i].item_id, items[i].item_profit, items[i].item_weight, fraction);
            break;
        }
    }

    printf("Maximum profit: %.6f\n", totalProfit);
}

int main() {
    int n;
    float capacity;

    // Input number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Dynamically allocate memory for items
    struct ITEM *items = (struct ITEM *)malloc(n * sizeof(struct ITEM));

    // Input item details
    for (int i = 0; i < n; i++) {
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%f %f", &items[i].item_profit, &items[i].item_weight);
        items[i].item_id = i + 1;
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }

    // Input knapsack capacity
    printf("Enter the capacity of knapsack: ");
    scanf("%f", &capacity);

    // Perform fractional knapsack algorithm
    fractionalKnapsack(items, n, capacity);

    // Free allocated memory
    free(items);

    return 0;
}