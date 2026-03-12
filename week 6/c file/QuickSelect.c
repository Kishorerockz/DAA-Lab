#include <stdio.h>

// 1. Helper function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// 2. Partition function (Required for Quick Select)
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// 3. Quick Select function
int quickSelect(int arr[], int low, int high, int k) {
    // If k is smaller than number of elements in array
    if (k > 0 && k <= high - low + 1) {
        
        // Now the compiler knows where to find partition()
        int index = partition(arr, low, high);

        // If index is same as k, we found the element
        if (index - low == k - 1)
            return arr[index];

        // If index is more, look in the left subarray
        if (index - low > k - 1)
            return quickSelect(arr, low, index - 1, k);

        // Else look in the right subarray
        return quickSelect(arr, index + 1, high, k - index + low - 1);
    }
    return -1;
}

int main() {
    // Printing your roll number
    printf("Roll No: CH.SC.U4CSE24222\n");
    printf("Algorithm: Quick Select\n--------------------------\n");

    int arr[] = {10, 4, 5, 8, 6, 11, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // We want to find the 3rd smallest element

    int result = quickSelect(arr, 0, n - 1, k);
    
    if (result != -1) {
        printf("The %drd smallest element is: %d\n", k, result);
    } else {
        printf("Invalid value for k\n");
    }
    
    return 0;
}
