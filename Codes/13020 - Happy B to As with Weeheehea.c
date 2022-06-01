#include<stdio.h>
#define swap(a, b){a^=b^=a^=b;}

int N, K;
char p[3][4];
int cnt[20000];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int ways = 0;

int encode(char p[3][4])
{
    int ret = 0;
    int power = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            ret += (p[i][j] == 'x' ? 2 : p[i][j]-'0') * pow(3, power++);
    return ret;
}

void find(int steps, int y, int x)
{
    if(steps > K)
        return;
    int enc = encode(p);
    if(cnt[enc] != 0)
    {
        ways +=  cnt[enc];
        cnt[enc] = 0;
    }
    for(int d = 0; d < 4; d++)
    {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if(ny >= 0 && ny <= 2 && nx >= 0 && nx <= 2)
        {
            swap(p[y][x], p[ny][nx]);
            find(steps+1, ny, nx);
            swap(p[y][x], p[ny][nx]);
        }
    }
}

int main()
{
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N+1; i++)
    {
        for(int j = 0; j < 3; j++)
            scanf("%s", p[j]);
        if(i < N)
        {
            int enc = encode(p);
            cnt[enc]++;
        }
    }
    int y, x;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(p[i][j] == 'x')
                y = i, x = j;
    find(0, y, x);
    printf("%d\n", ways);
}
