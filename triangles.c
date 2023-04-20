#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float* sortSideLengths(float a, float b, float c) {
	float shorter1;
	float shorter2;
	float longest;
	float *sides = malloc(3 * sizeof(float));

	if (a <= b && a <= c) {
		shorter1 = a;
		shorter2 = b < c ? b : c;
		longest = b < c ? c : b;
	}

	else if (b <= a && b <= c) {
		shorter1 = b;
		shorter2 = a < c ? a : c;
		longest = a < c ? c : a;
	}

	else {
		shorter1 = c;
		shorter2 = a < b ? a : b;
		longest = a < b ? b : a;
	}

	sides[0] = shorter1;
	sides[1] = shorter2;
	sides[2] = longest;

	return sides;
}

int isConstructible(float a, float b, float c) {
	return a + b > c && a + c > b && b + c > a ? 1 : 0;
}

int isEquilateral(float a, float b, float c) {
	return a == b && a == c ? 1 : 0;
}

int isIsosceles(float a, float b, float c) {
	return a == b || a == c || b == c ? 1 : 0;
}

int isAcute(float* sides) {
	return pow(sides[0], 2) + pow(sides[1], 2) > pow(sides[2], 2) ?
		1 : 0;
}

int isObtuse(float *sides){
	return pow(sides[0], 2) + pow(sides[1], 2) < pow(sides[2], 2) ?
		1 : 0;
}

int isRight(float *sides){
	return pow(sides[0], 2) + pow(sides[1], 2) == pow(sides[2], 2) ?
		1 : 0;
}

int main() {
	float a;
	float b;
	float c;

	scanf("%f %f %f", &a, &b, &c);
	
	float* sides = sortSideLengths(a,b,c);

	if (isConstructible(a,b,c)) {
		printf("Triangle is constructible\n");

		if (isEquilateral(a,b,c))
			printf("Triangle is equilateral\n");

		else if (isIsosceles(a,b,c))
			printf("Triangle is isosceles\n");

		else
			printf("Triangle is normal\n");

		if (isRight(sides))
			printf("Triangle is right-angled\n");

		else if (isAcute(sides))
			printf("Triangle is acute\n");

		else if (isObtuse(sides))
			printf("Triangle is obtuse\n");
	}

	else {
		printf("Triangle is not constructible\n");
	}

	free(sides);
	return 0;
}