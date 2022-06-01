#include<stdio.h>

int p[5][5];
int m[5][5];
int same;
int y[4] = {1, -1, 0, 0};
int x[4] = {0, 0, 1, -1};

void reset()
{
    same = 1;
    for(int i = 1; i <= 4; i++)
        for(int j = 1; j <= 4; j++)
            m[i][j] = p[i][j];
}

void solve()
{
    reset();
    for(int c = 1; c <= 4; c++)
        move(1, c, 0);
    if(same)
        printf("Invalid\n");
    else
        print();


    reset();
    for(int c = 1; c <= 4; c++)
        move(4, c, 1);
    if(same)
        printf("Invalid\n");
    else
        print();


    reset();
    for(int r = 1; r <= 4; r++)
        move(r, 1, 2);
    if(same)
        printf("Invalid\n");
    else
        print();


    reset();
    for(int r = 1; r <= 4; r++)
        move(r, 4, 3);
    if(same)
        printf("Invalid\n");
    else
        print();
}

void move(int r, int c, int d)
{
    int dy = y[d];
    int dx = x[d];
    for(int i = 0; i < 4; i++)
    {
        if(m[r + dy*i][c + dx*i] == 0)
        {
            for(int j = i+1; j < 4; j++)
            {
                if(m[r + dy*j][c + dx*j] != 0)
                {
                    same = 0;
                    m[r + dy*i][c + dx*i] = m[r + dy*j][c + dx*j];
                    m[r + dy*j][c + dx*j] = 0;
                    i--;
                    break;
                }
            }
        }
        else
        {
            for(int j = i+1; j < 4; j++)
            {
                if(m[r + dy*i][c + dx*i] == m[r + dy*j][c + dx*j])
                {
                    same = 0;
                    m[r + dy*i][c + dx*i] *= 2;
                    m[r + dy*j][c + dx*j] = 0;
                    break;
                }
                else if(m[r + dy*j][c + dx*j] != 0)
                    break;
            }
        }
    }
}

void print()
{
    for(int i = 1; i <= 4; i++)
        for(int j = 1; j <= 4; j++)
            printf("%d%c", m[i][j], j == 4 ? '\n' : ' ');
}

int main()
{
    while(1)
    {
        int stop = 0;
        for(int i = 1; i <= 4; i++)
            for(int j = 1; j <= 4; j++)
                if(scanf("%d", &p[i][j]) == EOF)
                {
                    stop = 1;
                    i = 5, j = 5;
                }

        if(stop)
            break;

        solve();
    }
}
