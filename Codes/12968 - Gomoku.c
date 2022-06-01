#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    char a[15][16];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<15; j++)
        {
            scanf("%s",a[j]);
        }
        char win='n';
        for(int i=0; i<15; i++)
        {
            for(int j=0; j<11; j++)
            {
                if(a[i][j]!='.' && a[i][j]==a[i][j+1] && a[i][j]==a[i][j+2] && a[i][j]==a[i][j+3] && a[i][j]==a[i][j+4])
                {
                    win=a[i][j];
                }
            }
        }
        if(win=='n')
        {
            for(int i=0; i<11; i++)
            {
                for(int j=0; j<15; j++)
                {
                    if(a[i][j]!='.' && a[i][j]==a[i+1][j] && a[i][j]==a[i+2][j] && a[i][j]==a[i+3][j] && a[i][j]==a[i+4][j])
                    {
                        win=a[i][j];
                    }
                }
            }
        }
        if(win=='n')
        {
            for(int i=0; i<11; i++)
            {
                for(int j=0; j<11; j++)
                {
                    if(a[i][j]!='.' && a[i][j]==a[i+1][j+1] && a[i][j]==a[i+2][j+2] && a[i][j]==a[i+3][j+3] && a[i][j]==a[i+4][j+4])
                    {
                        win=a[i][j];
                    }
                }
            }
        }
        if(win=='n')
        {
            for(int i=0; i<11; i++)
            {
                for(int j=4; j<15; j++)
                {
                    if(a[i][j]!='.' && a[i][j]==a[i+1][j-1] && a[i][j]==a[i+2][j-2] && a[i][j]==a[i+3][j-3] && a[i][j]==a[i+4][j-4])
                    {
                        win=a[i][j];
                    }
                }
            }
        }
        if(win=='n')
        {
            printf("none\n");
        }
        else if(win=='b')
        {
            printf("black\n");
        }
        else if(win=='w')
        {
            printf("white\n");
        }
    }
}
