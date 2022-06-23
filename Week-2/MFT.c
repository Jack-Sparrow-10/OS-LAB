#include<stdio.h>
int memory,blocks,block_size;

int main()
{
   int n;
   printf("\nEnter the Total Memory : ");
   scanf("%d",&memory);

   printf("Enter the size of blocks : ");
   scanf("%d",&block_size);

   printf("Enter the No.of blocks : ");
   scanf("%d",&blocks);

   printf("Enter No.of Processes : ");
   scanf("%d",&n);
   int p[n];
   
   for(int i=0;i<n;i++)
   {
      printf("Enter the Memory Required for the Process#%d : ",(i+1));
      scanf("%d",&p[i]);
   }


   int mem_allocted[n],internal_fragment=0,j=0;
   for(int i=0;i<n;i++)
   {
      if(p[i]<=block_size && j<blocks)
      {
         mem_allocted[i]=1;
         internal_fragment+=(block_size)-p[i];
         j++;
      }
      else
         mem_allocted[i]=0;
   }
   

   printf("\nProcess\t\tMemory Required\t\tMemory Alloted\t\tInternal Fragmentation\n");
   for(int i=0;i<n;i++)
   {
      if(mem_allocted[i])
         printf("Process#%d\t\t%d\t\t\tYes\t\t\t %d\n",(i+1),p[i],(block_size-p[i]));
      else
         printf("Process#%d\t\t%d\t\t\tNo\t\t   Exceeding Memory\n",(i+1),p[i]);
   }
    printf("\nExternal Fragmentation : %d\n\n\n",internal_fragment+memory-(block_size*blocks));

}
