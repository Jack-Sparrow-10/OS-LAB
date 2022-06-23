#include<stdio.h>

typedef struct file
{
    char fname[40];
    int start,length;
}filetable;

int main()
{
    int nfiles,nblocks,avail,k=0;
    printf("Enter No.of Memory Blocks : ");
    scanf("%d",&nblocks);
    printf("Enter No.of Files : ");
    scanf("%d",&nfiles);

    int memory[nblocks];
    for(int i=0;i<nblocks;i++)
        memory[i]=-1;
    filetable ft[nfiles];

    for(int i=0;i<nfiles;i++)
    {
        printf("Enter the File Name %d: ",i+1);
        scanf("%s",&ft[i].fname);
        printf("Enter the Length of the File : ");
        scanf("%d",&ft[i].length);
        ft[i].start=-1;
    }

    for(int i=0;i<nfiles;i++)
    {
        avail=1;
        int len=ft[i].length;
        if(memory[k]==-1)
        {
            for(int j=k+1;j<=len;j++)
            {
                if(memory[j]!=-1)
                {
                    avail=0;
                    break;
                }
            }
            if(avail)
            {
                ft[i].start=k;
                for(int j=k;j<=len;j++)
                    memory[j]=i;
                k=(k+len);
            }
        }
        k=(k+1)%nblocks;
        printf("%d\n",k);

    }

    printf("\nFile-Name\tStart Index\tLength\t\tAllocated\n");
    for(int i=0;i<nfiles;i++)
    {
        if(ft[i].start!=-1)
        {
            printf("%s\t\t    %d\t\t  %d\t\t  Yes\n",ft[i].fname,ft[i].start,ft[i].length);
        }
        else
        {
            printf("%s\t\t    -\t\t  %d\t\t  No\n",ft[i].fname,ft[i].length);
        }
    }

}
