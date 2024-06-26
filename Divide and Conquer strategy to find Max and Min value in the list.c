#include <stdio.h>

typedef struct {
    int min;
    int max;
} Pair;

Pair findMinMax(int arr[], int low, int high) {
    Pair minmax, leftMinMax, rightMinMax;
    int mid;

    if (low == high) {
        minmax.max = arr[low];
        minmax.min = arr[low];
        return minmax;
    }

    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            minmax.max = arr[low];
            minmax.min = arr[high];
        } else {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        return minmax;
    }

    mid = (low + high) / 2;
    leftMinMax = findMinMax(arr, low, mid);
    rightMinMax = findMinMax(arr, mid + 1, high);

    if (leftMinMax.min < rightMinMax.min) {
        minmax.min = leftMinMax.min;
    } else {
        minmax.min = rightMinMax.min;
    }

    if (leftMinMax.max > rightMinMax.max) {
        minmax.max = leftMinMax.max;
    } else {
        minmax.max = rightMinMax.max;
    }

    return minmax;
}

int main() {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    Pair minmax = findMinMax(arr, 0, arr_size - 1);

    printf("Minimum element is %d\n", minmax.min);
    printf("Maximum element is %d\n", minmax.max);

    return 0;
}
