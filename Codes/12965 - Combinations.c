#include<stdio.h>
int n,m;
int arr[22];
int hasil[22];
void solve(int idx,int idxh)
{
    if(idxh==m)
    {
        for(int i=0;i<m;i++)
        {
            if(i!=0)
                printf(" ");
            printf("%d",hasil[i]);
        }
        printf("\n");
        return;
    }
    for(int i=idx;i<n;i++)
    {
        hasil[idxh]=arr[i];
        solve(i+1,idxh+1);
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    solve(0,0);
}
