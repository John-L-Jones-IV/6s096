/*
 * matrix2.h
 * Problem Set 2, Problem 3
 * MIT OCW 6s096
 * John L. Jones IV
 */


typedef struct Matrix_s {
	size_t R, C;
	int *index;
} Matrix;


Matrix* allocateMatrix( size_t R, size_t C );
/* create a Matrix struct in the heap
 * with with R row C cols and an index int array with RxC length
 */


void destoryMatrix( Matrix *matrix );
/* free the Matrix struct from the heap
 */


Matrix* readMatrix( FILE *input );
/* read the file formated as
 * R C
 * 11 12 ..
 * 21 33 ..
 * .. ..
 *
 * return Matrix struct pointer to new Matrix struct alloacted in the heap
 *
 * NOTE: use destryMatrix when done using to avoid memory leak
 */


Matrix* matMul( Matrix *A, Matrix *B );
/* perform matrix multipication AxB
 *
 * return pointer to new product matrix allocated in the heap 
 */


void writeMatrix( FILE *output, Matrix *A );
/* write the contents of Matrix A to output file in format
 * R C
 * 11 12 ..
 * 21 33 ..
 * .. ..
 */

void printMatrix( Matrix *A );
/* print Matrix A to the console
 */
