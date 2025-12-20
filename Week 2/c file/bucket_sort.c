#include <stdio.h>
#include <stdlib.h>

void insertionSort(float bucket[], int n) {
    int i, j;
    float key;

    for (i = 1; i < n; i++) {
        key = bucket[i];
        j = i - 1;

        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

int main() {
    int n, i, j;
    float arr[100];
    float bucket[10][100];
    int count[10] = {0};

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements (0 to 1 range):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        int index = n * arr[i];
        bucket[index][count[index]++] = arr[i];
    }

    for (i = 0; i < n; i++) {
        insertionSort(bucket[i], count[i]);
    }

    j = 0;
    for (i = 0; i < n; i++) {
        for (int k = 0; k < count[i]; k++) {
            arr[j++] = bucket[i][k];
        }
    }

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    return 0;
}

