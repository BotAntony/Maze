// Basic implementation of stack that stores a vector (2-elements array)
#include "stack.h"

void initialize_stack(Stack *stack) {
    stack->top = -1;
}

bool isEmpty_stack(Stack *stack) {
    return stack->top == -1;
}

bool isFull_stack(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push_stack(Stack *stack, int value1, int value2) {
    if (isFull_stack(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top][0] = value1;
    stack->arr[stack->top][1] = value2;
    // debug
#ifdef DEBUG_STACK
    printf("Pushed [%d, %d] onto the stack\n", value1, value2);
    printf("Top: %d\n", stack->top);
#endif
}

int* pop_stack(Stack *stack) {
    if (isEmpty_stack(stack)) {
        printf("Stack Underflow\n");
        return NULL;
    }
    int* popped = stack->arr[stack->top];
    stack->top--;
    // debug
#ifdef DEBUG_STACK
    printf("Popped [%d, %d] from the stack\n", popped[0], popped[1]);
    printf("Top: %d\n", stack->top);
#endif
    return popped;
}

int* peek_stack(Stack *stack) {
    if (isEmpty_stack(stack)) {
        printf("Stack is empty\n");
        return NULL;
    }
    return stack->arr[stack->top];
}

