#include <stdio.h>

int main() {
	float x;
	float y;

	printf("Enter x coordinate: ");
	scanf("%f", &x);
	printf("Enter y coordinate: ");
	scanf("%f", &y);

	if (x > 0 && y > 0) {
		printf("Point is in I quarter");
	}

	else if (x < 0 && y > 0) {
		printf("Point is in II quarter");
	}

	else if (x < 0 && y < 0) {
		printf("Point is in III quarter");
	}

	else if (x > 0 && y < 0) {
		printf("Point is in IV quarter");
	}

	else if (x == 0 && y != 0) {
		printf("Point is on the Y axis");
	}

	else if (y == 0 && x != 0) {
		printf("Point is on the X axis");
	}

	else {
		printf("Point is in the center");
	}

	return 0;
}