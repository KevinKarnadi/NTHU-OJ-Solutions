#include<stdio.h>
int n;
int arr[6];
int hasil[6];
void solve(int idx)
{
    if(idx==n)
    {
        for(int i=0;i<n;i++)
            printf("%d ",hasil[i]);
        printf("\n");
        return;
    }
    for(int i=0;i<n;i++)
    {
        int yes=1;
        for(int j=0;j<idx;j++)
        {
            if(arr[i]==hasil[j])
                yes=0;
        }
        if(yes)
        {
            hasil[idx]=arr[i];
            solve(idx+1);
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        arr[i]=i+1;
    }
    solve(0);
}
