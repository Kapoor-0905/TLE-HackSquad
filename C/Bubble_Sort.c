#include <stdio.h>

int main()
{
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    
    int ar[size];
    for(int x=0; x<size; x++){
        scanf("%d", &ar[x]);
    }
    
    for(int x=0; x<size-1; x++){
        for(int y=x+1; y<size; y++){
            if(ar[x] > ar[y]){
                int temp = ar[x];
                ar[x] = ar[y];
                ar[y] = temp;
            }
        }
    }
    
    printf("Sorted Array:\n");
    for(int x=0; x<size; x++){
        printf("%d\t", ar[x]);
    }
    return 0;
}

