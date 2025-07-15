#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

void print(Node *head){
    Node *temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

}
int main() {
    int n, val, a;
    Node *head = NULL, *tail, *newNode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newNode = malloc(sizeof(Node));
        printf("Enter data for node :");
        scanf("%d", &val);

        newNode->data = val;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    printf("Enter value to delete: ");
    scanf("%d", &a);

    temp = head;
    while (temp != NULL && temp->data != a) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found!\n");
    } else {
        if (temp == head) {
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
        } else if (temp->next == NULL) {
            temp->prev->next = NULL;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
    
    print(head);
    
    return 0;
}
