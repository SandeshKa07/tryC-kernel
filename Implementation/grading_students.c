#include <stdio.h>
#include <string.h>

int main(void)
{
	int num_of_subjects = 0, iter = 0, mod_val = 0;

	printf("\nEnter Number of Subjects: ");
	scanf("%d", &num_of_subjects);

	int scores[num_of_subjects];

	for (iter = 0; iter < num_of_subjects; iter++)
		scanf("%d", &scores[iter]);

	for (iter = 0; iter < num_of_subjects; iter++) {
		if (scores[iter] < 38)
			continue;

		mod_val = (scores[iter] % 5);
		if (mod_val > 2 && mod_val <= 4)
			scores[iter] += 5 - mod_val;
		else
			continue;
	}

	for (iter = 0; iter < num_of_subjects; iter++)
		printf("\n%d", scores[iter]);

	return 0;
}
