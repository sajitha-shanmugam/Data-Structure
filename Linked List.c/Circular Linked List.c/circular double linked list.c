#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *tail = NULL, *newNode;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create the doubly circular linked list
    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);

        newNode->data = value;

        if (head == NULL) {
            // First node
            newNode->next = newNode->prev = newNode;
            head = tail = newNode;
        } else {
            // Insert at the end
            newNode->prev = tail;
            newNode->next = head;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode;
        }
    }

    // Display the list in forward direction
    printf("\nDoubly Circular Linked List (Forward): ");
    if (head != NULL) {
        struct Node* temp = head;
        do {
            printf("%d <-> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("(HEAD)\n");
    } else {
        printf("List is empty\n");
    }
    // Display the list in backward direction
printf("\nDoubly Circular Linked List (Backward): ");
if (tail != NULL) {
    struct Node* temp = tail;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    } while (temp != tail);
    printf("(TAIL)\n");
} else {
    printf("List is empty\n");
}


    return 0;
}
