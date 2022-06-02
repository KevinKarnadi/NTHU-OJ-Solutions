#include<stdio.h>

int n, m, x;
int b[10][10];
long long ans;

void solve(int row, int ctrN, int ctrM)
{
    if(ctrN == n && ctrM == m)
    {
        ans++;
        return;
    }
    if(ctrN < n)
    {
        for(int col = 0; col < x; col++)
        {
            int valid = 1;
            for(int i = row - 1; i >= 0; i--)
                if(b[i][col])
                    valid = 0;
            for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
                if(b[i][j])
                    valid = 0;
            for(int i = row - 1, j = col + 1; i >= 0 && j < x; i--, j++)
                if(b[i][j])
                    valid = 0;
            if(valid)
            {
                b[row][col] = 1;
                solve(row + 1, ctrN + 1, ctrM);
                b[row][col] = 0;
            }
        }
    }
    if(ctrM < m)
    {
        for(int col = 0; col < x; col++)
        {
            int valid = 1;
            for(int i = row - 1; i >= 0; i--)
                if(b[i][col])
                    valid = 0;
            for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
                if(b[i][j] == 1)
                    valid = 0;
            for(int i = row - 1, j = col + 1; i >= 0 && j < x; i--, j++)
                if(b[i][j] == 1)
                    valid = 0;
            if(valid)
            {
                b[row][col] = 2;
                solve(row + 1, ctrN, ctrM + 1);
                b[row][col] = 0;
            }
        }
    }
}

int main()
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        x = n + m;
        ans = 0;
        solve(0, 0, 0);
        printf("%lld\n", ans);
    }
}
