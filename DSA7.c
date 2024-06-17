/* Implement Circular Double Linked List*/
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
 
 
struct Node* insertAtBeginning(struct Node *last, int value) {
    struct Node *newNode = createNode(value);
    if (last == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }
    newNode->next = last->next;
    newNode->prev = last;
    last->next->prev = newNode;
    last->next = newNode;
    return last;
}
 
 
struct Node* insertAtEnd(struct Node *last, int value) {
    struct Node *newNode = createNode(value);
    if (last == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }
    newNode->next = last->next;
    newNode->prev = last;
    last->next->prev = newNode;
    last->next = newNode;
    return newNode;
}
 
 
struct Node* deleteNode(struct Node *last, int key) {
    if (last == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }
    struct Node *temp = last->next;
    struct Node *prev = last;
 
    
    do {
        if (temp->data == key) {
            break;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != last->next);
 
    
    if (temp == last->next && temp->data != key) {
        printf("Element %d not found in the list\n", key);
        return last;
    }
 
    if (temp->next == temp) {
        free(temp);
        return NULL;
    }
 
   
    if (temp == last->next) {
        last->next = temp->next;
        temp->next->prev = last;
    }
 
   
    if (temp == last) {
        prev->next = last->next;
        last = prev;
    } else {
        prev->next = temp->next;
        temp->next->prev = prev;
    }
 
    free(temp);
    return last;
}
 
 
void displayForward(struct Node *last) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Circular doubly linked list elements (forward): ");
    struct Node *temp = last->next;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}
 
 
void displayBackward(struct Node *last) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Circular doubly linked list elements (backward): ");
    struct Node *temp = last;
    do {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    } while (temp != last);
    printf("\n");
}
 
 
void freeList(struct Node *last) {
    if (last == NULL) {
        return;
    }
    struct Node *temp = last->next;
    while (temp != last) {
        struct Node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    free(last);
}
 
int main() {
    struct Node *last = NULL;
    int choice, value, key;
 
    while (1) {
        printf("\nCircular Doubly Linked List Operations:\n");
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
                last = insertAtBeginning(last, value);
                if (last == NULL) {
                    last = last->next;
                }
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                last = insertAtEnd(last, value);
                if (last == NULL) {
                    last = last->next; 
                }
                break;
            case 3:
                if (last == NULL) {
                    printf("List is empty. Cannot delete.\n");
                } else {
                    printf("Enter key to delete: ");
                    scanf("%d", &key);
                    last = deleteNode(last, key);
                }
                break;
            case 4:
                displayForward(last);
                break;
            case 5:
                displayBackward(last);
                break;
            case 6:
                freeList(last);
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
 
    return 0;
}
