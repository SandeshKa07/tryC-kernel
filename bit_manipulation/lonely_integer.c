#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int lonelyinteger(int a_size, int *a)
{
	int num = 0, result = 0;

	num = result ^ a[0];

	if (a_size == 1)
		return num;

	for (int i = 1; i < a_size; i++)
		num = num ^ a[i];

	return num;
}

int main(void)
{
	int n;

	scanf("%i", &n);

	int *a = malloc(sizeof(int) * n);

	for (int a_i = 0; a_i < n; a_i++)
		scanf("%i", &a[a_i]);

	int result = lonelyinteger(n, a);

	printf("%d\n", result);

	return 0;
}
