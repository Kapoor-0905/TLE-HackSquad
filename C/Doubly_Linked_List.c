#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next, *prev;
}*head  = NULL;

void frontAdd(int n){
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = n;
    newNode->prev = NULL;
    if(head == NULL){
        newNode->next = NULL;
        head = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
}

void endAdd(int n){
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = n;
    newNode->next = NULL;
    if(head == NULL){
        newNode->prev = NULL;
        head = newNode;
    }
    else{
        struct Node *ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->prev = ptr;
    } 
}

void frontDel(){
    if(head == NULL){
        printf("List is Empty!");
    }
    else{
        printf("%d\n", head->data);
        head = head->next;
        head->prev = NULL;
    }
}

void endDel(){
    if(head == NULL){
        printf("List is Empty!");
    }
    else{
        struct Node *ptr = head;
        while(ptr->next->next != NULL){
            ptr = ptr->next;
        }
        printf("%d\n", ptr->next->data);
        ptr->next = NULL;
    }
}

void insert(int n, int i){
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = n;
    int index = 0;
    struct Node *ptr = head;
    while(index < i){
        ptr = ptr->next;
        index++;
    }
    struct Node *temp = ptr->next;
    newNode->next = temp;
    temp->prev = newNode;
    ptr->next = newNode;
    newNode->prev = ptr;
}

void display(){
    if(head == NULL){
        printf("List is Empty!");
    }
    else{
        struct Node *ptr = head;
        while(ptr != NULL){
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main(){
    frontAdd(7);
    frontAdd(5);
    frontAdd(1);
    endAdd(5);
    endAdd(1);
    display();
    frontDel();
    display();
    endDel();
    display();
    insert(7, 1);
    insert(7, 3);
    display();
    return 0;
}
