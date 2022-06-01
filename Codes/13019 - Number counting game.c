#include<stdio.h>
int N,K;
char save[1100000];
int solve(int set,int sum)
{
    if(sum>=K)
        return save[set]=0;
    if(save[set]!=-1)
        return save[set];
    for(int i=0;i<N;i++)
    {
        if((set & (1<<i))==0)
        {
            int next=solve((set | (1<<i)),sum+i+1);
            if(next==0)
                return save[set]=1;
        }
    }
    return save[set]=0;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&N,&K);
        for(int i=0;i<(1<<N);i++)
            save[i]=-1;
        printf("%s\n",solve(0,0) ? "True":"False");
    }
}
