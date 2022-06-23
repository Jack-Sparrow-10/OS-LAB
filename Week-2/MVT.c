#include<stdio.h>
int memory;

int main()
{
   int n;
   printf("\nEnter the Total Memory : ");
   scanf("%d",&memory);

   printf("Enter No.of Processes : ");
   scanf("%d",&n);
   int p[n];
   
   for(int i=0;i<n;i++)
   {
      printf("Enter the Memory Required for the Process#%d : ",(i+1));
      scanf("%d",&p[i]);
   }


   int mem_allocted[n];
   for(int i=0;i<n;i++)
   {
      if(p[i]<=memory)
      {
         mem_allocted[i]=1;
         memory-=p[i];
      }
      else
         mem_allocted[i]=0;
   }
   

   printf("\nProcess\t\t  Memory Required\t     Status\n");
   for(int i=0;i<n;i++)
   {
      if(mem_allocted[i])
         printf("Process#%d\t\t%d\t\t  Memory Alloted\n",(i+1),p[i]);
      else
         printf("Process#%d\t\t%d\t\t  Exceeds Memory\n",(i+1),p[i]);
   }
   if (memory)
        printf("\nExternal Fragmentation : %d\n\n\n",memory);
    else
        printf("\nNo External Fragmentation\n\n");
}
