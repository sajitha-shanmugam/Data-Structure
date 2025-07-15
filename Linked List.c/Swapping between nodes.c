#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *temp, *node1 = NULL, *node2 = NULL;
    int n, val, a, b;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Creating the list
    for (int i = 0; i < n; i++) {
        struct Node* newNode = malloc(sizeof(struct Node));
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    // Display list before swap
    printf("Before Swap: ");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // Take values to swap
    printf("Enter two values to swap: ");
    scanf("%d %d", &a, &b);

    // Find the nodes with data a and b
    temp = head;
    while (temp != NULL) {
        if (temp->data == a)
            node1 = temp;
        else if (temp->data == b)
            node2 = temp;
        temp = temp->next;
    }

    // Swap data if both nodes found
    if (node1 && node2) {
        int t = node1->data;
        node1->data = node2->data;
        node2->data = t;

        // Display after swap
        printf("After Swap: ");
        temp = head;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    } else {
        printf("One or both values not found in the list.\n");
    }

    return 0;
}
