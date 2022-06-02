#include<stdio.h>

int N;
int p[11][11];
int ways = 0;

void find(int row, int ctr)
{
    if(ctr == N)
    {
        ways++;
        return;
    }
    for(int col = 1; col <= N; col++)
    {
        int valid = 1;
        for(int i = row-1; i >= 1; i--)
        {
            if(p[i][col] == 1)
                valid = 0;
        }

        for(int i = row-1, j = col-1; i >= 1 && j >= 1; i--, j--)
        {
            if(p[i][j] == 1)
                valid = 0;
        }

        for(int i = row-1, j = col+1; i >= 1 && j <= N; i--, j++)
        {
            if(p[i][j] == 1)
                valid = 0;
        }

        if(valid)
        {
            p[row][col] = 1;
            find(row+1, ctr+1);
            p[row][col] = 0;
        }
    }
}

int main()
{
    scanf("%d", &N);
    find(1, 0);
    printf("%d", ways);
}
