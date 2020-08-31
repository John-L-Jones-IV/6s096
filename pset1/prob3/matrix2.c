/*
 * John L. Jones IV
 */
#include <stdio.h>
#include <stdlib.h>

#define FILE_IN "matrix2.4.in"
#define FILE_OUT "matrix2.4.out"


typedef struct Matrix_s {
	size_t R, C;
	int *index;
} Matrix;


Matrix* allocate_matrix(size_t R, size_t C) {
	Matrix *matrix = malloc(sizeof(Matrix));
	matrix->R = R;
	matrix->C = C;
	matrix->index = calloc(R*C, sizeof(int));
	return matrix;
}


void destroy_matrix(Matrix *matrix) {
	free(matrix->index);
	free(matrix);
}


Matrix* read_matrix(FILE *input) {
	size_t R, C;
	fscanf(input, "%zu %zu", &R, &C);
	Matrix *matrix = allocate_matrix(R, C);
	for (size_t r = 0; r < R; ++r) {
		for (size_t c = 0; c < C; ++c) {
			fscanf(input, "%d", &matrix->index[c + r*C]);
		}
	}
	return matrix;
}


Matrix* mat_mul(Matrix *A, Matrix *B) {
	if (A->C != B->R) {
		printf("Error: tried to multiply (%zux%zu)x(%zux%zu)", A->R, A->C, B->R, B->C);
		exit(EXIT_FAILURE);
	}

	size_t nRows = A->R, nCols = B->C, nInner = A->C;
	Matrix *prod = allocate_matrix(nRows, nCols);

	for (size_t r = 0; r < nRows; ++r) {
		for (size_t c = 0; c < nCols; ++c) {
			prod->index[c + r*nCols] = 0;
			for (size_t i = 0; i < nInner; ++i) {
				prod->index[c + r*nCols] += (A->index[i + r*A->C] * B->index[c + i*B->R]);
			}
		}
	}
	return prod;
}


void write_matrix(FILE *output, Matrix *A) {
	fprintf(output, "%zu %zu\n", A->R, A->C);
	for (size_t r = 0; r < A->R; ++r) {
		for (size_t c = 0; c < A->C; ++c) {
			fprintf(output, "%d ", A->index[c + r*A->C]);
		}
		fprintf(output, "\n");
	}
}


void print_matrix(Matrix *A) {
	printf("%ld %ld\n", A->R, A->C);
	for (size_t r = 0; r < A->R; ++r) {
		for (size_t c = 0; c < A->C; ++c) {
			printf("%d ", A->index[c + r*A->C]);
		}
		printf("\n");
	}
}


int main() {
	FILE *input = fopen(FILE_IN, "r");
	Matrix *A = read_matrix(input);
	Matrix *B = read_matrix(input);
	fclose(input);
	
	Matrix *C = mat_mul(A, B);

	FILE *output = fopen(FILE_OUT, "w");
	write_matrix(output, C);
	fclose(output);

	destroy_matrix(A);
	destroy_matrix(B);
	destroy_matrix(C);
	return 0;
}

