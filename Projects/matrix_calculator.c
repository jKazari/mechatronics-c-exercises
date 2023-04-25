// Napisz program, który umożliwi: 
// 	- wypełnienie wartościami dwóch tablic / macierzy
// 	- dodanie macierzy
// 	- odjęcie macierzy
// 	- mnożenie macierzy
// Przed wykonaniem operacji program powinien sprawdzać, czy pozwalają
// na to wymiary poszczególnych macierzy.Program  powinien  mieć  „menu” 
// umożliwiające  wykonanie  powyższych  operacji  oraz zakończenie
// programu.
// Dodatkowo:
// 	- dodanie do macierzy zadanej liczby rzeczywistej
// 	- odjęcie do macierzy zadanej liczby rzeczywistej
// 	- mnożenie elementów macierzy przez zadaną liczbę rzeczywistą

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	float** array;
	int height;
	int width;
} Matrix;

float** createMatrix(int height, int width) {
	float** matrix = (float**)malloc(height * sizeof(float*));
	for (int i = 0; i < height; i++) {
		matrix[i] = (float*)malloc(width * sizeof(float*));
	}
	return matrix;
}

Matrix initializeMatrix(int height, int width) {
	Matrix m;
	m.array = createMatrix(height, width);
	m.height = height;
	m.width = width;	
	return m;
}

Matrix enterMatrixValues(Matrix m) {
	for (int i = 0; i < m.height; i++) {
		for (int j = 0; j < m.width; j++) {
			float value;
			scanf("%f", &value);
			m.array[i][j] = value;
		}
	}
	return m;
}

void printMatrix(Matrix m) {
	for (int i = 0; i < m.height; i++) {
		for (int j = 0; j < m.width; j++) {
			printf("%3.1f ", m.array[i][j]);
		}
		printf("\n");
	}
}

Matrix addMatrices(Matrix m1, Matrix m2) {
	if (m1.height != m2.height || m1.width != m2.width) {
		printf("Can't add matrices of different sizes");
		Matrix emptyMatrix = initializeMatrix(0, 0);
        return emptyMatrix;
	}

	Matrix m3 = initializeMatrix(m1.height, m1.width);
	for (int i = 0; i < m3.height; i++) {
		for (int j = 0; j < m3.width; j++) {
			m3.array[i][j] = m1.array[i][j] + m2.array[i][j];
		}
	}
	return m3;
}

Matrix subtractMatrices(Matrix m1, Matrix m2) {
	if (m1.height != m2.height || m1.width != m2.width) {
		printf("Can't subtract matrices of different sizes");
		Matrix emptyMatrix = initializeMatrix(0, 0);
        return emptyMatrix;
	}

	Matrix m3 = initializeMatrix(m1.height, m1.width);
	for (int i = 0; i < m3.height; i++) {
		for (int j = 0; j < m3.width; j++) {
			m3.array[i][j] = m1.array[i][j] - m2.array[i][j];
		}
	}
	return m3;
}

Matrix multiplyMatrices(Matrix m1, Matrix m2) {
	if (m1.width != m2.height) {
		printf("Can't multiply matrices; condition not met");
		Matrix emptyMatrix = initializeMatrix(0, 0);
        return emptyMatrix;
	}

	Matrix m3 = initializeMatrix(m1.height, m2.width);
	for (int i = 0; i < m3.height; i++) {
		for (int j = 0; j < m3.width; j++) {
			float sum = 0;
			for (int k = 0; k < m1.width; k++) {
				sum += m1.array[i][k] * m2.array[k][j];
			}
			m3.array[i][j] = sum;
		}
	}
	return m3;
}

Matrix multiplyByScalar(Matrix m, float s) {
	for (int i = 0; i < m.height; i++) {
		for (int j = 0; j < m.width; j++) {
			m.array[i][j] = m.array[i][j] * s;
		}
	}
	return m;
}

Matrix addScalar(Matrix m, float s) {
	for (int i = 0; i < m.height; i++) {
		for (int j = 0; j < m.width; j++) {
			m.array[i][j] = m.array[i][j] + s;
		}
	}
	return m;
}

Matrix subtractScalar(Matrix m, float s) {
	for (int i = 0; i < m.height; i++) {
		for (int j = 0; j < m.width; j++) {
			m.array[i][j] = m.array[i][j] - s;
		}
	}
	return m;
}

Matrix scanMatrix() {
	int height;
	int width;

	printf("Enter matrix dimensions (height x width): ");
	scanf("%d", &height);
	scanf("%d", &width);
	Matrix m;

	printf("Enter matrix values:\n");
	m = initializeMatrix(height, width);
	m = enterMatrixValues(m);

	return m;
}

float scanScalar() {
	float s;
	printf("Enter scalar: ");
	scanf("%f", s);
	return s;
}

int main() {
	printf("Choose operation:\n");
	printf("+: Add matrices\n");
	printf("-: Subtract matrices\n");
	printf("x: Multiply matrices\n");
	printf("a: Add scalar to matrix\n");
	printf("s: Subtract scalar from matrix\n");
	printf("m: Multiply matrix by scalar\n");

	Matrix m1;
	Matrix m2;
	Matrix m;
	float s;
	switch (getchar()) {
		case '+':
			m1 = scanMatrix();
			m2 = scanMatrix();
			printf("The result of matrix addition is:\n");
			printMatrix(addMatrices(m1, m2));
			break;
		case '-':
			m1 = scanMatrix();
			m2 = scanMatrix();
			printf("The result of matrix subtraction is:\n");
			printMatrix(subtractMatrices(m1, m2));
			break;
		case 'x':
			m1 = scanMatrix();
			m2 = scanMatrix();
			printf("The result of matrix multiplication is:\n");
			printMatrix(multiplyMatrices(m1, m2));
			break;
		case 'a':
			m = scanMatrix();
			s = scanScalar();
			printf("The result of scalar addition:\n");
			printMatrix(addScalar(m, s));
			break;
		case 's':
			m = scanMatrix();
			s = scanScalar();
			printf("The result of scalar subtraction:\n");
			printMatrix(subtractScalar(m, s));
			break;
		case 'm':
			m = scanMatrix();
			s = scanScalar();
			printf("The result of multiplication by scalar:\n");
			printMatrix(multiplyByScalar(m, s));
			break;
		default:
			printf("Invalid choice\n");
	}
	return 0;
}