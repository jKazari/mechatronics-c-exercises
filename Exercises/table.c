#include <stdio.h>

#define LIMIT 10

int main() {
	for (int i = 1; i <= LIMIT; ++i) {
		for (int j = 1; j <= LIMIT; ++j) {
			printf("%4d", i * j);
		}
		printf("\n");
	}
	return 0;
}
