#include<stdio.h>
void hanoi(int n,char a,char b,char c)
{
    if(n==0)
        return;
    hanoi(n-1,a,c,b);
    printf("move disk %d from rod %c to rod %c\n",n,a,c);
    hanoi(n-1,b,a,c);
}
int main()
{
    int n;
    scanf("%d",&n);
    hanoi(n,'A','B','C');
}
