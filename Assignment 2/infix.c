#include <stdio.h>

#define MAX 100  

char stack[MAX];  
int top = -1;     


void push(char x) {
    if (top < MAX - 1) {
        stack[++top] = x;
    }
}


char pop() {
    if (top != -1) {
        return stack[top--];
    }
    return -1;  
}


int precedence(char x) {
    if (x == '+' || x == '-') {
        return 1;
    }
    if (x == '*' || x == '/') {
        return 2;
    }
    return 0;
}
int isOperand(char x) {
    return (x >= '0' && x <= '9') || (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}


void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char x;

    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i];  
        } 
        else if (infix[i] == '(') {
            push(infix[i]);
        } 
        else if (infix[i] == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();  
            }
            pop();  
        } 
        else {  
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }

   
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';  
}

int main() {
    char infix[MAX], postfix[MAX];

    
    printf("Enter infix expression: ");
    scanf("%s", infix);

    
    infixToPostfix(infix, postfix);

    
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
