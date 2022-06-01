#include<stdio.h>

int main()
{
    double a,b;
    char x;

    scanf("%lf%c%lf",&a,&x,&b);
    if(x=='+')
    {
        printf("%.3lf",a+b);
    }
    else if(x=='-')
    {
        printf("%.3lf",a-b);
    }
    else if(x=='*')
    {
        printf("%.3lf",a*b);
    }
    else if(x=='/')
    {
        if(b==0)
        {
            printf("Error");
        }
        else
        {
            printf("%.3lf",a/b);
        }
    }
    printf("\n");
    return 0;
}
