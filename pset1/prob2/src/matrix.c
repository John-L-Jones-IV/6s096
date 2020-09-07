#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "matrix.h"

Matrix matMul( Matrix *A, Matrix *B ) {
	Matrix C;
	if ( A->C != B->R ) {
		C.R = 0;
		C.C = 0;
		return C;
	}
	else {
		C.R = A->R;
		C.C = B->C;
	}

	int32_t sum;
	for ( size_t i = 0; i < A->R; ++i ) {
		for ( size_t j = 0; j < B->C; ++j ) {
			sum = 0;
			for ( size_t k = 0; k < A->C; ++k ) {
				sum += (A->index[i][k] * B->index[k][j]);
			}
			C.index[i][j] = sum;
		}
	}
	return C;
}


void build_mat( FILE *input, Matrix *A ) {
	fscanf( input, "%zu", &A->R );
	fscanf( input, "%zu", &A->C );
	for ( size_t i = 0; i < A->R; ++i ) {
		for ( size_t j = 0; j < A->C; ++j ) {
			fscanf( input, "%d", &A->index[i][j] );
		}
	}
}


void write_mat( FILE *output, Matrix *A ) {
	fprintf( output, "%ld %ld\r\n", A->R, A->C );
	for ( size_t i = 0; i < A->R; ++i ) {
		for ( size_t j = 0; j < A->C; ++j ) {
			if ( j == A->C -1 ) {
				fprintf( output, "%d", A->index[i][j] );
			}
			else {
				fprintf( output, "%d ", A->index[i][j] );
			}
		}
		if ( i < A->R-1 ) {
			fprintf( output, "\r\n" );
		}
	}
}


#ifndef TEST
int main( int argc, char *argv ) {
	FILE *input = fopen( "matrix.9.in", "r" );
	FILE *output = fopen( "matrix.9.out", "w" );

	Matrix A;
	build_mat( input, &A );
	Matrix B;
	build_mat( input, &B );

	Matrix C = matMul( &A, &B );
	write_mat( output, &C );

	fclose( input );
	fclose( output );
	return 0;
}
#endif // TEST

