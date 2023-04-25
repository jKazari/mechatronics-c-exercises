#include <stdio.h>
#include <math.h>

int main() {
	int n;
	int counter = 0;
	int sum = 0;

	printf("Enter a number:\t\t");
	scanf("%d", &n);

	printf("Natural dividers:\t");
	for (int i = 1; i <= n; ++i) {
		if (n%i == 0) {
			printf("%d, ", i);
			counter += 1;
			sum += i;
		}
	}
	printf("\n");
	printf("Found dividers:\t\t%d\n", counter);
	printf("Sum of dividers:\t%d\n", sum);

	if (counter == 2) {
		printf("Number is prime\n");
	}

	return 0;
}