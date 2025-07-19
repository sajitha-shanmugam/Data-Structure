#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *front = NULL, *rear = NULL, *temp, *newNode;
    int choice, value;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // Enqueue
            printf("Enter value to enqueue: ");
            scanf("%d", &value);

            newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = value;
            newNode->next = NULL;

            if (rear == NULL) {
                front = rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
            printf("%d enqueued\n", value);

        } else if (choice == 2) {
            // Dequeue
            if (front == NULL) {
                printf("Queue Underflow\n");
            } else {
                temp = front;
                printf("%d dequeued\n", temp->data);
                front = front->next;
                if (front == NULL)
                    rear = NULL;
                free(temp);
            }

        } else if (choice == 3) {
            // Peek
            if (front == NULL) {
                printf("Queue is empty\n");
            } else {
                printf("Front element: %d\n", front->data);
            }

        } else if (choice == 4) {
            // Display
            if (front == NULL) {
                printf("Queue is empty\n");
            } else {
                printf("Queue elements: ");
                temp = front;
                while (temp != NULL) {
                    printf("%d ", temp->data);
                    temp = temp->next;
                }
                printf("\n");
            }

        } else if (choice == 5) {
            printf("Exiting...\n");

        } else {
            printf("Invalid choice\n");
        }

    } while (choice != 5);

    return 0;
}
