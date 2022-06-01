#include<stdio.h>

int main()
{
    int a,b,temp;
    scanf("%d %d",&a,&b);
    if(a>b)
    {
        temp=a;
        a=b;
        b=temp;
    }
    int x=0;
    for(int i=a; i>=1; i--)
    {
        if(a%i==0 && b%i==0 && i>x)
        {
            x=i;
        }
    }
    printf("%d\n",x);

    return 0;
}
