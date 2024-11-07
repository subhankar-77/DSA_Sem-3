#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct 
{
    int size;
    int top;
    float *stack;
} Stack;

void push(float a, Stack* S) 
{
    S->stack[++(S->top)] = a;
}

float pop(Stack *S) 
{
    return S->stack[(S->top)--];
}

float peek(Stack *S) 
{
    return S->stack[S->top];
}

char *arrayconverter(char *exp, char *exp2[], int *c);
int isOperator(char*);
float evaluate(float, float, char*);

int main() 
{
    Stack s;
    s.size = 100;
    s.stack = (float*)malloc(s.size * sizeof(float));
    s.top = -1;
    if (s.stack == NULL) 
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    char* exp = (char*)malloc(100 * sizeof(char));
    if (exp == NULL) 
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter a postfix expression: ");
    fgets(exp, 100, stdin);
    exp[strcspn(exp, "\n")] = 0;
    int count = 0;
    char *exp2[100]; 
    arrayconverter(exp, exp2, &count);
    for (int i = 0; i < count; i++) 
    {
        if (isOperator(exp2[i])) 
        {
            float a = pop(&s);
            float b = pop(&s);
            float eval = evaluate(a, b, exp2[i]);
            push(eval, &s);
        } 
        else 
        {
            push(atof(exp2[i]), &s);
        }
    }
    printf("Result: %.2f\n", pop(&s));
    free(exp);
    free(s.stack);
    return 0;
}

char *arrayconverter(char *exp, char *exp2[], int *c) 
{
    char *token;
    int i = 0;
    token = strtok(exp, " \t\n");
    while (token != NULL) 
    {
        exp2[i++] = token;
        token = strtok(NULL, " \t\n");
    }
    *c = i; 
    return NULL;
}

int isOperator(char *c) 
{
    char ch = c[0];
    switch (ch) {
    case '+':
    case '-':
    case '%':
    case '*':
    case '^':
        return 1; 
    default:
        return 0; 
    }
}

float evaluate(float a, float b, char *arr) 
{
    char c = arr[0]; 
    switch (c) 
    {
    case '+':
        return (b + a);
    case '-':
        return (b - a);
    case '%':
        return ((int)b % (int)a); 
    case '*':
        return b * a;
    case '^':
        return pow(b, a); 
    default:
        return 0.0f; 
    }
}
