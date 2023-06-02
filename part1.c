#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int value;
    struct Node* next;
};

// Function to search for an element in the linked list
int searchElement(struct Node* head, int key) {
    struct Node* current = head;
    int position = 0;

    while (current != NULL) {
        if (current->value == key) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1;
}

// Function to insert an element at a given position in the linked list
void insertAtPosition(struct Node** head, int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;

    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        int currentPosition = 0;

        while (current != NULL && currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }

        if (current == NULL) {
            printf("Invalid position.\n");
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to insert an element at the head of the linked list
void insertAtHead(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
}

// Function to insert an element at the end of the linked list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newNode;
    }
}

// Function to delete an element from the linked list
void deleteElement(struct Node** head, int key) {
    struct Node* current = *head;
    struct Node* prev = NULL;

    // Handle deletion at the head
    if (current != NULL && current->value == key) {
        *head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->value != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element not found.\n");
        return;
    }

    prev->next = current->next;
    free(current);
}

// Function to delete the last element from the linked list
void deleteLastElement(struct Node** head) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    free(current);
}

// Function to print all elements in the linked list
void printLinkedList(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");
}

// Test the linked list implementation
int main() {
    struct Node* head = NULL;

    // Insert elements
    insertAtEnd(&head, 23);
    insertAtEnd(&head, 52);
    insertAtEnd(&head, 19);
    insertAtEnd(&head, 9);
    insertAtEnd(&head, 100);

    // Print all elements
    printf("Linked list: ");
    printLinkedList(head);

    // Search for an element
    int searchKey;
    printf("Enter the element to search: ");
    scanf("%d", &searchKey);
    int position = searchElement(head, searchKey);
    if (position != -1) {
        printf("Element found at position %d.\n", position);
    } else {
        printf("Element not found.\n");
    }

    // Insert an element at a given position
    int insertValue, insertPosition;
    printf("Enter the element to insert: ");
    scanf("%d", &insertValue);
    printf("Enter the position to insert: ");
    scanf("%d", &insertPosition);
    insertAtPosition(&head, insertValue, insertPosition);

    // Print all elements
    printf("Linked list after insertion: ");
    printLinkedList(head);

    // Insert an element at the head
    int insertHeadValue;
    printf("Enter the element to insert at the head: ");
    scanf("%d", &insertHeadValue);
    insertAtHead(&head, insertHeadValue);

    // Print all elements
    printf("Linked list after inserting at the head: ");
    printLinkedList(head);

    // Insert an element at the end
    int insertEndValue;
    printf("Enter the element to insert at the end: ");
    scanf("%d", &insertEndValue);
    insertAtEnd(&head, insertEndValue);

    // Print all elements
    printf("Linked list after inserting at the end: ");
    printLinkedList(head);

    // Delete an element
    int deleteKey;
    printf("Enter the element to delete: ");
    scanf("%d", &deleteKey);
    deleteElement(&head, deleteKey);

    // Print all elements
    printf("Linked list after deletion: ");
    printLinkedList(head);

    // Delete the last element
    deleteLastElement(&head);

    // Print all elements
    printf("Linked list after deleting the last element: ");
    printLinkedList(head);

    return 0;
}
