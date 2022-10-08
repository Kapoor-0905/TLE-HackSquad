#include <stdio.h>

void main(){
    int size;
    printf("Enter size of array: ");
    scanf("%d",&size);
    int ar[size];
    printf("Enter array elements:\n");
    for(int x=0; x<size; x++){
        scanf("%d",&ar[x]);
    }
    
    int num;
    printf("Enter number to be searched: ");
    scanf("%d",&num);
    
    int min = 0, max = size-1, found = 0;
    while(min <= max){
        int mid = (min + max)/2;
        if(ar[mid] == num){
            printf("Number found!");
            found = 1;
            break;
        }
        else if(num < num){
            min = mid + 1;
        }
        else{
            max = mid - 1;
        }
    }
    if(found == 0){
        printf("Number not found!");
    }
}


