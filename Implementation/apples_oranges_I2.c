#include <stdio.h>

int main(void)
{
	int start_point = 0, end_point = 0, apple_tree = 0, mango_tree = 0,
		apple_count = 0, mango_count = 0, iter = 0, res = 0, a_fall = 0,
		m_fall = 0;

	scanf("%d%d", &start_point, &end_point);
	scanf("%d%d", &apple_tree, &mango_tree);
	scanf("%d%d", &apple_count, &mango_count);

	int apple_distance[apple_count], mango_distance[mango_count];

	for (iter = 0; iter < apple_count; iter++)
		scanf("%d", &apple_distance[iter]);

	for (iter = 0; iter < mango_count; iter++)
		scanf("%d", &mango_distance[iter]);

	for (iter = 0; iter < apple_count; iter++) {
		res = apple_tree + apple_distance[iter];
		apple_distance[iter] = res;
	}

	for (iter = 0; iter < mango_count; iter++) {
		res = mango_tree + mango_distance[iter];
		mango_distance[iter] = res;
	}

	for (iter = 0; iter < apple_count; iter++) {
		if (apple_distance[iter] >= start_point &&
		    apple_distance[iter] <= end_point) {
			a_fall = a_fall + 1;
		}
	}

	for (iter = 0; iter < mango_count; iter++) {
		if (mango_distance[iter] >= start_point &&
		    mango_distance[iter] <= end_point) {
			m_fall = m_fall + 1;
		}
	}

	printf("%d\n%d\n", a_fall, m_fall);

	return 0;
}
