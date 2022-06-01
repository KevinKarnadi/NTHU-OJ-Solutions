#include<stdio.h>
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int ans=a;
    if(a>b)
    {
        int num=a;
        int start=1;
        while(start)
        {
            if(num%a==0 && num%b==0)
            {
                ans=num;
                start=0;
            }
            else
            {
                num++;
            }
        }
    }
    else if(b>a)
    {
        int num=b;
        int start=1;
        while(start)
        {
            if(num%a==0 && num%b==0)
            {
                ans=num;
                start=0;
            }
            else
            {
                num++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
