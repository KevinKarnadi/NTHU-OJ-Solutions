#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int max=2*n;
    int p[max][max];
    int i=0,j=0,stop=0;
    int num=1;
    char go='r';
    while(num<=pow(max,2))
    {
        if(go=='r')
        {
            p[i][j]=num;
            num++;
            j++;
            if(j>max-1-stop)
            {
                j--;
                i++;
                go='d';
            }
        }
        else if(go=='d')
        {
            p[i][j]=num;
            num++;
            i++;
            if(i>max-1-stop)
            {
                i--;
                j--;
                go='l';
            }
        }
        else if(go=='l')
        {
            p[i][j]=num;
            num++;
            j--;
            if(j<0+stop)
            {
                j++;
                i--;
                stop++;
                go='u';
            }
        }
        else if(go=='u')
        {
            p[i][j]=num;
            num++;
            i--;
            if(i<0+stop)
            {
                i++;
                j++;
                go='r';
            }
        }
    }
    for(int i=0;i<max;i++)
    {
        for(int j=0;j<max;j++)
        {
            if(j!=0)
            {
                printf(" ");
            }
            printf("%d",p[i][j]);
        }
        printf("\n");
    }
    return 0;
}
