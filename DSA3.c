/*Implement circular queue using arrays.*/
#include <stdio.h>
#include <stdlib.h>
 
#define MAX_SIZE 5
 
 
struct CircularQueue {
    int items[MAX_SIZE];
    int front, rear;
};
 
 
void initialize(struct CircularQueue *cq) {
    cq->front = -1; 
    cq->rear = -1; 
}
 
int isFull(struct CircularQueue *cq) {
    return (cq->front == 0 && cq->rear == MAX_SIZE - 1) || (cq->rear == (cq->front - 1) % (MAX_SIZE - 1));
}
 
 
int isEmpty(struct CircularQueue *cq) {
    return cq->front == -1;
}
 
 
void enqueue(struct CircularQueue *cq, int value) {
    if (isFull(cq)) {
        printf("Queue overflow! Cannot enqueue %d\n", value);
    } else {
        if (cq->front == -1) {
            cq->front = cq->rear = 0;
        } else {
            cq->rear = (cq->rear + 1) % MAX_SIZE;
        }
        cq->items[cq->rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}
 
 
int dequeue(struct CircularQueue *cq) {
    if (isEmpty(cq)) {
        printf("Queue underflow! Cannot dequeue\n");
        return -1; 
    } else {
        int dequeued = cq->items[cq->front];
        if (cq->front == cq->rear) {
            cq->front = cq->rear = -1;
        } else {
            cq->front = (cq->front + 1) % MAX_SIZE;
        }
        return dequeued;
    }
}
 
 
void display(struct CircularQueue *cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        int i = cq->front;
        do {
            printf("%d ", cq->items[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (cq->rear + 1) % MAX_SIZE);
        printf("\n");
    }
}
 
int main() {
    struct CircularQueue cq;
    initialize(&cq);
 
    int choice, value;
 
    while (1) {
        printf("\nCircular Queue Operations:\n");
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
                enqueue(&cq, value);
                break;
            case 2:
                value = dequeue(&cq);
                if (value != -1) {
                    printf("%d dequeued from queue\n", value);
                }
                break;
            case 3:
                display(&cq);
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
