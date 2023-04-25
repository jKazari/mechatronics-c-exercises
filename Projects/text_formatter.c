// Napisz program, który w zadanym ciągu znaków (max 60 znaków):
// 	- Usunie zbędne spacje na końcu i początku tekstu
// 	- Usunie wielokrotne spacje i zamieni je na pojedyncze
// 	- Usunie spacje przed znakami interpunkcyjnymi  i  nawiasami
// 	  zamykającymioraz po nawiasie otwierającym
// 	- Doda spacje po znakach interpunkcyjnych i przed nawiasami
// 	  otwierającymi, jeśli ich tam nie ma
// 	- Zamieni litery na początku każdego zdania na wielkie
// 	- Jeśli znajdzie w tekście ciąg „@M” wpisze w to miejsce słowo
//    „mechatronika”

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 				60
#define CUSTOM_WORD 		"mechatronika"
#define CUSTOM_WORD_MACRO 	'M'

int isPunctuationOrClosingBrace(char c) {
	return (c == '.' || c == ';' || c == ')' || 
			c == ',' || c == '!' || c == ']' || 
			c == ':' || c == '?' || c == '}') ? 1 : 0;
}

int isOpeningBrace(char c) {
	return (c == '(' || c == '[' || c == '{') ? 1 : 0;
}

char* trimText(char* text) {
	char* i = text;
    char* j;

    while (*i == ' ') {
        i++;
    }

    j = i + strlen(i) - 1;
    while (j > i && *j == ' ') {
        j--;
    }
    *(j+1) = '\0';

	text = i;
    return text;
}

char* removeMultiSpace(char* text) {
	int i = 0;
	int j = 0;

	while (i < strlen(text)) {
		if (text[i] != ' ') {
			text[j++] = text[i++];
		}
		else {
			while (text[i] == ' ') {
				i++;
			}
			text[j++] = ' ';
		}
	}
	text[j] = '\0';

	return text;
}

char* removeSpacesAroundPunctuation(char* text) {
	int i;
	int j;

	// Removes spaces before punctuation marks or closing braces
	i = 0; j = 0;
	while (i < strlen(text)) {
		if (text[i] == ' ' && isPunctuationOrClosingBrace(text[i+1])) {
			i++;
		}
		else {
			text[j++] = text[i++];
		}
	}
	text[j] = '\0';

	// Removes spaces after opening braces
	i = 0; j = 0;
	while (i < strlen(text)) {
		if (isOpeningBrace(text[i]) && text[i+1] == ' ') {
			text[j++] = text[i++];
			i++;
		}
		else {
			text[j++] = text[i++];
		}
	}
	text[j] = '\0';

	return text;
}

char* addSpacesAroundPunctuation(char* text) {
	char* result = malloc(strlen(text) * 2);
	int i;
	int j;

	// Adds spaces after punctuation marks and closing braces
	i = 0; j = 0;
	while (i < strlen(text)) {
		if (isPunctuationOrClosingBrace(text[i])) {
			result[j++] = text[i++];
			if (i < strlen(text) && text[i] != ' ') {
				result[j++] = ' ';
			}
		}
		else {
			result[j++] = text[i++];
		}
	}
	result[j] = '\0';

	// Redefines variables
	text = result;
	result = malloc(strlen(text) * 2);

	// Adds spaces before opening braces
	i = 0; j = 0;
	while (i < strlen(text)) {
		if (text[i] != ' ' && isOpeningBrace(text[i+1])) {
			result[j++] = text[i++];
			result[j++] = ' ';
		}
		else {
			result[j++] = text[i++];
		}
	}
	result[j] = '\0';

	return result;
}

char* correctCapitalization(char* text) {
	int i = 0;
	int j = 0;

	while (i < strlen(text)) {
		if (text[i] == '.' && islower(text[i+2])) {
			text[j++] = text[i++];
			text[j++] = text[i++];
			text[j++] = toupper(text[i++]);
		}
		else {
			text[j++] = text[i++];
		}
	}
	text[j] = '\0';
	
	return text;
}

char* addCustomWord(char* text) {
	char* result = malloc(strlen(text) * 2);
	int i = 0;
	int j = 0;

	while (i < strlen(text)) {
		if (text[i] == '@' && text[i+1] == CUSTOM_WORD_MACRO) {
			for (int k = 0; k < strlen(CUSTOM_WORD); k++) {
				result[j++] = CUSTOM_WORD[k];
			}
			i += 2;
		}
		else {
			result[j++] = text[i++];
		}
	}
	result[j] = '\0';
	
	return result;
}

char* correctText(char* text) {
	char* trimmed = trimText(text);
	char* removedMultiSpace = removeMultiSpace(trimmed);
	char* removedSpaces = removeSpacesAroundPunctuation(removedMultiSpace);
	char* addedSpaces = addSpacesAroundPunctuation(removedSpaces);
	char* correctedCapitalization = correctCapitalization(addedSpaces);
	char* addedCustomWord = addCustomWord(correctedCapitalization);
	return addedCustomWord;
}

int main() {
	char text[MAX] = {0};

	// Get input from user
	char c;
	int i = 0;
	while((c = getchar()) != '\n') {
		text[i++] = c;
	}
	text[i] = '\0';
	
	printf("%s", correctText(text));
	return 0;
}

// "   To @M jest,testowy tekst .  lol  ( zobaczmy )  czy(  go )  poprawi   "