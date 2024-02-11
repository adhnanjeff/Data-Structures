#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
    printf("Element inserted at the beginning successfully.\n");
}

void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty. Cannot delete from the beginning.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
    printf("Element deleted from the beginning successfully.\n");
}

void insertEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        printf("Element inserted at the end successfully.\n");
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    printf("Element inserted at the end successfully.\n");
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty. Cannot delete from the end.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Element deleted from the end successfully.\n");
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
    printf("Element deleted from the end successfully.\n");
}

void insertMiddle(int value) {
    printf("Enter the position to insert after: ");
    int position;
    scanf("%d", &position);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node* temp = head;
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position. Element not inserted.\n");
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;

    printf("Element inserted at position %d successfully.\n", position);
}

void deleteMiddle() {
    if (head == NULL) {
        printf("List is empty. Cannot delete from the middle.\n");
        return;
    }

    printf("Enter the position to delete: ");
    int position;
    scanf("%d", &position);

    struct Node* temp = head;
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position. Element not deleted.\n");
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Element deleted from position %d successfully.\n", position);
}

void displayList() {
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\n***** Doubly Linked List Operations *****\n");
        printf("1. Insert Beginning\n");
        printf("2. Delete Beginning\n");
        printf("3. Insert End\n");
        printf("4. Delete End\n");
        printf("5. Insert Middle\n");
        printf("6. Delete Middle\n");
        printf("7. Display List\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;
            case 2:
                deleteBeginning();
                break;
            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertMiddle(value);
                break;
            case 6:
                deleteMiddle();
                break;
            case 7:
                displayList();
                break;
            case 8:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 8);

    return 0;
}
