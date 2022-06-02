#include<stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    char x[n + 1];
    scanf("%s", x);

    char data[26];
    for(int i = 0; i < 26; i++)
        data[i] = 'a' + i;

    while(m--)
    {
        char a, b;
        scanf(" %c %c", &a, &b);
        int idxA, idxB;
        for(int i = 0; i < 26; i++)
        {
            if(data[i] == a)
                idxA = i;
            if(data[i] == b)
                idxB = i;
        }
        char temp = data[idxA];
        data[idxA] = data[idxB];
        data[idxB] = temp;
    }

    for(int i = 0; i < n; i++)
        x[i] = data[x[i] - 'a'];
    puts(x);
}
