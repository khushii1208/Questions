#include <stdio.h>
#include <stdlib.h>
 
 
struct Node {
    int data;
    struct Node *next;
};
 
 
struct Node* insertAtBeginning(struct Node *head, int value) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }
    newNode->data = value;
    newNode->next = head;
    return newNode;
}
 
 
void insertAtEnd(struct Node *head, int value) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
 
    struct Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}
 
 
struct Node* deleteNode(struct Node *head, int key) {
    struct Node *temp = head;
    struct Node *prev = NULL;
 
   
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }
 
    
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
 
    
    if (temp == NULL) {
        printf("Element %d not found in the list\n", key);
        return head;
    }
 
    
    prev->next = temp->next;
    free(temp);
    return head;
}
 
 
void display(struct Node *head) {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    printf("Linked list elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
 
// Function to free the memory allocated to the linked list
void freeLinkedList(struct Node *head) {
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
        printf("\nSingle Linked List Operations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete node\n");
        printf("4. Display\n");
        printf("5. Exit\n");
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
                if (head == NULL) {
                    head = (struct Node*) malloc(sizeof(struct Node));
                    head->data = value;
                    head->next = NULL;
                } else {
                    insertAtEnd(head, value);
                }
                break;
            case 3:
                if (head == NULL) {
                    printf("Linked list is empty. Cannot delete.\n");
                } else {
                    printf("Enter key to delete: ");
                    scanf("%d", &key);
                    head = deleteNode(head, key);
                }
                break;
            case 4:
                display(head);
                break;
            case 5:
                freeLinkedList(head);
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
 
    return 0;
}
