#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

typedef struct Node Node;

Node* head = NULL;
Node* last = NULL;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        last = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Node with data %d inserted at the beginning.\n", data);
}

void insertAtEnd(int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        last = newNode;
    } else {
        newNode->prev = last;
        last->next = newNode;
        last = newNode;
    }
    printf("Node with data %d inserted at the end.\n", data);
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else {
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            last = NULL;
        }
        free(temp);
        printf("Node deleted from the beginning.\n");
    }
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else {
        Node* temp = last;
        last = last->prev;
        if (last != NULL) {
            last->next = NULL;
        } else {
            head = NULL;
        }
        free(temp);
        printf("Node deleted from the end.\n");
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        printf("Doubly Linked List: ");
        Node* current = head;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {

    int choice, data;
     printf("\n--- Doubly Linked List Operations ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display\n");
        printf("6. Exit\n");
    while (1) {
       
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                deleteAtBeginning();
                break;
            case 4:
                deleteAtEnd();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
                        default:
            printf("Invalid choice. Please enter a valid option.\n");
    }
}

return 0;
}
