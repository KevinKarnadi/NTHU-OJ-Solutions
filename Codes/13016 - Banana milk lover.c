#include<stdio.h>
#define ull unsigned long long
ull len[2000],sum[2000],max[2000];
int v[2000];
ull* x[2000];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%llu",&len[i]);
            x[i]=(ull*)malloc(len[i]*sizeof(ull));
            sum[i]=max[i]=0;
            v[i]=1;
            for(int j=0;j<len[i];j++)
            {
                scanf("%llu",&x[i][j]);
                sum[i]+=x[i][j];
                max[i]=x[i][j]>max[i] ? x[i][j]:max[i];
            }
        }
        for(int i=0;i<n;i++)
        {
            int id=-1;
            for(int j=0;j<n;j++)
            {
                if(v[j])
                {
                    if(id==-1)
                        id=j;
                    else if(sum[j]>sum[id])
                        id=j;
                    else if(sum[j]==sum[id] && max[j]>max[id])
                        id=j;
                    else if(sum[j]==sum[id] && max[j]==max[id] && len[j]>len[id])
                        id=j;
                }
            }
            v[id]=0;
            printf("%llu",x[id][0]);
            for(int j=1;j<len[id];j++)
                printf(" %llu",x[id][j]);
            printf("\n");
        }
        for(int i=0;i<n;i++)
            free(x[i]);
    }
}
