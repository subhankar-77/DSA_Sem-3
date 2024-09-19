#include <stdio.h>
#include <stdlib.h>  

#define MAX 100  

int stack[MAX];  
int top = -1;    


void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    } else {
        printf("Stack overflow\n");
        
    }
}


int pop() {
    if (top != -1) {
        return stack[top--];
    } else {
        printf("Stack underflow\n");
        
    }
}


int evaluatePostfix(char postfix[]) {
    int i = 0;
    int op1, op2, result;
    char ch;

    while (postfix[i] != '\0') {
        ch = postfix[i];

        if (ch >= '0' && ch <= '9') {
           
            push(ch - '0');
        } else {
            
            op2 = pop();
            op1 = pop();

            switch (ch) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    
            }

            push(result);  
        }

        i++;
    }

    return pop();  
}

int main() {
    char postfix[MAX];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
}
