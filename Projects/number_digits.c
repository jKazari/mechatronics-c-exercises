// Napisz program, który określi, z jakiego zbioru cyfr składa się dowolna
// zadana liczba, anastępnie poda sumę tych cyfr,oraz która z nich jest
// największa i najmniejsza. 
// Np.: liczba -1246.526 składa się z cyfr 1, 2, 4, 5, 6; 
// suma tych cyfr = 18; najmniejsza cyfra to 1 a największa to 6. 
// Ponadto program posortuje zbiór cyfr i wyznaczy medianę

#include <stdio.h>

#define MAX_LENGTH 100

void insertElementToSet(int set[], int* index, int element) {
	set[*index] = element;
	++(*index);
}

int isElementInSet(int set[], int setElements, int element) {
	for (int i = 0; i < setElements; i++) {
		if (set[i] == element)
			return 1;
	}
	return 0;
}

int printSet(int set[], int setElements) {
	for (int i = 0; i < setElements; i++) {
		if (i != setElements-1)
			printf("%d, ", set[i]);
		else
			printf("%d", set[i]);
	}
}

void sortSet(int set[], int setElements) {
	for (int i = 0; i < setElements - 1; i++) {
        for (int j = 0; j < setElements - i - 1; j++) {
            if (set[j] > set[j+1]) {
                int temp = set[j];
                set[j] = set[j+1];
                set[j+1] = temp;
            }
        }
    }
}

int digitsSum(int set[], int setElements) {
	int sum = 0;
	for (int i = 0; i < setElements; i++) {
		sum += set[i];
	}
	return sum;
}

float digitsMedian(int set[], int setElements) {
	if (setElements % 2 != 0)
		return set[setElements/2];
	else
		return (set[setElements/2] + set[setElements/2 - 1]) / 2.0;
}

int main() {
	int number[MAX_LENGTH]	 = {0};
	int digits				 = 0;
	int set[MAX_LENGTH]		 = {0};
	int setElements			 = 0;

	// Reads entered number and saves it to number[] setay
	char c;
	int i = 0; 
	while ((c = getchar()) != '\n') {
		if (c >= '0' && c <= '9') {
			number[i] = (int)(c - '0');
			++i;
			++digits;
		}
	}

	// Appends digits from number[] setay to set
	for (int i = 0; i < digits; i++) {
		if (!isElementInSet(set, setElements, number[i])) {
			insertElementToSet(set, &setElements, number[i]);
		}
	}

	// Sorts the set
	sortSet(set, setElements);

	// Output
	printf("The number consists of digits:\t[");
	printSet(set, setElements);
	printf("]\n");
	printf("Digit sum:\t\t\t%d\n", digitsSum(set, setElements));
	printf("Digit median:\t\t\t%.1f\n", digitsMedian(set, setElements));
	printf("Smallest digit:\t\t\t%d\n", set[0]);
	printf("Biggest digit:\t\t\t%d\n", set[setElements-1]);
	return 0;
}