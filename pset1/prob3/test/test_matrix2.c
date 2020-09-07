/*
 * test_matrix2.c
 * Problem Set 2, Problem 3
 * MIT OCW 6s096
 * John L. Jones IV
 */


#include <stdio.h> 
#include <string.h>
#include <sys/stat.h>

#include "unity.h"
#include "matrix2.h"

#define INPUT_FILE_FORMAT "test/data/matrix2.%zu.in"
#define ANSWER_FILE_FORMAT "test/data/matrix2.%zu.out"
#define OUTPUT_FILE_FORMAT "test/output/matrix2.%zu.out"

void setUp( void ) {}
void tearDown( void ) {}


int getFileSize( char *filename ) {
	struct stat st;

	if ( stat( filename, &st ) == 0 ) {
		return ( st.st_size );
	}
	else {
		return -1;
	}
}


void testCompareOutput( size_t file_number ) {
	FILE *input_file_ptr;
	FILE *output_file_ptr;
	FILE *answer_file_ptr;

	char message[180];
	char input_file_name[80];
	char output_file_name[80];
	char answer_file_name[80];
	sprintf( input_file_name, INPUT_FILE_FORMAT, file_number );
	sprintf( output_file_name, OUTPUT_FILE_FORMAT, file_number );
	sprintf( answer_file_name, ANSWER_FILE_FORMAT, file_number );

	/* read input files */ 
	input_file_ptr = fopen( input_file_name, "r" );
	Matrix *A = readMatrix( input_file_ptr );
	Matrix *B = readMatrix( input_file_ptr );
	fclose( input_file_ptr );

	Matrix *C = matMul( A, B );

	/* write product to file */
	output_file_ptr = fopen( output_file_name, "w" );
	writeMatrix( output_file_ptr, C );
	fclose( output_file_ptr );

	/* compare contents of output file and answer file */
	answer_file_ptr = fopen( answer_file_name, "r" );
	output_file_ptr = fopen( output_file_name, "r" );
	size_t R_ans, R_out, C_ans, C_out;
	fscanf( answer_file_ptr, "%zu", &R_ans );
	fscanf( answer_file_ptr, "%zu", &C_ans );
	fscanf( output_file_ptr, "%zu", &R_out );
	fscanf( output_file_ptr, "%zu", &C_out );
	if ( R_ans != R_out ) {
		sprintf( message, "FAIL: R=%zu in answer and R=%zu in ouput\n", R_ans, R_out );
		TEST_FAIL_MESSAGE( message );
		TEST_FAIL();
		return;
	}
	if ( C_ans != C_out ) {
		sprintf( message, "FAIL: C=%zu in answer and C=%zu in ouput\n", C_ans, C_out );
		TEST_FAIL_MESSAGE( message );
		TEST_FAIL();
		return;
	}

 	int c1, c2;
	for ( size_t i = 1; i <= R_out; ++i ) {
		for ( size_t j = 1; j <= C_out; ++j ) {
			fscanf( answer_file_ptr, "%d", &c1 );
			fscanf( output_file_ptr, "%d", &c2 );
			sprintf( message, "FAIL: answer %c does not match %c at row:%zu col:%zu", c1, c2, i, j );
			TEST_ASSERT_MESSAGE( c1 == c2, message );
		}
	}
	fclose( answer_file_ptr );
	fclose( output_file_ptr );
	TEST_PASS();
}


void testCompareOutput1() { testCompareOutput( 1 ); }
void testCompareOutput2() { testCompareOutput( 2 ); }
void testCompareOutput3() { testCompareOutput( 3 ); }
void testCompareOutput4() { testCompareOutput( 4 ); }
void testCompareOutput5() { testCompareOutput( 5 ); }
void testCompareOutput6() { testCompareOutput( 6 ); }
void testCompareOutput7() { testCompareOutput( 7 ); }
void testCompareOutput8() { testCompareOutput( 8 ); }
void testCompareOutput9() { testCompareOutput( 9 ); }
void testCompareOutput10() { testCompareOutput( 10 ); }
void testCompareOutput11() { testCompareOutput( 11 ); }


#ifdef TEST
int main( void ) {
 	UNITY_BEGIN();
	RUN_TEST( testCompareOutput1 );
	RUN_TEST( testCompareOutput2 );
	RUN_TEST( testCompareOutput3 );
	RUN_TEST( testCompareOutput4 );
	RUN_TEST( testCompareOutput5 );
	RUN_TEST( testCompareOutput6 );
	RUN_TEST( testCompareOutput7 );
	RUN_TEST( testCompareOutput8 );
	RUN_TEST( testCompareOutput9 );
	RUN_TEST( testCompareOutput10 );
	RUN_TEST( testCompareOutput11 );
 	return UNITY_END();
}
#endif // TEST
