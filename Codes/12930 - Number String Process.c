#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    char a[n+1];
    scanf("%s",a);
    int num[n];
    for(int i=0;i<n;i++)
    {
        num[i]=a[i]-48;
    }
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int a,b,sz;
        unsigned long long A=0,B=0;
        scanf("%d %d %d",&a,&b,&sz);
        for(int j=a;j<a+sz;j++)
        {
            A=A*10+num[j];
        }
        for(int j=b;j<b+sz;j++)
        {
            B=B*10+num[j];
        }
        printf("%llu\n",A*B);
        for(int j=a;j<n;j++)
        {
            num[j]=num[j+1*sz];
        }
        b-=sz;
        for(int j=b;j<n;j++)
        {
            num[j]=num[j+1*sz];
        }
        n-=2*sz;
    }
    return 0;
}
