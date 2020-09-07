/*
 * matrix2.c
 * Problem Set 2, Problem 3
 * MIT OCW 6s096
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


Matrix* allocateMatrix( size_t R, size_t C ) {
	Matrix *matrix = malloc( sizeof(Matrix) );
	matrix->R = R;
	matrix->C = C;
	matrix->index = calloc( R*C, sizeof(int) );
	return matrix;
}


void destroyMatrix( Matrix *matrix ) {
	free( matrix->index );
	free( matrix );
}


Matrix* readMatrix( FILE *input ) {
	size_t R, C;
	fscanf( input, "%zu %zu", &R, &C );
	Matrix *matrix = allocateMatrix( R, C );
	for ( size_t r = 0; r < R; ++r ) {
		for ( size_t c = 0; c < C; ++c ) {
			fscanf( input, "%d", &matrix->index[c + r*C] );
		}
	}
	return matrix;
}


Matrix* matMul( Matrix *A, Matrix *B ) {
	if ( A->C != B->R ) {
		printf( "Error: cannot multiply (%zux%zu)x(%zux%zu)", A->R, A->C, B->R, B->C );
		exit( EXIT_FAILURE );
	}

	size_t nRows = A->R, nCols = B->C, nInner = A->C;
	Matrix *prod = allocateMatrix( nRows, nCols );

	for ( size_t r = 0; r < nRows; ++r ) {
		for ( size_t c = 0; c < nCols; ++c ) {
			prod->index[c + r*nCols] = 0;
			for ( size_t i = 0; i < nInner; ++i ) {
				prod->index[c + r*nCols] += ( A->index[i + r*A->C] * B->index[c + i*B->C] );
			}
		}
	}
	return prod;
}


void writeMatrix( FILE *output, Matrix *A ) {
	fprintf( output, "%zu %zu\n", A->R, A->C );
	for ( size_t r = 0; r < A->R; ++r ) {
		for ( size_t c = 0; c < A->C; ++c ) {
			fprintf( output, "%d ", A->index[c + r*A->C] );
		}
		fprintf( output, "\n" );
	}
}


void printMatrix( Matrix *A ) {
	printf( "%ld %ld\n", A->R, A->C );
	for ( size_t r = 0; r < A->R; ++r ) {
		for ( size_t C = 0; c < A->C; ++c ) {
			printf( "%d ", A->index[c + r*A->C] );
		}
		printf( "\n" );
	}
}


#ifndef TEST
int main() {
	FILE *input = fopen( FILE_IN, "r" );
	Matrix *A = readMatrix( input );
	Matrix *B = readMatrix( input );
	fclose( input );
	
	Matrix *C = matMul( A, B );

	FILE *output = fopen( FILE_OUT, "w" );
	writeMatrix( output, C );
	fclose( output );

	destroyMatrix( A );
	destroyMatrix( B );
	destroyMatrix( C );
	return 0;
}
#endif // TEST
