#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Global variable for the head of the linked list
struct Node* head;

// Function to search for an element in the linked list
int search(int key) {
    struct Node* current = head;
    int position = 0;

    while (current != NULL) {
        if (current->data == key) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1; // Element not found
}

// Function to insert an element at a specified position in the linked list
void insert(int data, int position) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    // If the list is empty or the new node needs to be inserted at the head
    if (head == NULL || position == 0) {
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL) {
            head->prev = newNode;
        }

        head = newNode;
        return;
    }

    // Find the position to insert the new node
    struct Node* current = head;
    int currentPosition = 0;

    while (current != NULL && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    // If the position is beyond the end of the list, insert at the end
    if (current == NULL) {
        current = head;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newNode;
        newNode->prev = current;
        newNode->next = NULL;
    } else {
        // Insert the new node at the specified position
        newNode->next = current->next;
        newNode->prev = current;
        current->next = newNode;

        if (newNode->next != NULL) {
            newNode->next->prev = newNode;
        }
    }
}

// Function to insert an element at the end of the linked list
void insertAtEnd(int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    // Traverse to the last node
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Update the links
    current->next = newNode;
    newNode->prev = current;
}

// Function to delete an element from the linked list
void delete(int key) {
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == key) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            free(current);
            return;
        }
        current = current->next;
    }
}

// Function to print all elements in the linked list in reverse order
void printReverse() {
    struct Node* current = head;

    // Traverse to the last node
    while (current->next != NULL) {
        current = current->next;
    }

    // Traverse backwards and print each element
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }

    printf("\n");
}

// Function to print all elements in the linked list
void printList() {
    struct Node* current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

// Driver code
int main() {
    head = NULL;

    // Inserting elements into the linked list
    insert(23, 0);
    insert(52, 1);
    insert(19, 2);
    insert(9, 3);
    insertAtEnd(100);

    // Printing the linked list
    printf("Original linked list: ");
    printList();

    // Searching for an element
    int searchKey;
    printf("Enter an element to search: ");
    scanf("%d", &searchKey);
    int position = search(searchKey);
    if (position != -1) {
        printf("Element found at position %d\n", position);
    } else {
        printf("Element not found\n");
    }

    // Inserting an element in the middle
    int newData, insertPos;
    printf("Enter the element to insert: ");
    scanf("%d", &newData);
    printf("Enter the position to insert: ");
    scanf("%d", &insertPos);
    insert(newData, insertPos);

    // Printing the linked list after insertion
    printf("After insertion: ");
    printList();

    // Inserting an element at the head
    printf("Enter the element to insert at the head: ");
    scanf("%d", &newData);
    insert(newData, 0);

    // Printing the linked list after insertion
    printf("After insertion at the head: ");
    printList();

    // Inserting an element at the end
    printf("Enter the element to insert at the end: ");
    scanf("%d", &newData);
    insertAtEnd(newData);

    // Printing the linked list after insertion
    printf("After insertion at the end: ");
    printList();

    // Deleting an element from the middle
    int deleteData;
    printf("Enter the element to delete: ");
    scanf("%d", &deleteData);
    delete(deleteData);

    // Printing the linked list after deletion
    printf("After deletion: ");
    printList();

    // Deleting the head of the linked list
    delete(head->data);

    // Printing the linked list after deletion
    printf("After deleting the head: ");
    printList();

    // Deleting the last element of the linked list
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    delete(current->data);

    // Printing the linked list after deletion
    printf("After deleting the last element: ");
    printList();

    // Printing all elements in the linked list in reverse order
    printf("Reverse order: ");
    printReverse();

    return 0;
}
