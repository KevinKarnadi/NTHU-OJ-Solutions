#include <stdio.h>

int main()
{
    int X, Y, Z;
    scanf("%d %d %d", &X, &Y, &Z);

    int a, b, c;
    a = (X-Y+Z)/2;
    b = X-a;
    c = Z-a;

    printf("%d %d %d\n", a, b, c);

    return 0;
}
