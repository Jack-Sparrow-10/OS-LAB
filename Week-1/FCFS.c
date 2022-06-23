#include<stdio.h>
int main()
{
    int n,bt[25],tat[25],wt[25],i,j;

    printf("Enter The Number of Processes : ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter the Burst Time of process #%d : ",i+1);
        scanf("%d",&bt[i]);
    }

    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
    float avgwt=0,avgtat=0;
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnAround Time\n");
    for(i=0;i<n;i++)
    {
        tat[i]=wt[i]+bt[i];
        avgwt+=wt[i];
        avgtat+=tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
    }

    printf("Average Waiting Time : %.2f\n",avgwt/n);
    printf("Average TurnAround Time : %.2f\n",avgtat/n);
    
}