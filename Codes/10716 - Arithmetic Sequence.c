#include <stdio.h>

int main()
{
	int a, n, d, un, sn;
	scanf("%d %d %d", &a, &n, &d);

	un = a+(n-1)*d;
	sn = n*(2*a+(n-1)*d)/2;

	printf("%d %d", un, sn);

	return 0;
}
