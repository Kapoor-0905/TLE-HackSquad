#include <stdio.h>

int main(){
    int size;
    printf("Enter size of array: ");
    scanf("%d",&size);
    int ar[size];
    printf("Enter array elements:\n");
    for(int x=0; x<size; x++){
        scanf("%d",&ar[x]);
    }
    
    for(int x=0; x<size-1; x++){
        int index = x;
        for(int y=x+1;  y<size; y++){
            if(ar[index]>ar[y]){
                index = y;
            }
        }
        int temp = ar[x];
        ar[x] = ar[index];
        ar[index] = temp;
    }
    
    printf("Sorted Array:\n");
    for(int x=0; x<size; x++){
        printf("%d\t", ar[x]);
    }
    return 0;
}
