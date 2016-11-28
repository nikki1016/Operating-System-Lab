#include<stdio.h>
int main(){
        printf("Enter the number of processes--- ");
        int n=0,i=0,j;
        scanf("%d",&n);
        int p[n],pr[n],bt[n],wt[n],tat[n];
        for(;i<n;i++){
                p[i]=i;
                printf("Enter the Burst time of process %d -- ",i);
                scanf("%d",&bt[i]);
                printf("System/User process (0/1) ? ---");
                scanf("%d",&pr[i]);
        }
        for(i=0;i<n;i++){
                for(j=0;j<n-i-1;j++){
                        if(pr[j]>pr[j+1]){
                                int temp=bt[j];
                                bt[j]=bt[j+1];
                                bt[j+1]=temp;
                                temp=p[j];
                                p[j]=p[j+1];
                                p[j+1]=temp;
                                temp=pr[j];
                                pr[j]=pr[j+1];
                                pr[j+1]=temp;
                        }
                }
        }
        int s=0;
        wt[0]=0;
        for(i=1;i<n;i++){
                s+=bt[i-1];
                wt[i]=s;
        }
        double tw=0.0,tt=0.0;
        for(i=0;i<n;i++){
                tat[i]=wt[i]+bt[i];
                tw+=wt[i];
                tt+=tat[i];
        }
        printf("PROCESS\tSYSTEM/USER PROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
        for(i=0;i<n;i++){
                printf("P%d\t%d\t\t\t%d\t\t\t%d\t\t%d\n",p[i],pr[i],bt[i],wt[i],tat[i]);
        }
        printf("Average Waiting time: %lf\n",tw/n);
        printf("Average Turnaround time: %lf\n",tt/n);
        return 0;
}
