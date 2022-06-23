#include<stdio.h>
int main()
{
    int index,i,p[100],n;
    printf("Enter the Index block: ");
    scanf("%d",&index);
    printf("Enter the no.of files that are alloacted:");
    scanf("%d",&n);
    printf("Files that are already allocated");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    int n1,allocate=0;
    printf("Enter The blocks to be alloted : ");
    scanf("%d",&n1);
    i=0;
    while(i<n1+n)
    {
        for(int j=0;j<n;j++)
        {
        if(i==p[j])
        {
            allocate=1;
            i++;
        }
        }
        if(allocate==0)
        {
        printf("%d:%d Allocated\n",index,i);
        i++;
        }
        allocate=0;
    }
	
}