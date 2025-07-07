// Online C compiler to run C program online
#include <stdio.h>
#include  <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
    
}node;

int main(){
    int n,value;
    struct node *head = NULL,*tail = NULL,*newNode;
    
    printf("Enter no of nodes:");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        newNode = (struct node*) malloc (sizeof(struct node));
        
        if(newNode == NULL){
            printf("Error in memory allocation\n");
            return 1;
        }
        printf("Enter data %d: ",i+1);
        scanf("%d",&value);
        
        newNode -> data = value;
        newNode -> prev = NULL;
        newNode -> next = NULL;
        
        if(head==NULL){
            head = tail = newNode;
        }else{
            tail -> next = newNode;
            newNode-> prev = tail;
            tail = newNode;
        }
    }
    printf("Forward:");
    struct node* temp = head;
    while(temp!=NULL){
        printf("%d <->",temp->data);
        temp = temp -> next;
    }
    printf("NULL\n");
// Print backward
printf("\nBackward: ");
temp = tail;
while (temp != NULL) {
    printf("%d <-> ", temp->data);
    temp = temp->prev;
}
printf("NULL\n");

    return 0;
}
