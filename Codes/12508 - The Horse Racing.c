#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[50];
    int b[50];
    int v[50];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        v[i]=1;
    }
    for(int i=0;i<n;i++)
        scanf("%d",&b[i]);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int idx=-1;
        int min=101;
        for(int j=0;j<n;j++)
        {
            if(v[j] && a[j]>b[i] && a[j]<min)
            {
                idx=j;
                min=a[j];
            }
        }
        if(idx>-1)
        {
            v[idx]=0;
            ans++;
        }
    }
    printf("%d",ans);
}
