#include <stdio.h>

int main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    
    int time[n][4];
    
    printf("Enter process details: \nID\tBust\tArrival\t\tPriority\n");
    for(int x=0; x<n; x++){
        scanf("%d %d %d %d", &time[x][0], &time[x][1], &time[x][2], &time[x][3]);
    }
    
    for(int x=0; x<n; x++){
        for(int y=x+1; y<n-1; y++){
            if(time[x][3]<time[y][3]){
                
                int temp = time[x][0];
                time[x][0] = time[y][0];
                time[y][0] = temp;
                
                temp = time[x][1];
                time[x][1] = time[y][1];
                time[y][1] = temp;
                
                temp = time[x][2];
                time[x][2] = time[y][2];
                time[y][2] = temp;
                
                temp = time[x][3];
                time[x][3] = time[y][3];
                time[y][3] = temp;
            }
        }
    }
    
    printf("Process Schedule:\nID\tCompletion Time\n");
    int ct=0;
    for(int x=0; x<n; x++){
        ct+=time[x][1];
        printf("%d\t\t%d\n",time[x][0] ,ct);
    }
    
  return 0;
}
