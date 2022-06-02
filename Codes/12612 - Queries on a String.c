#include<stdio.h>

int main()
{
    char s[10005];
    scanf("%s", s);

    int m;
    scanf("%d", &m);
    while(m--)
    {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        l--;
        r--;
        k = k % (r - l + 1);
        while(k--)
        {
            char temp = s[r];
            for(int i = r; i > l; i--)
                s[i] = s[i-1];
            s[l] = temp;
        }
    }
    puts(s);
}
