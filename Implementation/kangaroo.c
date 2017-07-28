#include <stdio.h>

int main(void)
{
	int x1 = 0, v1 = 0, x2 = 0, v2 = 0;
	int meet = 0;

	scanf("%ld%ld%ld%ld", &x1, &v1, &x2, &v2);

	if ((x1 < x2 && v1 < v2) || (x1 == x2 && ((v1 < v2) || (v2 < v1)))) {
		printf("NO\n");
		return 0;
	}

	if ((v1 > v2) && ((x2 - x1) % (v1 - v2)) == 0)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}
