#include<stdio.h>
int main()
{
    char a[101];
    scanf("%s",a);
    int arr[101];
    int x=strlen(a);
    for(int i=0; i<x; i++)
    {
        arr[i]=a[i]-'0';
    }
    int b[x];
    int no=0;
    int ctr=0;
    for(int i=x-1; i>=0; i--)
    {
        if(arr[i]==0)
        {
            b[ctr]=0;
        }
        else if(arr[i]==1)
        {
            b[ctr]=1;
        }
        else if(arr[i]==6)
        {
            b[ctr]=9;
        }
        else if(arr[i]==8)
        {
            b[ctr]=8;
        }
        else if(arr[i]==9)
        {
            b[ctr]=6;
        }
        else
        {
            no=1;
            break;
        }
        ctr++;
    }
    if(no)
    {
        printf("No");
    }
    else
    {
        int start=0;
        for(int i=0; i<x; i++)
        {
            if(b[i]!=0)
            {
                start=1;
            }
            if(start)
            {
                printf("%d",b[i]);
            }
        }
    }
    printf("\n");
    return 0;
}
