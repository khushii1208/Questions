#include <stdio.h>
#include <stdlib.h>
 
 
struct Node {
    int data;
    struct Node* next;
};
 
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
 
 
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
 
 
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Linked list elements: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
 
 
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
 
int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <number_of_nodes> <file_name>\n", argv[0]);
        return EXIT_FAILURE;
    }
 
    int n = atoi(argv[1]); 
    char* file_name = argv[2];
 
    struct Node* head = NULL;
    int value;
 
    
    printf("Enter %d values to create the linked list:\n", n);
    for (int i = 0; i < n; ++i) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }
 
    
    printf("Linked list created:\n");
    display(head);
 
   
    FILE* fp = fopen(file_name, "w");
    if (fp == NULL) {
        perror("Error opening file");
        freeList(head);
        return EXIT_FAILURE;
    }
 
    struct Node* temp = head;
    while (temp != NULL) {
        fprintf(fp, "%d\n", temp->data);
        temp = temp->next;
    }
 
    fclose(fp);
    printf("Contents of linked list have been written to %s\n", file_name);
 
    
    freeList(head);
 
    return EXIT_SUCCESS;
}
 
