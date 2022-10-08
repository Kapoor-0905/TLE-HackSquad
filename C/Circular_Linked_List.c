#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*head = NULL;

void frontAdd(int n){
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = n;
    if(head == NULL){
        head = newNode;
        newNode->next = head;
    }
    else{
        struct Node *ptr = head;
        while(ptr->next != head){
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void endAdd(int n){
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = n;
    if(head == NULL){
        head = newNode;
        newNode->next = head;
        struct Node *ptr = head;
        do{
            ptr = ptr->next;
        }while(ptr->next != head);
        ptr->next = head;
    }
    else{
        struct Node *ptr = head;
        do{
            ptr = ptr->next;
        }while(ptr->next != head);
        ptr->next = newNode;
        newNode->next = head;
    }
}

void frontDel(){
    if(head == NULL){
        printf("List is Empty!");
    }
    else if(head->next == head){
        head = NULL;
    }
    else{
        struct Node *ptr = head;
        do{
            ptr = ptr->next;
        }while(ptr->next != head);
        printf("%d\n", head->data);
        head = head->next;
        ptr->next = head;
    }
}

void endDel(){
    if(head == NULL){
        printf("List is Empty!");
    }
    else if(head->next == head){
        head = NULL;
    }
    else{
        struct Node *ptr = head;
        do{
            ptr = ptr->next;
        }while(ptr->next->next != head);
        printf("%d\n", ptr->next->data);
        ptr->next = head;
    }
}

void display(){
    if(head == NULL){
        printf("List is Empty!");
    }
    else{
        struct Node *ptr = head;
        do{
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }while(ptr != head);
        printf("\n");
    }
}

int main(){
    endAdd(7);
    endAdd(5);
    endAdd(1);
    frontAdd(4);
    display();
    frontDel();
    display();
    endDel();
    display();
    return 0;
}
