#include<stdio.h>
int main()
{
    int lena;
    scanf("%d",&lena);
    getchar();
    int A[100]= {0};
    for(int i=lena-1; i>=0; i--)
    {
        A[i]=getchar()-48;
    }
    int lenb;
    getchar();
    scanf("%d",&lenb);
    getchar();
    int B[100]= {0};
    for(int i=lenb-1; i>=0; i--)
    {
        B[i]=getchar()-48;
    }
    int len=lena;
    if(lena>lenb)
    {
        len=lena;
    }
    else if(lenb>lena)
    {
        len=lenb;
    }
    int hasil[len];
    for(int i=0; i<len; i++)
    {
        if(i==len-1)
        {
            hasil[i]=A[i]+B[i];
        }
        else
        {
            if(A[i]+B[i]<10)
            {
                hasil[i]=A[i]+B[i];
            }
            else
            {
                hasil[i]=A[i]+B[i];
                hasil[i]-=10;
                A[i+1]+=1;
            }
        }
    }
    for(int i=len-1; i>=0; i--)
    {
        printf("%d",hasil[i]);
    }
    return 0;
}
