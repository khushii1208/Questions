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
    if (argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return EXIT_FAILURE;
    }
 
    char* file_name = argv[1]; 
    struct Node* head = NULL;
    int value;
 
    
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
 
   
    while (fscanf(fp, "%d", &value) != EOF) {
        head = insertAtEnd(head, value);
    }
 
    fclose(fp);
 
    
    printf("Linked list recreated from %s:\n", file_name);
    display(head);
 
   
    freeList(head);
 
    return EXIT_SUCCESS;
}
