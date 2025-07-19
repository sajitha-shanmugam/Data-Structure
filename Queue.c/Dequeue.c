#include <stdio.h>
#define SIZE 100

int queue[SIZE];
int front = -1, rear = -1;

int main() {
    int choice, value;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) { // Enqueue
            if (rear == SIZE - 1) {
                printf("Queue Overflow\n");
            } else {
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                if (front == -1) front = 0;
                rear++;
                queue[rear] = value;
                printf("%d enqueued\n", value);
            }

        } else if (choice == 2) { // Dequeue
            if (front == -1 || front > rear) {
                printf("Queue Underflow\n");
            } else {
                printf("%d dequeued\n", queue[front]);
                front++;
            }

        } else if (choice == 3) { // Display
            if (front == -1 || front > rear) {
                printf("Queue is empty\n");
            } else {
                printf("Queue elements: ");
                for (int i = front; i <= rear; i++) {
                    printf("%d ", queue[i]);
                }
                printf("\n");
            }

        } else if (choice == 4) {
            printf("Exiting...\n");
        } else {
            printf("Invalid choice\n");
        }

    } while (choice != 4);

    return 0;
}
