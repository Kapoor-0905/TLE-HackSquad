#include <stdlib.h>
#include <stdio.h>

struct Tree{
    int data;
    struct Tree * left;
    struct Tree * right;
}*root = NULL;

struct Tree* plant(){
    struct Tree *branch = (struct Tree*) malloc(sizeof(struct Tree));
    printf("Enter Number: ");
    scanf("%d", &branch->data);
    int choice;
    printf("Do you want to create Left Node: ");
    scanf("%d", &choice);
    if(choice == 1){
        branch->left = plant();
    }
    else{
        branch->left = NULL;
    }
    printf("Do you want to create Right Node: ");
    scanf("%d", &choice);
    if(choice == 1){
        branch->right = plant();
    }
    else{
        branch->right = NULL;
    }
    return branch;
}

void preOrder(struct Tree *ptr){
    if(ptr != NULL){
        printf("%d\t", ptr->data);
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
}

void postOrder(struct Tree *ptr){
    if(ptr != NULL){
        postOrder(ptr->left);
        postOrder(ptr->right);
        printf("%d\t", ptr->data);
    }
}

void inOrder(struct Tree *ptr){
    if(ptr != NULL){
        inOrder(ptr->left);
        printf("%d\t", ptr->data);
        inOrder(ptr->right);
    }
}

int main()
{
    root = plant();
    printf("Pre-Order: ");
    preOrder(root);
    printf("\nIn-Order: ");
    inOrder(root);
    printf("\nPost-Order: ");
    postOrder(root);
}

