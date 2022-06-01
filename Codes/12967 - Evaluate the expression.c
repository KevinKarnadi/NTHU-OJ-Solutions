#include<stdio.h>
int main()
{
    char a[100001];
    scanf("%s",a);
    int x=strlen(a)-1;
    int num=0,power=0;
    long long sum=0,sumx=0;
    while(x>-1)
    {
        if(a[x]>='0' && a[x]<='9')
        {
            num=num+(a[x]-48)*pow(10,power);
            power++;
        }
        else if(a[x]=='+')
        {
            sum+=num;
            num=0;
            power=0;
        }
        else if(a[x]=='-')
        {
            sum-=num;
            num=0;
            power=0;
        }
        else if(a[x]==')')
        {
            sumx=0;
            while(a[x]!='(')
            {
                if(a[x]>='0' && a[x]<='9')
                {
                    num=num+(a[x]-48)*pow(10,power);
                    power++;
                }
                else if(a[x]=='+')
                {
                    sumx+=num;
                    num=0;
                    power=0;
                }
                else if(a[x]=='-')
                {
                    sumx-=num;
                    num=0;
                    power=0;
                }
                x--;
            }
            sumx+=num;
            num=sumx;
        }
        x--;
    }
    sum+=num;
    printf("%lld\n",sum);
    return 0;
}
