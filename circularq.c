#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int front ;
    int rear ;
    int size;
    int * queue;
}Queue;
void Insert (Queue * Q)
{
    char ch ;
    int val;
    if (Q->rear == Q->size && Q->front == 0 || Q->rear == Q->front - 1 )
    {
        printf("Queue is full. Do you want to resize Y/N ");
        scanf (" %c" , &ch);
        if (ch == 'Y')
        {
            Q->size += 1;
            int * q = (int *)realloc (Q->queue ,Q->size*sizeof(int) );
            Q->queue = q;
            printf("Enter your value to be inserted ");
            scanf ("%d" , &val);
            Q->queue[(Q->rear)++] = val;
            return ;
        }
        else 
            return ;
    }
    if (Q->front == -1 && Q->rear == -1)
        Q->front = Q->rear = 0;
    if (Q->rear == Q->size && Q->front != 0)
             Q->rear = 0 ;
    printf("Enter your value to be inserted ");
    scanf ("%d" , &val);
    Q->queue[(Q->rear)++] = val;
    return ;
}
void Delete (Queue * Q)
{
    if (Q->front == -1 )
    {
        printf ("Queue is empty\n ");
        return;
    }
    printf ("Deleted element is %d\n",Q->queue[(Q->front)]);
    if (Q->front==Q->rear)
        Q->front = Q->rear = -1;
    else if (Q->front == Q->size)
         Q->front = 0;
    else 
          Q->front ++;
}
void Display(Queue * Q)
{
        if (Q->front == -1)
    {
        printf("\nQueue is Empty\n");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (Q->rear > Q->front)
    {
        for (int i = Q->front; i < Q->rear; i++)
            printf("%d ",Q->queue[i]);
    }
    else
    {
        for (int i = 0; i < Q->rear; i++)
            printf("%d ", Q->queue[i]);
        for (int i = Q->front; i < Q->size; i++)
            printf("%d ", Q->queue[i]);
    }
    printf ("\n");
}

int main ()
{
    int ch ;
    Queue Q;
    void (* funcpointer[3])(Queue *) ;
    funcpointer [0] = Insert ;
    funcpointer [1] = Delete ;
    funcpointer [2] = Display ;
    Q.size = 5;
    Q.queue = (int*)malloc(Q.size * sizeof (int));
    Q.front = Q.rear = -1;
    do {
        printf (" Enter 0 to insert\n 1 to delete\n 2 to display\n");
        printf ("Enter your choice ");
        scanf ("%d", &ch);
        if (ch > -1 && ch < 3)
           funcpointer [ch](&Q) ;
        else ch = 9 ;
    }while (ch != 9);
    return 0 ;
}