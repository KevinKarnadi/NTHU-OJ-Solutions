#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int a[100][100],b[100][100];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d",&a[i][j]);
            b[i][j]=a[i][j];
        }
    }
    int q;
    scanf("%d",&q);
    q%=4;
    for(int x=0; x<q; x++)
    {
        int temp=n;
        n=m;
        m=temp;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                b[i][j]=a[m-1-j][i];
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                a[i][j]=b[i][j];
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(j!=0)
            {
                printf(" ");
            }
            printf("%d",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}
