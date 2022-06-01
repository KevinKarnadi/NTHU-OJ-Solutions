#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        l--;
        r--;
        int ans=a[l];
        int ctr[501]={0};
        for(int j=l;j<=r;j++)
        {
            ctr[a[j]]++;
            if(ctr[a[j]]>ctr[ans] || (ctr[a[j]]==ctr[ans] && a[j]<ans))
            {
                ans=a[j];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
