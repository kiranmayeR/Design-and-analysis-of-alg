#include <stdio.h>

typedef struct {
    int weight;
    int value;
} Item;

void knapsack(Item items[], int n, int capacity) {
    int currentWeight = 0;
    float totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remain = capacity - currentWeight;
            totalValue += items[i].value * ((float) remain / items[i].weight);
            break;
        }
    }

    printf("Maximum value in Knapsack = %.2f\n", totalValue);
}

int main() {
    Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    knapsack(items, n, capacity);

    return 0;
}
