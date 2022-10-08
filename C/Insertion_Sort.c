 #include <stdio.h>
 
 int main(){
     int size;
     printf("Enter Array Size: ");
     scanf("%d", &size);
     
     int ar[size];
     for(int x=0; x<size; x++){
         scanf("%d", &ar[x]);
     }
     
     
     for(int x=0; x<size-1; x++){
        for(int y=x+1; y>0; y--){
            if(ar[y] < ar[y-1]){
                int temp = ar[y];
                ar[y] = ar[y-1];
                ar[y-1] = temp;
            }
            else{
                break;
            }
        }
     }
     
     
     printf("Sorted Array:\n");
     for(int x=0; x<size; x++){
         printf("%d\t", ar[x]);
     }
     return 0;
 }
