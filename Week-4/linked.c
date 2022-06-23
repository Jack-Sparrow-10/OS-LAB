#include<stdio.h>
int main()
{
    int b[100],bi,i,n;
    printf("Enter number of blocks already allocated");
    scanf("%d",&n);
    printf("Enter Blocks that are already allocated:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    int len,st;
    printf("Enter start index: ");
    scanf("%d",&st);
    printf("Enter len: ");
    scanf("%d",&len);
    int j,allocate,len1=len+st,cnt=0;
    for(i=st;cnt<len1-1;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==b[j])
                {
                    printf("%d Block is already allocated\n",i);
                    allocate=1;
                }
        }
        if(allocate==0)
        {
            printf("%d Allocated %d\n",i,1);
            j++;
            cnt++;
        }
        allocate=0;
    }
}