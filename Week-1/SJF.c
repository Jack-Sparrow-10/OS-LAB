#include<stdio.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{
    int n;

    printf("Enter The Number of Processes : ");
    scanf("%d",&n);

    int bt[n],tat[n],wt[n],i,j,a[n];

    for(i=0;i<n;i++)
    {
        printf("Enter the Burst Time of process #%d : ",i+1);
        a[i]=i+1;
        scanf("%d",&bt[i]);
    }

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(bt[j]>bt[j+1])
                {
                    swap(&bt[j],&bt[j+1]);
                    swap(&a[j],&a[j+1]);
                }
        }
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
        printf("%d\t\t%d\t\t%d\t\t%d\n",a[i],bt[i],wt[i],tat[i]);
    }

    printf("Average Waiting Time : %.2f\n",avgwt/n);
    printf("Average TurnAround Time : %.2f\n",avgtat/n);
    
}