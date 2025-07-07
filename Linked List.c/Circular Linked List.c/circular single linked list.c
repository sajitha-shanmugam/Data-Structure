#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create circular linked list
    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
            head->next = head;  // point to itself
        } else {
            temp->next = newNode;
            newNode->next = head; // last node points to head
            temp = newNode;
        }
    }

    // Display the circular linked list
    printf("\nSingly Circular Linked List: ");
    temp = head;
    if (head != NULL) {
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("HEAD\n");

    return 0;
}
