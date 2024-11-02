// stack.h
#ifndef STACK_H_
#define STACK_H_

#include <stdbool.h>
#include <stdio.h>

// This should be enough for 90x90 maze
#define MAX_SIZE 1000

// #define DEBUG_STACK 1

typedef struct {
    int arr[MAX_SIZE][2];
    int top;
} Stack;

void initialize_stack(Stack *stack);
bool isEmpty_stack(Stack *stack);
bool isFull_stack(Stack *stack);
void push_stack(Stack *stack, int value1, int value2);
int* pop_stack(Stack *stack);
int* peek_stack(Stack *stack);

#endif // STACK_H_
