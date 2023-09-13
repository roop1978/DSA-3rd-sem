#include <stdio.h>

// Recursive Binary Search
int binarySearch(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1; // Element not found
    }

    int mid = (low + high) / 2;

    if (arr[mid] == target) {
        return mid; // Element found at index 'mid'
    } else if (arr[mid] < target) {
        return binarySearch(arr, mid + 1, high, target); // Search in the right half
    } else {
        return binarySearch(arr, low, mid - 1, target); // Search in the left half
    }
}

// Recursive Selection Sort
void selectionSort(int arr[], int n, int index) {
    if (index == n - 1) {
        return; // Base case: array is sorted
    }

    int minIndex = index;
    for (int i = index + 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i; // Find the index of the minimum element
        }
    }

    // Swap the minimum element with the current element
    int temp = arr[index];
    arr[index] = arr[minIndex];
    arr[minIndex] = temp;

    // Recursive call to sort the remaining elements
    selectionSort(arr, n, index + 1);
}

// Recursive Multiplication using Repeated Addition
int multiply(int a, int b) {
    if (b == 0) {
        return 0; // Base case: anything multiplied by 0 is 0
    }

    if (b > 0) {
        return a + multiply(a, b - 1); // Repeated addition
    } else {
        return -multiply(a, -b); // Handle negative 'b'
    }
}

int main() {
    // Binary Search
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int index = binarySearch(arr, 0, n - 1, target);
    if (index != -1) {
        printf("Element %d found at index %d\n", target, index);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    // Selection Sort
    int selectionArr[] = {64, 34, 25, 12, 22, 11, 90};
    int selectionSize = sizeof(selectionArr) / sizeof(selectionArr[0]);
    selectionSort(selectionArr, selectionSize, 0);
    printf("Sorted array using selection sort: ");
    for (int i = 0; i < selectionSize; i++) {
        printf("%d ", selectionArr[i]);
    }
    printf("\n");

    // Multiplication using Repeated Addition
    int num1 = 7;
    int num2 = 5;
    int result = multiply(num1, num2);
    printf("Multiplication of %d and %d is %d\n", num1, num2, result);

    return 0;
}
