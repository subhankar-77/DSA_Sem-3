#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int top ;
    char* stack ;
}Stack;
void push (char a , Stack* S )
{
    S->stack[++(S->top)] = a;
}
char pop (Stack *S)
{
    return S->stack[(S->top)--];
}
char peek (Stack *S)
{
    return S->stack[S->top];
}



int isvalid (char*);
int matches (char , char);
int isrbracket(char);
int islbracket(char);
int isoperator (char );
int highpriority (char, Stack *S);
int priority_index(char);

char priority[] = {'^','%','/', '*' , '+','-'};
char lbracket [] = {'(', '{', '['};
char rbracket [] = {')','}',']'};

int main ()
{
    char* expression = malloc (10 * sizeof (char));
    char *postfix;
    int p = 0;
    do{   
       printf ("Enter your expression : ");
       gets ( expression);
    }while (isvalid(expression));
    printf ("Expression is Valid\n");
    strcat(expression, ")");
    int n = strlen(expression);
    postfix = (char*)malloc((n + 1) * sizeof(char));
    Stack S;
    S.stack = (char*)malloc((n + 1) * sizeof(char));
    S.top = -1;
    push('(', &S);
    for (int i = 0; i < n; i++) {
        char c = expression[i];
        
        if (islbracket(c)) {
            push(c, &S);
        } else if (isdigit(c) || isalpha(c)) {
            postfix[p++] = c;
        } else if (isrbracket(c)) {
            while (S.top != -1 && !islbracket(peek(&S))) {
                postfix[p++] = pop(&S);
            }
            pop(&S); // Remove the matching left bracket
        } else if (isoperator(c)) {
            while (S.top != -1 && isoperator(peek(&S)) && highpriority(c, &S)) {
                postfix[p++] = pop(&S);
            }
            push(c, &S);
        }
    }
    postfix[p] = '\0';
    printf("Postfix expression: %s\n", postfix);
    free(expression);
    free(postfix);
    free(S.stack);
    return 0;
}


int isvalid (char * a)
{
    char c;
    int n = strlen(a);
    Stack  S ;
    S.stack = (char*)malloc (n * sizeof(char));
    S.top = -1;
    for (int i = 0 ; i < n ; i++)
    {
        if (islbracket (a[i]))
        {
            push (a[i],&S);
        }
        else if (isrbracket(a[i]) )
        {
            if (S.top != -1 && matches (peek (&S), a[i]))
                c = pop(&S);
            else
                return 1;
        }
    }
    if (S.top < 0)
    {
        free (S.stack);
        return 0;
    }
    free (S.stack);
    return 1;  
}


int matches(char a, char b) 
{
    return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']');
}

int islbracket(char c)
{
    for (int j = 0; j < sizeof(lbracket); j++)
    {
        if (c == lbracket[j])
            return 1;
    }
    return 0;
}

int isrbracket(char c)
{
    for (int j = 0; j < sizeof(rbracket); j++)
    {
        if (c == rbracket[j])
            return 1;
    }
    return 0;
}

int isoperator(char c)
{
    for (int j = 0; j < sizeof(priority); j++)
    {
        if (c == priority[j]) 
            return 1;
    }
    return 0;
}

int highpriority(char c, Stack* S) 
{
    int c_priority = priority_index(c);
    int s_priority = priority_index(peek(S));
    return c_priority <= s_priority; 
}

int priority_index(char op)
{
        for (int i = 0; i < sizeof(priority); i++)
            if (op == priority[i]) return i;
        return -1;
}
