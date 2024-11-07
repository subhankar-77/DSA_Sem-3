#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *stack;
    int top;
} Stack;

int N;

void push(char c, Stack *S) {
    S->stack[++S->top] = c;
}

char pop(Stack *S) {
    return S->stack[S->top--];
}

char peek(Stack *S) {
    return S->stack[S->top];
}

int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void reverse(char* exp) {
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
}

void infixToPostfix(char* infix, char* postfix, Stack *S) {
    int i = 0, k = 0;
    while (infix[i]) {
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i], S);
        } else if (infix[i] == ')') {
            while (S->top != -1 && S->stack[S->top] != '(') {
                postfix[k++] = pop(S);
            }
            pop(S); // Remove '('
        } else { // Operator
            while (S->top != -1 && precedence(S->stack[S->top]) >= precedence(infix[i])) {
                postfix[k++] = pop(S);
            }
            push(infix[i], S);
        }
        i++;
    }
    while (S->top != -1) {
        postfix[k++] = pop(S);
    }
    postfix[k] = '\0'; // Null-terminate the postfix expression
}

void infixToPrefix(char* infix, char* prefix, Stack *S) {
    reverse(infix);
    for (int i = 0; infix[i]; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    char *postfix = (char *)malloc(N * sizeof(char));
    infixToPostfix(infix, postfix, S);
    reverse(postfix);
    strcpy(prefix, postfix);
    free(postfix); 
}

int isValid(char *exp) {
    Stack S;
    S.stack = (char*)malloc(strlen(exp) * sizeof(char));
    S.top = -1;

    for (int i = 0; exp[i]; i++) {
        if (exp[i] == '(') {
            push(exp[i], &S);
        } else if (exp[i] == ')') {
            if (S.top != -1 && peek(&S) == '(') {
                pop(&S);
            } else {
                free(S.stack);
                return 0; 
            }
        }
    }
    int valid = S.top == -1; 
    free(S.stack);
    return valid;
}

int main() {
    char *infix = (char *)malloc(100 * sizeof(char));
    char *prefix = (char *)malloc(100 * sizeof(char));

    do {
        printf("Enter an infix expression: ");
        fgets(infix, 100, stdin);
        infix[strcspn(infix, "\n")] = 0; 
    } while (!isValid(infix));

    N = strlen(infix);
    Stack S;
    S.stack = (char *)malloc(N * sizeof(char));
    S.top = -1;

    infixToPrefix(infix, prefix, &S);
    
    printf("Prefix expression: %s\n", prefix);
    free(infix);
    free(prefix);
    free(S.stack);
    
    return 0;
}
