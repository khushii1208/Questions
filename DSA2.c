/*Implement QUEUE to perform the below operations using arrays.
a. enqueue
b. dequeue
c. display
*/
#include <stdio.h>
#include <stdlib.h>
 
#define MAX_SIZE 100
 
 
struct Queue {
    int items[MAX_SIZE];
    int front, rear;
};
 
 
void initialize(struct Queue *q) {
    q->front = -1; 
    q->rear = -1; 
}
 
 
int isFull(struct Queue *q) {
    return (q->rear == MAX_SIZE - 1);
}
 
 
int isEmpty(struct Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}
 
 
void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue overflow! Cannot enqueue %d\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}
 
 
int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow! Cannot dequeue\n");
        return -1; 
    } else {
        int dequeued = q->items[q->front];
        q->front++;
        return dequeued;
    }
}
 
 
void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}
 
int main() {
    struct Queue queue;
    initialize(&queue);
 
    int choice, value;
 
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                value = dequeue(&queue);
                if (value != -1) {
                    printf("%d dequeued from queue\n", value);
                }
                break;
            case 3:
                display(&queue);
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
