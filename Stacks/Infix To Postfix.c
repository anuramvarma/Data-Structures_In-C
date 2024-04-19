#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};
struct Stack* createStack(unsigned capacity) 
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}
int isEmpty(struct Stack* stack) 
{
    return stack->top == -1;
}
void push(struct Stack* stack, char op) 
{
    stack->array[++stack->top] = op;
}
char pop(struct Stack* stack) 
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '\0';
}
int precedence(char ch) 
{
    return (ch == '+' || ch == '-') ? 1 : (ch == '*' || ch == '/') ? 2 : -1;
}
void infixToPostfix(char* infix) 
{
    struct Stack* stack = createStack(strlen(infix));
    char postfix[strlen(infix)];
    int j = 0;
    for (int i = 0; infix[i]; i++) 
    {
        char ch = infix[i];
        if (isalnum(ch))
            postfix[j++] = ch;
        else if (ch == '(')
            push(stack, ch);
        else if (ch == ')') 
        {
            while (!isEmpty(stack) && stack->array[stack->top] != '(')
                postfix[j++] = pop(stack);
            pop(stack); // Remove '('
        } else {
            while (!isEmpty(stack) && precedence(ch) <= precedence(stack->array[stack->top]))
                postfix[j++] = pop(stack);
            push(stack, ch);
        }
    }
    while (!isEmpty(stack))
        postfix[j++] = pop(stack);
    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);
}
int main() 
{
    char infix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}
