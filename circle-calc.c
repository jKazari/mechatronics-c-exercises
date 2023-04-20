#include <stdio.h>
#include <math.h>

#define PI 3.141593

#define LARGE_CIRCLES	1
#define BIG_CIRCLES		2
#define MEDIUM_CIRCLES	4
#define SMALL_CIRCLES	6

#define LARGE_RADIUS	1
#define BIG_RADIUS		0.5
#define MEDIUM_RADIUS	0.25
#define SMALL_RADIUS	0.125

float circleArea(float r) {
	return PI * r * r;
}

int main() {
	float r;
	float area;
	
	printf("Enter big circle radius: ");
	scanf("%f", &r);

	area = LARGE_CIRCLES * circleArea(r * LARGE_RADIUS) - 
		BIG_CIRCLES * circleArea(r * BIG_RADIUS) - 
		SMALL_CIRCLES * circleArea(r * SMALL_RADIUS) + 
		MEDIUM_CIRCLES * circleArea(r * MEDIUM_RADIUS);

	printf("Shaded area is %f", area);
	
	return 0;
}