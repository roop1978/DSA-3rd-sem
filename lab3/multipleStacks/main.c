#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Adjust the size as needed

int n;
int top[10]; // Assuming a maximum of 10 stacks

int arr[MAX_SIZE];

void initializeStacks() {
    printf("Enter the number of stacks: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        top[i] = -1;
    }
}

void push(int stackNum, int value) {
    if (stackNum < 0 || stackNum >= n) {
        printf("\nInvalid stack number");
        return;
    }

    if (top[stackNum] == MAX_SIZE - 1) {
        printf("\nStack %d overflow", stackNum);
        return;
    }

    int index = stackNum * (MAX_SIZE / n) + top[stackNum] + 1;
    arr[index] = value;
    top[stackNum]++;
}

int pop(int stackNum) {
    if (stackNum < 0 || stackNum >= n) {
        printf("\nInvalid stack number");
        return -1;
    }

    if (top[stackNum] == -1) {
        printf("\nStack %d underflow", stackNum);
        return -1;
    }

    int index = stackNum * (MAX_SIZE / n) + top[stackNum];
    int value = arr[index];
    top[stackNum]--;
    return value;
}

void displayStack(int stackNum) {
    if (stackNum < 0 || stackNum >= n) {
        printf("\nInvalid stack number");
        return;
    }

    printf("Stack %d: ", stackNum);
    if (top[stackNum] == -1) {
        printf("Empty\n");
        return;
    }

    int index = stackNum * (MAX_SIZE / n);
    for (int i = index; i <= index + top[stackNum]; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    initializeStacks();

    int stackNum, value, choice;

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stack number and value to push: ");
                scanf("%d %d", &stackNum, &value);
                push(stackNum, value);
                break;
            case 2:
                printf("Enter stack number to pop from: ");
                scanf("%d", &stackNum);
                int poppedValue = pop(stackNum);
                if (poppedValue != -1) {
                    printf("Popped value: %d\n", poppedValue);
                }
                break;
            case 3:
                printf("Enter stack number to display: ");
                scanf("%d", &stackNum);
                displayStack(stackNum);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
