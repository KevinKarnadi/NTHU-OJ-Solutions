#include<stdio.h>
int n;
char x[101];
int check()
{
    int ctr=0;
    for(int i=0;i<n;i++)
    {
        if(x[i]=='(')
            ctr++;
        else if(x[i]==')')
            ctr--;
        if(ctr<0)
            return 0;
    }
    if(ctr==0)
        return 1;
    else
        return 0;
}
unsigned long long solve(int a,int b)
{
    if(b==a+1)
        return 1;
    else
    {
        unsigned long long sum=0;
        for(int i=a;i<=b;i++)
        {
            int end=find(i);
            if(end==i+1)
                sum+=1;
            else
                sum+=2*solve(i+1,end-1);
            i=end;
        }
        return sum;
    }
}
int find(int idx)
{
    int ctr=0;
    for(int i=idx;i<n;i++)
    {
        if(x[i]=='(')
            ctr++;
        else if(x[i]==')')
            ctr--;
        if(ctr==0)
            return i;
    }
}
int main()
{
    scanf("%d",&n);
    scanf("%s",x);
    int valid=check();
    if(valid)
        printf("%llu\n",solve(0,n-1));
    else
        printf("Error\n");
}
