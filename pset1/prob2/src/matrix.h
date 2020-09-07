#define MAXN 300

typedef struct Matrix_s {
	size_t R, C;
	int index[MAXN][MAXN];
} Matrix;

Matrix matMul( Matrix *A, Matrix *B );
/* Matrix Multiplication
 *
 * return the matrix multiplication product of Matrix A and Matrix B
 */

void build_mat( FILE *input, Matrix *A );
/* given file pointer input populate matrix A
 *
 * file should follow format
 * R C
 * 11 12
 * 21 22
 */

void write_mat( FILE *output, Matrix *A );
/* write Matrix A to file output */

