#include <stdio.h>
#define SIZE 100

int main() {
    int queue[SIZE];
    int front = -1, rear = -1;
    int choice, value;

    do {
        printf("\n1. Enqueue\n2. Display\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (rear == SIZE - 1) {
                printf("Queue Overflow\n");
            } else {
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                if (front == -1) {
                    front = 0;
                }
                rear++;
                queue[rear] = value;
                printf("%d enqueued to queue\n", value);
            }
        } else if (choice == 2) {
            if (front == -1 || front > rear) {
                printf("Queue is empty\n");
            } else {
                printf("Queue elements: ");
                for (int i = front; i <= rear; i++) {
                    printf("%d ", queue[i]);
                }
                printf("\n");
            }
        } else if (choice == 3) {
            printf("Exiting...\n");
        } else {
            printf("Invalid choice!\n");
        }

    } while (choice != 3);

    return 0;
}
