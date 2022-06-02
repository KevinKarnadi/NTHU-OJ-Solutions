#include<stdio.h>

int n;
char s[10001];
char b[100][100];
char str[11] = "ICPCASIASG";
int found = 0;

void solve(int idx, int y, int x)
{
    if(idx == 10)
    {
        found = 1;
        return;
    }
    if(idx == 0)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(b[i][j] == str[0])
                    solve(idx + 1, i, j);
    }
    else
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(b[i][j] == str[idx] && pow(y - i, 2) + pow(x - j, 2) == 5)
                    solve(idx + 1, i, j);
    }
}

int main()
{
    scanf("%d", &n);
    scanf("%s", s);
    int idx = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            b[i][j] = s[idx++];
    solve(0, 0, 0);
    if(found)
        printf("YES\n");
    else
        printf("NO\n");
}
