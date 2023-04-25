// Napisz program, który w podanym dowolnym tekście
// policzy ile w tym tekście jest:
// 	- znaków (razem: liter, spacji, liczb, innych znaków);
// 	- spacji;
// 	- liter (wszystkich);
// 	- dużych liter;
// 	- cyfr;
// 	- liczb;
// 	- słów;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define	IN	1
#define OUT	0

void countBasicChars(char* text) {
	int i = 0;
	int characters = 0;
	int spaces = 0;
	int letters = 0;
	int upperLetters = 0;
	int digits = 0;

	while (text[i] != '\0') {
		char c = text[i];
		if (c == ' ') {
			spaces++;
		}
		if (isalpha(c)) {
			letters++;
		}
		if (isupper(c)) {
			upperLetters++;
		}
		if (isdigit(c)) {
			digits++;
		}
		characters++;
		i++;
	}

	printf("Amount of characters:\t\t%d\n", characters);
	printf("Amount of spaces:\t\t%d\n", spaces);
	printf("Amount of letters:\t\t%d\n", letters);
	printf("Amount of uppercase letters:\t%d\n", upperLetters);
	printf("Amount of digits:\t\t%d\n", digits);
}

void countWordsAndNumbers(char* text) {
	int i = 0;
	int words = 0;
	int numbers = 0;
	int state = OUT;

	while (text[i] != '\0') {
		char c = text[i];
		if (isblank(c)) {
			state = OUT;
		}
		else if (state == OUT && !isdigit(c)) {
			state = IN;
			words++;
		}
		else if (state == OUT && isdigit(c)) {
			state = IN;
			numbers++;
		}
		i++;
	}
	printf("Amount of words:\t\t%d\n", words);
	printf("Amount of numbers:\t\t%d\n", numbers);
}

int main() {
	char text[] = "To jest testowy program, 7 zobaczmy 7890 czy zadziala...";
	countBasicChars(text);
	countWordsAndNumbers(text);
	return 0;
}