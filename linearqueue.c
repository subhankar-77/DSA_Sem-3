#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int front ;
    int rear ;
    int size ;
    int *queue ;
}Queue ;
void Insert (int val , Queue * Q)
{
    char ch ;
    if (Q->rear > Q->size)
    {
        printf ("Queue is full do you want to resize ? Y/N");
        scanf ("%c",&ch);
        if (ch == 'Y')
        {
            Q->size += 100;
            Q->queue = realloc(Q->queue,Q->size*sizeof(int));
        }
        else
            return ;  
    }
    if (Q->front == -1 && Q->rear == -1)
            Q->rear=Q->front = 0;
    Q->queue[(Q->rear)++] = val;
}
void Delete (Queue *Q)
{
    if (Q->front == -1 || Q->front > Q->rear){
        printf ("Queue is empty ");return;}
    else 
        printf ("Deleted element is %d\n",Q->queue[(Q->front)++]);
}
void Display (Queue *Q)
{
    for (int i = Q->front ;i < Q->rear;i++ )
        printf ("%d ",Q->queue[i]);
    printf("\n");
}



int main ()
{
    Queue Q ;
    Q.queue = malloc (100 * (sizeof(int)));
    Q.size = 100;
    Q.front = Q.rear = -1;
    int ch,val ;
    do {
        printf (" Enter 0 to insert\n 1 to delete\n 2 to display\n");
        printf ("Enter choice ");
        scanf ("%d",&ch);
        switch (ch)
        {
            case 0 :
            printf ("Enter your value to be pushed ");
            scanf ("%d", &val);
            Insert (val , &Q);
            break;
            case 1 :
            Delete(&Q);
            break;
            case 2:
            Display (&Q);
            break;
            default:
            ch = 4;
        }
    }while (ch < 3);
    free(Q.queue);
}