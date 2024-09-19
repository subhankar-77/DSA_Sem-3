#include <stdio.h>
#include <stdlib.h>

#define MAX 100 


int front = 0, rear = -1, size = 0; 


int isFull();
int isEmpty();
void insertRear(int deque[], int item);
int deleteFront(int deque[]);
int deleteRear(int deque[]);
void displayDeque(int deque[]);

int main() {
    int deque[MAX]; 
    int choice, item;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Rear\n");
        printf("2. Delete from Front\n");
        printf("3. Delete from Rear\n");
        printf("4. Display Deque\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull()) {
                    printf("Deque is full!\n");
                } else {
                    printf("Enter item to insert at rear: ");
                    scanf("%d", &item);
                    insertRear(deque, item);
                }
                break;
            case 2:
                item = deleteFront(deque);
                if (item != -1) {
                    printf("Deleted item from front: %d\n", item);
                }
                break;
            case 3:
                item = deleteRear(deque);
                if (item != -1) {
                    printf("Deleted item from rear: %d\n", item);
                }
                break;
            case 4:
                displayDeque(deque);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);  
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}


int isFull() {
    return size == MAX;
}

int isEmpty() {
    return size == 0;
}


void insertRear(int deque[], int item) {
    rear++;
    deque[rear] = item;
    size++;
}


int deleteFront(int deque[]) {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return -1;
    } else {
        int item = deque[front];
        front++;
        size--;
        return item;
    }
}


int deleteRear(int deque[]) {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return -1;
    } else {
        int item = deque[rear];
        rear--;
        size--;
        return item;
    }
}


void displayDeque(int deque[]) {
    if (isEmpty()) {
        printf("Deque is empty!\n");
    } else {
        printf("Deque elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", deque[i]);
        }
        printf("\n");
    }
}
