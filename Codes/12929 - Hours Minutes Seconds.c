#include<stdio.h>
int main()
{
    int M1,D1,h1,m1,s1;
    int M2,D2,h2,m2,s2;
    scanf("%d/%d",&M1,&D1);
    scanf("%d:%d:%d",&h1,&m1,&s1);
    scanf("%d/%d",&M2,&D2);
    scanf("%d:%d:%d",&h2,&m2,&s2);
    unsigned long long A,B,C;
    A=s1+m1*60+h1*60*60+D1*60*60*24+M1*60*60*24*30;
    B=s2+m2*60+h2*60*60+D2*60*60*24+M2*60*60*24*30;
    if(A<B)
    {
        int temp=A;
        A=B;
        B=temp;
    }
    C=A-B;
    int MM=0,DD=0,hh=0,mm=0,ss=0;
    while(C>=60*60*24*30)
    {
        C-=60*60*24*30;
        MM++;
    }
    while(C>=60*60*24)
    {
        C-=60*60*24;
        DD++;
    }
    while(C>=60*60)
    {
        C-=60*60;
        hh++;
    }
    while(C>=60)
    {
        C-=60;
        mm++;
    }
    ss=C;
    printf("%d %d\n",MM,DD);
    if(hh<10)
        printf("0%d:",hh);
    else
        printf("%d:",hh);
    if(mm<10)
        printf("0%d:",mm);
    else
        printf("%d:",mm);
    if(ss<10)
        printf("0%d",ss);
    else
        printf("%d",ss);
    printf("\n");
    return 0;
}
