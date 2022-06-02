#include<stdio.h>

int isLeap(int y)
{
    if(y % 400 == 0 || y % 4 == 0 && y % 100 != 0)
        return 1;
    else
        return 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int y;
        scanf("%d", &y);
        int diff = 0;
        if(isLeap(y))
        {
            while(1)
            {
                y++;
                if(isLeap(y))
                    diff += (366 % 7);
                else
                    diff += (365 % 7);
                if(diff % 7 == 0 && isLeap(y))
                    break;
            }
        }
        else
        {
            while(1)
            {
                y++;
                if(isLeap(y))
                    diff += (366 % 7);
                else
                    diff += (365 % 7);
                if(diff % 7 == 0 && !isLeap(y))
                    break;
            }
        }
        printf("%d\n", y);
    }
}
