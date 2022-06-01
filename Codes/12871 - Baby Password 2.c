#include<stdio.h>

int main()
{
    char c,x;
    int d;
    scanf("%c %d",&c,&d);
    if(c>=65 && c<=90)
    {
        if(c-d>=65 && c-d<=90)
        {
            x=c-d+32;
        }
        else if(c-d<65)
        {
            x=91+(c-65)-d+32;
        }
        else if(c-d>90)
        {
            x=64-(90-c)-d+32;
        }
    }
    else if(c>=97 && c<=122)
    {
        if(c-d>=97 && c-d<=122)
        {
            x=c-d-32;
        }
        else if(c-d<97)
        {
            x=123+(c-97)-d-32;
        }
        else if(c-d>122)
        {
            x=96-(122-c)-d-32;
        }
    }
    printf("%c\n",x);
    return 0;
}
