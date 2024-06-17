/*Implement STACK to perform the below operations using arrays.
a. push
b. pop
c. display
*/
#include <stdio.h>
#include <stdlib.h>
 
#define MAX_SIZE 100
 
struct Stack {
    int items[MAX_SIZE];
    int top;
};
 
 
void initialize(struct Stack *s) {
    s->top = -1; 
}
 
 
int isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}
 
 
int isEmpty(struct Stack *s) {
    return s->top == -1;
}
 
 
void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow! Cannot push %d\n", value);
    } else {
        s->top++;
        s->items[s->top] = value;
        printf("%d pushed to stack\n", value);
    }
}
 
 
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop\n");
        return -1; 
    } else {
        int popped = s->items[s->top];
        s->top--;
        return popped;
    }
}
 
 
void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}
 
int main() {
    struct Stack stack;
    initialize(&stack);
 
    int choice, value;
 
    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("%d popped from stack\n", value);
                }
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
 
    return 0;
}
