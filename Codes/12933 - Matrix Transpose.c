#include<stdio.h>

int main()
{
    int y,x;
    scanf("%d %d",&y,&x);
    int arr[y][x];
    for(int i=0; i<y; i++)
    {
        for(int j=0; j<x; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<y; j++)
        {
            if(j==y-1)
            {
                printf("%d\n",arr[j][i]);
            }
            else
            {
                printf("%d ",arr[j][i]);
            }
        }
    }

    return 0;
}
