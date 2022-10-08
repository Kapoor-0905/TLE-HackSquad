#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*head;

void display(struct Node* ptr){
    if(ptr==NULL){
        printf("List is empty");
    }
    else{
        while(ptr!=NULL){
            printf("%d\t",ptr->data);
            ptr = ptr->next;
        }
    }
    
}

void frontAdd(int n){
    struct Node *newNode;
    newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = n;
    newNode->next = head;
    head = newNode;
}

void endAdd(int n){
    struct Node *newNode, *temp;
    newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = n;
    newNode->next = NULL;
    temp=head;
    while(temp!=NULL && temp->next!=NULL){
        temp = temp->next;
    }
    temp->next= newNode;
}

void frontDelete(){
    head = head->next;
}

void endDelete(){
    if(head == NULL){
        printf("List is empty.");
    }
    else{
        struct Node *temp;
        temp = head;
        while(temp->next->next!=NULL){
            temp = temp->next;
        }
        temp->next = NULL;
    }
}

void count(struct Node *ptr){
    int c=0;
    while(ptr!=NULL){
        ptr = ptr->next;
        c++;
    }
    printf("\n%d",c);
}

void insert(int n, int index){
    struct Node *ptr, *newNode;
    ptr = head;
    newNode = (struct Node*) malloc(sizeof(struct Node));
    
    int count =1;
    while(count!=index){
        ptr = ptr->next;
        count++;
    }
    newNode->data = n;
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void main(){
    head = NULL;
    frontAdd(7);
    frontAdd(5);
    endAdd(1);
    frontAdd(2);
    endAdd(4);
    display(head);
    count(head);
    frontDelete();
    endDelete();
    printf("\n");
    display(head);
    count(head);
    insert(77, 2);
    printf("\n");
    display(head);
    count(head);
    int number, position;
    printf("\nEnter No and position: ");
    scanf("%d%d",&number, &position);
    insert(number,position);
    endAdd(number);
    frontAdd(number);
    display(head);
    printf("\n");
    count(head);
}
