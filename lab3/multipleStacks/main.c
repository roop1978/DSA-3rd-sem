
// c program to implement n stacks using arrays
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int n, freespot;

int arr[MAX_SIZE];
int top[MAX_SIZE];
int next[MAX_SIZE];

void initializeStacks() {
    printf("Enter number of stacks: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        top[i] = -1;
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        next[i] = i + 1;
    }

    next[MAX_SIZE - 1] = -1;
    freespot = 0;
}

void push(int m, int x) {
    if (freespot == -1) {
        printf("\nStack overflow");
        return;
    }

    int index = freespot;
    freespot = next[index];
    arr[index] = x;
    next[index] = top[m - 1];
    top[m - 1] = index;
}

int pop(int m) {
    if (top[m - 1] == -1) {
        printf("\nStack underflow");
        return -1;
    }

    int index = top[m - 1];
    top[m - 1] = next[index];
    next[index] = freespot;
    freespot = index;
    return arr[index];
}

int main() {
    initializeStacks();

    int stackNum, value, choice;

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
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
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
