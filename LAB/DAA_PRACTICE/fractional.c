#include <stdio.h>

void fractionalKnapsack(int n, int weights[], int profits[], int capacity) {
    float totalProfit = 0.0;
    int remainingCapacity = capacity;

    // Sort items by profit-to-weight ratio in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((float)profits[i] / weights[i] < (float)profits[j] / weights[j]) {
                // Swap weights
                int tempWeight = weights[i];
                weights[i] = weights[j];
                weights[j] = tempWeight;

                // Swap profits
                int tempProfit = profits[i];
                profits[i] = profits[j];
                profits[j] = tempProfit;
            }
        }
    }

    // Fill the knapsack greedily
    for (int i = 0; i < n; i++) {
        if (remainingCapacity == 0) break;

        if (weights[i] <= remainingCapacity) {
            // Take the entire item
            totalProfit += profits[i];
            remainingCapacity -= weights[i];
        } else {
            // Take fractional part of the item
            totalProfit += profits[i] * ((float)remainingCapacity / weights[i]);
            break;
        }
    }

    printf("Maximum profit: %.2f\n", totalProfit);
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n], profits[n];

    printf("Enter the weight and profit of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d (Weight Profit): ", i + 1);
        scanf("%d %d", &weights[i], &profits[i]);
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    fractionalKnapsack(n, weights, profits, capacity);

    return 0;
}
