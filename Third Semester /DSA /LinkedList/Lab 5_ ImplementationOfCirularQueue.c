#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node node;

node *start = NULL;

void insertAtBeginning(int value) {
    node *newNode = (node*) malloc(sizeof(node));
    newNode->data = value;
    if (start == NULL) {
        start = newNode;
        newNode->next = start;
    } else {
        node *ptr = start;
        while (ptr->next != start) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->next = start;
        start = newNode;
    }
    printf("Node with data %d inserted at the beginning.\n", value);
}

void insertAtEnd(int value) {
    node *newNode = (node*) malloc(sizeof(node));
    newNode->data = value;
    if (start == NULL) {
        start = newNode;
        newNode->next = start;
    } else {
        node *ptr = start;
        while (ptr->next != start) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->next = start;
    }
    printf("Node with data %d inserted at the end.\n", value);
}

void deleteAtBeginning() {
    if (start == NULL) {
        printf("Circular linked list is empty. Unable to delete.\n");
        return;
    }
    if (start->next == start) {
        free(start);
        start = NULL;
    } else {
        node *ptr = start;
        while (ptr->next != start) {
            ptr = ptr->next;
        }
        node *temp = start;
        start = start->next;
        ptr->next = start;
        free(temp);
    }
    printf("Node deleted from the beginning.\n");
}

void deleteAtEnd() {
    if (start == NULL) {
        printf("Circular linked list is empty. Unable to delete.\n");
        return;
    }
    if (start->next == start) {
        free(start);
        start = NULL;
    } else {
        node *ptr = start;
        node *prev = NULL;
        while (ptr->next != start) {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = start;
        free(ptr);
    }
    printf("Node deleted from the end.\n");
}

void display() {
    if (start == NULL) {
        printf("Circular linked list is empty.\n");
        return;
    }
    node *ptr = start;
    printf("Circular linked list: ");
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);
    printf("\n");
}

int main() {
 
    int choice, value;
     printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete at beginning\n");
        printf("4. Delete at end\n");
        printf("5. Display\n");
        printf("6. Exit\n");
    while (1) {
       
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
               insertAtEnd(value);
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
printf("Invalid choice. Please try again.\n");
}
}
return 0;
}
