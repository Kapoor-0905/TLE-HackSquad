#include <stdio.h>

void Hanoi(int n, int start, int end){
    if(n == 1){
        printf("move block %d from tower %d to tower %d\n", n, start, end);
    }
    else{
        int temp = 6 - start - end;
        Hanoi(n-1, start, temp);
        printf("move block %d from tower %d to tower %d\n", n, start, end);
        Hanoi(n-1, temp, end);
    }
}

int main(){
    int blocks;
    printf("Enter number of blocks in the tower of hanoi: ");
    scanf("%d", &blocks);
    Hanoi(blocks, 1, 3);
}
