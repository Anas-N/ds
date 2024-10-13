#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // If current element is smaller than pivot
            i++;
            swap(&arr[i], &arr[j]); // Swap
        }
    }
    swap(&arr[i + 1], &arr[high]); // Place pivot in correct position
    return i + 1; // Return pivot index
}

// Function to implement quick sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index
        quickSort(arr, low, pi - 1); // Recursively sort before pivot
        quickSort(arr, pi + 1, high); // Recursively sort after pivot
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;

    // Input the number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input the elements
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform quick sort
    quickSort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}