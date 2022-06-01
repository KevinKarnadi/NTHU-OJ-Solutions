#include<stdio.h>
int n,m;
long long w[20],v[20];
long long ans=0;
void solve(int idx,long long weight,long long val)
{
    if(val>ans)
        ans=val;
    for(int i=idx;i<n;i++)
    {
        if(weight+w[i]<=m)
            solve(i+1,weight+w[i],val+v[i]);
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%lld %lld",&w[i],&v[i]);
    solve(0,0,0);
    printf("%lld\n",ans);
}
