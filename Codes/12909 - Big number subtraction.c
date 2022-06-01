#include<stdio.h>
int main()
{
    int lena,lenb;
    scanf("%d",&lena);
    getchar();
    int a[100]= {0};
    for(int i=lena-1; i>=0; i--)
    {
        a[i]=getchar()-'0';
    }
    getchar();
    scanf("%d",&lenb);
    getchar();
    int b[100]= {0};
    for(int i=lenb-1; i>=0; i--)
    {
        b[i]=getchar()-'0';
    }
    int status=0;
    if(lena==lenb)
    {
        int c[lena];
        for(int i=lena-1; i>=0; i--)
        {
            if(a[i]>b[i])
            {
                status=1;
                break;
            }
            else if(b[i]>a[i])
            {
                status=2;
                break;
            }
        }
        if(status==1)
        {
            for(int i=0; i<lena; i++)
            {
                if(a[i]>=b[i])
                {
                    c[i]=a[i]-b[i];
                }
                else
                {
                    a[i]+=10;
                    a[i+1]-=1;
                    c[i]=a[i]-b[i];
                }
            }
            int start=0;
            for(int i=lena-1; i>=0; i--)
            {
                if(c[i]!=0)
                {
                    start=1;
                }
                if(start)
                {
                    printf("%d",c[i]);
                }
            }
        }
        else if(status==2)
        {
            for(int i=0; i<lenb; i++)
            {
                if(b[i]>=a[i])
                {
                    c[i]=b[i]-a[i];
                }
                else
                {
                    b[i]+=10;
                    b[i+1]-=1;
                    c[i]=b[i]-a[i];
                }
            }
            int start=0;
            printf("-");
            for(int i=lena-1; i>=0; i--)
            {
                if(c[i]!=0)
                {
                    start=1;
                }
                if(start)
                {
                    printf("%d",c[i]);
                }
            }
        }
        else
        {
            printf("0");
        }
    }
    else if(lena>lenb)
    {
        int c[lena];
        for(int i=0; i<lena; i++)
        {
            if(a[i]>=b[i])
            {
                c[i]=a[i]-b[i];
            }
            else
            {
                a[i]+=10;
                a[i+1]-=1;
                c[i]=a[i]-b[i];
            }
        }
        int start=0;
        for(int i=lena-1; i>=0; i--)
        {
            if(c[i]!=0)
            {
                start=1;
            }
            if(start)
            {
                printf("%d",c[i]);
            }
        }
    }
    else if(lenb>lena)
    {
        int c[lenb];
        for(int i=0; i<lenb; i++)
        {
            if(b[i]>=a[i])
            {
                c[i]=b[i]-a[i];
            }
            else
            {
                b[i]+=10;
                b[i+1]-=1;
                c[i]=b[i]-a[i];
            }
        }
        int start=0;
        printf("-");
        for(int i=lenb-1; i>=0; i--)
        {
            if(c[i]!=0)
            {
                start=1;
            }
            if(start)
            {
                printf("%d",c[i]);
            }
        }
    }
    return 0;
}
