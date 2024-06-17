#include <stdio.h>
#include <stdlib.h>
 
 
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
 
 
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
 
 
struct Node* insertAtBeginning(struct Node *head, int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}
 
void insertAtEnd(struct Node *head, int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        printf("List is empty. Inserting at the beginning.\n");
        return;
    }
    struct Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}
 
 
struct Node* deleteNode(struct Node *head, int key) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }
    struct Node *temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found in the list\n", key);
        return head;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp == head) {
        head = temp->next;
    }
    free(temp);
    return head;
}
 
 
void displayForward(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Doubly linked list elements (forward): ");
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
 
 
void displayBackward(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Doubly linked list elements (backward): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}
 
 
void freeList(struct Node *head) {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
 
int main() {
    struct Node *head = NULL;
    int choice, value, key;
 
    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete node\n");
        printf("4. Display forward\n");
        printf("5. Display backward\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(head, value);
                break;
            case 3:
                if (head == NULL) {
                    printf("List is empty. Cannot delete.\n");
                } else {
                    printf("Enter key to delete: ");
                    scanf("%d", &key);
                    head = deleteNode(head, key);
                }
                break;
            case 4:
                displayForward(head);
                break;
            case 5:
                displayBackward(head);
                break;
            case 6:
                freeList(head);
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
 
    return 0;
}
