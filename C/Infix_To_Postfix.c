#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[20];
int top = -1;

void push(char ch){
    if(top>=19){
        printf("Overflow");
    }
    else{
        top++;
        stack[top] = ch;
    }
}

void pop(){
    if(top == -1){
        printf("Underflow");
    }
    else{
        printf("%c ",stack[top]);
        top--;
    }
}

void main(){
    char str[20];
    printf("Enter string: ");
    scanf("%s",str);
    
    for(int x=0; x<10; x++){
        if(str[x]=='('){
            push(str[x]);
        }
        else if(str[x]==')'){
            while(stack[top]!='('){
                pop();
            }
        }
        else if((str[x]>='0' && str[x]<='9') || (str[x]>='A' && str[x]<='Z') || (str[x]>='a' && str[x]<='z')){
            printf("%c ",str[x]);
        }
        else{
            if(stack[top]=='('){
                push(str[x]);
            }
            else if((str[x]=='+'||str[x]=='-') && (stack[top]=='*'||stack[top]=='/')){
                pop();
                push(str[x]);
            }
            else if((str[x]=='*'||str[x]=='/') && (stack[top]=='+'||stack[top]=='-')){
                push(str[x]);
            }
            else if((str[x]=='+'||str[x]=='-') && (stack[top]=='+'||stack[top]=='-')){
                pop();
                push(str[x]);
            }
            else if((str[x]=='*'||str[x]=='/') && (stack[top]=='*'||stack[top]=='/')){
                pop();
                push(str[x]);
            }
        }
    }
    while(top!=-1){
        if(stack[top]!='(' && stack[top]!=')'){
            pop();
        }
        else{
            top--;
        }
    }
}
