#include <stdio.h>
#define size 5

int queue[size], front = -1, rear = -1;

void enQueue(int n){
    if((rear+1)%size == front){
        printf("Queue is Full\n");
    }
    else{
        if(rear == -1){
            front++;
            queue[++rear] = n;
        }
        else{
            rear = (rear+1) % size;
            queue[rear] = n;
        }
    }
}

void deQueue(){
    if(front == -1){
        printf("Queue is empty\n");
    }
    else if(front == rear){
        printf("Element: %d\n", queue[front]);
        front = rear = -1;
    }
    else{
        printf("Element: %d\n", queue[front]);
        front = (front+1) % size;
    }
}

void display(){
    if(front == -1){
        printf("Queue is Empty!\n");
    }
    else{
        int index = front;
        while(index != rear){
            printf("%d\t", queue[index]);
            index = (index+1) % size;
        }
        printf("%d\n", queue[rear]);
    }
}

void main(){
    enQueue(7);
    enQueue(5);
    enQueue(1);
    display();
    deQueue();
    deQueue();
    display();
    enQueue(7);
    enQueue(5);
    enQueue(1);
    enQueue(4);
    display();
    enQueue(6);
}
