#include<stdio.h>
struct node{
    unsigned dist[20];
    unsigned from[20];
}rt[20];

int main(){
    int c[20][20];
    int i, j ,k ,n, count=0;
    printf("Enter the no of nodes:");
    scanf("%d",&n);
    printf("\n Enter the cost matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            c[i][j]=0;
            scanf("%d",&c[i][j]);
            rt[i].dist[j] = c[i][j];
            rt[i].from[j] = j;
        }
    }
    do{
        count=0;
        for (i=0;i<n;i++)
        for(j=0;j<n;j++)
        for(k=0;k<n;k++)
        if(rt[i].dist[j] > c[i][k] + rt[k].dist[j]){
            rt[i].dist[j] = rt[i].dist[k]+rt[k].dist[j];
            rt[i].from[j] = k;
            count++;
        }
    }while(count!=0);
    
    for(i=0;i<n;i++){
        printf("\n\nFor router %d\n",i+1);
        for(j=0;j<n;j++){
            printf("\t\nnode %d via %d distance %d",j+1,rt[i].from[j]+1,rt[i].dist[j]);
        }
    }
    printf("\n\n");
}
