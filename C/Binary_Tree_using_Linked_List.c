#include <stdlib.h>
#include <stdio.h>

struct Tree{
    int data;
    struct Tree * left;
    struct Tree * right;
}*root;

void plant(){
    struct Tree *branch = (struct Tree*) malloc(sizeof(struct Tree));
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    branch->data = n;
    root = branch;
    struct Tree *ptr = root;
    struct Tree *pre = root;
    char choice;
    printf("Enter: -1 -> left Node, 1 -> right node, 0 -> parent node, 2 -> exit\n");
    do{
        struct Tree *newBranch = (struct Tree*) malloc(sizeof(struct Tree));
        printf("Enter choice: ");
        scanf("%c", &choice);
        if(choice == -1){
            printf("Enter Number: ");
            scanf("%d", &n);
            newBranch->data = n;
            ptr->left = newBranch;
            pre = ptr;
            ptr = ptr->left;
            
        }
        else if(choice == 1){
            printf("Enter Number: ");
            scanf("%d", &n);
            newBranch->data = n;
            ptr->right = newBranch;
            pre = ptr;
            ptr = ptr->right;
            
        }
        else if(choice == 2){
            printf("Tree planted successfully!");
        }
        else{
            ptr = pre;
        }
    }while(choice == 'E');
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
    plant();
    printf("Pre-Order: ");
    preOrder(root);
    printf("\nIn-Order: ");
    inOrder(root);
    printf("\nPost-Order: ");
    postOrder(root);
}
