#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of the deque

// Initialize front, rear, and size for the deque
int front = -1, rear = -1, size = 0;  // Global variables for front, rear, and size

// Function prototypes
int isFull();
int isEmpty();
void insertFront(int deque[], int item);
void insertRear(int deque[], int item);
int deleteFront(int deque[]);
void displayDeque(int deque[]);

int main() {
    int deque[MAX];  // Array to hold deque elements
    int choice, item;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front (Output Restricted)\n");
        printf("4. Display Deque\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull()) {
                    printf("Deque is full!\n");
                } else {
                    printf("Enter item to insert at front: ");
                    scanf("%d", &item);
                    insertFront(deque, item);
                }
                break;
            case 2:
                if (isFull()) {
                    printf("Deque is full!\n");
                } else {
                    printf("Enter item to insert at rear: ");
                    scanf("%d", &item);
                    insertRear(deque, item);
                }
                break;
            case 3:
                item = deleteFront(deque);
                if (item != -1) {
                    printf("Deleted item from front: %d\n", item);
                }
                break;
            case 4:
                displayDeque(deque);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);  // Exit the program
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}

// Check if the deque is full
int isFull() {
    return size == MAX;
}

// Check if the deque is empty
int isEmpty() {
    return size == 0;
}

// Insert an item at the front of the deque
void insertFront(int deque[], int item) {
    if (front == -1 && rear == -1) {  // First element
        front = rear = 0;
    } else if (front == 0) {  // Wrap around
        front = MAX - 1;
    } else {
        front--;
    }
    deque[front] = item;
    size++;
}

// Insert an item at the rear of the deque
void insertRear(int deque[], int item) {
    if (front == -1 && rear == -1) {  // First element
        front = rear = 0;
    } else if (rear == MAX - 1) {  // Wrap around
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = item;
    size++;
}

// Delete an item from the front of the deque
int deleteFront(int deque[]) {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return -1;
    } else {
        int item = deque[front];
        if (front == rear) {  // Only one element
            front = rear = -1;
        } else if (front == MAX - 1) {  // Wrap around
            front = 0;
        } else {
            front++;
        }
        size--;
        return item;
    }
}

// Display the deque
void displayDeque(int deque[]) {
    if (isEmpty()) {
        printf("Deque is empty!\n");
    } else {
        printf("Deque elements are: ");
        int i = front;
        while (1) {
            printf("%d ", deque[i]);
            if (i == rear) {
                break;
            }
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}
