#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *queue; // Dynamic array to hold the elements
    int front;
    int rear;
    int size;
} irDQ;

void insertRear(int val, irDQ *Q) {
    if (Q->rear >= Q->size - 1) {
        printf("Queue is full. Do you want to resize? Y/N: ");
        char ch;
        scanf(" %c", &ch);
        if (ch == 'Y') {
            Q->size *= 2;
            Q->queue = (int *)realloc(Q->queue, Q->size * sizeof(int));
        } else {
            return;
        }
    }
    if (Q->front == -1 && Q->rear == -1) {
        Q->front = Q->rear = 0;
    } else {
        Q->rear++;
    }
    
    Q->queue[Q->rear] = val; 
}

void deleteFront(irDQ *Q) {
    if (Q->front == -1 || Q->front > Q->rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Deleted element is %d\n", Q->queue[Q->front++]);
}

void deleteRear(irDQ *Q) {
    if (Q->rear < Q->front) {
        printf("Queue is empty\n");
        return;
    }
    printf("Deleted element is %d\n", Q->queue[Q->rear--]);
}

void display(irDQ *Q) {
    if (Q->front == -1 || Q->front > Q->rear) {
        printf("Queue is empty\n");
        return;
    }

    for (int i = Q->front; i <= Q->rear; i++) {
        printf("%d ", Q->queue[i]);
    }
    printf("\n");
}

int main() {
    irDQ Q;
    Q.queue = (int *)malloc(100 * sizeof(int));
    Q.size = 100;
    Q.front = Q.rear = -1;

    int ch, val;
    do {
        printf("Enter 0 to insert\n1 to delete from front\n2 to delete from rear\n3 to display\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 0:
                printf("Enter your value to be pushed: ");
                scanf("%d", &val);
                insertRear(val, &Q);
                break;
            case 1:
                deleteFront(&Q);
                break;
            case 2:
                deleteRear(&Q);
                break;
            case 3:
                display(&Q);
                break;
            default:
                ch = 4; // Exit
        }
    } while (ch < 4);

    free(Q.queue);
    return 0;
}
