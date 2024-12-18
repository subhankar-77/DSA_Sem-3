#include <stdlib.h>
#include <stdio.h>

typedef struct Node 
{
    int data ;
    struct Node * pre ;
    struct Node * next ;
}Node ;
Node * Start = NULL ;

void insertbeg ()
{
    Node *N1 = (Node * )malloc(1*sizeof (Node));
    printf ("Enter your data ") ;
    scanf ("%d" , &N1->data);
    N1->next = Start;
    N1->pre = NULL;
    if (Start != NULL)
          Start->pre = N1;
    Start = N1 ;
}
void insertend ()
{
    Node *N1 = (Node * )malloc(1*sizeof (Node));
    printf ("Enter your data ") ;
    scanf ("%d" , &N1->data);
    Node * p = Start ;
    N1->next = NULL;
    while (p->next != NULL)
        p = p->next ;
    p->next = N1;
    N1->pre = p ;
}
void insertpos ()
{
    Node * p = Start ;
    int pos ,c = 0 ;
    printf ("Enter your position ");
    scanf ("%d" , &pos);
    if (pos == 0){
       insertbeg();return;}
    Node *N1 = (Node * )malloc(1*sizeof (Node));
    printf ("Enter your data ") ;
    scanf ("%d" , &N1->data);
    while (p->next != NULL && c < pos)
    {
        p = p->next ;
        c++;
    }
    N1->pre = p->pre;
    N1->next = p;
    p->pre->next = N1;
    p->pre = N1;
}
void deletebeg ()
{
    if (Start != NULL)
    {
        Node * p = Start ;
         Start->next->pre = NULL;
         Start = Start->next ;
         free (p);
    }
}
void deleteend()
{
    if (Start != NULL)
    {
         Node * p = Start ;
         while (p->next != NULL)
             p = p->next ;
         p->pre->next = NULL ;
         free (p) ;
    }
}
void deletepos ()
{
    if (Start != NULL)
    {
        Node * p = Start ;
        int pos ,c = 0 ;
        printf ("Enter your position ");
        scanf ("%d" , &pos);
        if (pos == 0){
             deletebeg();
             return;
        }
        while (p->next != NULL && c < pos)
        {
             p = p->next ;
             c++;
        }
       if (p->pre != NULL) 
            p->pre->next = p->next;
       if (p->next != NULL) 
           p->next->pre = p->pre;
    free (p);
    }
}
void display ()
{
    Node * ptr = Start ;
    while (ptr != NULL)
    {
        printf ("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main ()
{
    int ch ;
    void (* funcpointer[7])() = {insertbeg , insertend , insertpos , deletebeg , deleteend, deletepos ,display};
    do {
        printf (" Enter 0 to insert at beginning\n 1 to insert at end\n 2 to insert at position\n 3 to delete at beginning \n 4 to delete at end \n 5 to delete at position \n 6 to display\n");
        printf ("Enter your choice ");
        scanf ("%d", &ch);
        if (ch > -1 && ch < 7)
           funcpointer [ch]() ;
        else ch = 9 ;
    }while (ch != 9);
    while (Start != NULL) {
        deletebeg();
    }
    return 0 ;
}