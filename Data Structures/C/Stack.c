#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int arr[MAX_SIZE];
    int top;
};

typedef struct Stack Stack;

void init(Stack* stack) {
    stack->top = -1;
}

int is_empty(Stack* stack) {
    return stack->top == -1;
}

int is_full(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, int item) {
    if (!is_full(stack)) {
        stack->arr[++stack->top] = item;
    } else {
        printf("Stack overflow\n");
    }
}

int pop(Stack* stack) {
    if (!is_empty(stack)) {
        return stack->arr[stack->top--];
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}

int peek(Stack* stack) {
    if (!is_empty(stack)) {
        return stack->arr[stack->top];
    } else {
        printf("Stack is empty\n");
        return -1;
    }
}

int main() {
    Stack stack;
    init(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    printf("Top element after pops: %d\n", peek(&stack));

    return 0;
}
