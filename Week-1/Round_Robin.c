#include<stdio.h>
int main()
{
    int n;
    printf("Enter the no.of Processes : ");
    scanf("%d",&n);

    int wt[n],bt[n],tat[n],run_q[n],count=0,qt,time=0,i;
    float avgwt=0,avgtat=0;

    for(i=0;i<n;i++)
    {
        printf("Enter the Burst time of Process#%d : ",(i+1));
        scanf("%d",&bt[i]);
        run_q[i]=bt[i];
    }

    
    printf("Enter the Quantum Time : ");
    scanf("%d",&qt);

    while(count!=n)
    {
        for(i=0,count=0;i<n;i++)
        {
            if(run_q[i]==0)
            {
                count++;
                continue;
            }
            if(run_q[i]>qt)
            {
                run_q[i]-=qt;
                time+=qt;
                tat[i]=time;
            }
                
            else if(run_q[i]>0)
            {
                time+=run_q[i];
                tat[i]=time;
                run_q[i]=0;
            }
            
        }
    }

    printf("\nProcess\t\t\tBurst Time\tWaiting Time\tTurnAround Time\n");
    for(i=0;i<n;i++)
    {
        wt[i]=tat[i]-bt[i];
        avgtat+=tat[i];
        avgwt+=wt[i];
        printf("Process#%d\t\t%d\t\t%d\t\t%d\n",(i+1),bt[i],wt[i],tat[i]);
    }

    printf("\nAverage Turn-Around Time = %.2f\n",avgtat/n);
    printf("Average Waiting Time = %.2f\n\n",avgwt/n);
}