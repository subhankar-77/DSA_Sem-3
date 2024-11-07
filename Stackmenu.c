#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int size ;
    int top ;
    int* stack ;
}Stack;
void push (int a , Stack* S )
{
    char ch ;
    if (S->top > S->size)
    {
        printf ("Stack full. Do you want to resize ? Y/N");
        scanf ("%c" , &ch);
        if (ch == 'Y')
        {
            S->size += 100 ;
           S->stack = (int*) realloc(S->stack, S->size *sizeof(int));
        }
        else 
           return ;
    }
    S->stack[++(S->top)] = a;
}
void pop (Stack *S)
{
    if (S->top < 0 )
    {
       printf("Stack is empty");
       return ;
    }
    printf ("Popped element is %d\n", S->stack[(S->top)--]);
}
void peek (Stack *S)
{
    if (S->top < 0 )
    {
       printf("Stack is empty");
       return ;
    }
    printf ("Top element is %d\n", S->stack[(S->top)]);
}
void display (Stack *S)
{
    for (int i = 0 ; i <= S->top ; i++)
         printf ("%d ",S->stack[i]);
    printf ("\n");
    return ;
}


int main ()
{
    Stack S ;
    S.stack = (int*) malloc (100 * (sizeof(int)));
    S.size = 100;
    S.top = -1;
    int ch,val ;
    do {
        printf (" Enter 0 to push\n 1 to pop\n 2 to peek\n 3 to display\n");
        printf ("Enter choice ");
        scanf ("%d",&ch);
        switch (ch)
        {
            case 0 :
            printf ("Enter your value to be pushed ");
            scanf ("%d", &val);
            push (val , &S);
            break;
            case 1 :
            pop(&S);
            break;
            case 2:
            peek(&S);
            break;
            case 3:
            display (&S);
            break;
            default:
            ch = 4;
        }
    }while (ch < 4);
    free(S.stack);
}
