#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

void insertBeginning(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;

    if (head == NULL) {
        newNode->next = newNode;  // Circular reference to itself
        newNode->prev = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
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
    while (temp->next != head) {
        temp = temp->next;
    }

    if (temp == head) {
        free(head);
        head = NULL;
    } else {
        temp->next = head->next;
        head->next->prev = temp;
        free(head);
        head = temp->next;
    }

    printf("Element deleted from the beginning successfully.\n");
}

void insertEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;  // Circular reference to itself
        newNode->prev = newNode;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    newNode->next = head;
    head->prev = newNode;
    printf("Element inserted at the end successfully.\n");
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty. Cannot delete from the end.\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head) {
        free(head);
        head = NULL;
    } else {
        prev->next = temp->next;
        temp->next->prev = prev;
        free(temp);
    }

    printf("Element deleted from the end successfully.\n");
}

void insertAtPosition(int value, int position) {
    if (position < 1) {
        printf("Invalid position. Element not inserted.\n");
        return;
    }

    if (position == 1) {
        insertBeginning(value);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Invalid position. Element not inserted.\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != head) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;

    printf("Element inserted at position %d successfully.\n", position);
}

void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty. Cannot delete from the specified position.\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position. Element not deleted.\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    for (int i = 1; i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head) {
        if (temp->next == head) {
            free(head);
            head = NULL;
        } else {
            prev->next = temp->next;
            temp->next->prev = prev;
            free(temp);
            head = prev->next;
        }
    } else {
        prev->next = temp->next;
        temp->next->prev = prev;
        free(temp);
    }

    printf("Element deleted from position %d successfully.\n", position);
}

void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main() {
    int choice, value, position;

    do {
        printf("\n***** Circular Doubly Linked List Operations *****\n");
        printf("1. Insert Beginning\n");
        printf("2. Delete Beginning\n");
        printf("3. Insert End\n");
        printf("4. Delete End\n");
        printf("5. Insert at Position\n");
        printf("6. Delete at Position\n");
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
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insertAtPosition(value, position);
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
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
