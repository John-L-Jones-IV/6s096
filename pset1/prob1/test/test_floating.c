#include <stdio.h> 
#include <string.h>
#include <sys/stat.h>

#include "unity.h"
#include "floating.h"

#define INPUT_FILE_FORMAT "test/data/floating.%ld.in"
#define ANSWER_FILE_FORMAT "test/data/floating.%ld.out"
#define OUTPUT_FILE_FORMAT "test/output/floating.%ld.out"


void setUp(void) {}
void tearDown(void) {}

int getFileSize( char *filename ) {
	struct stat st;

	if ( stat( filename, &st) == 0 ) {
		return ( st.st_size );
	}
	else {
		return -1;
	}
}



void testCompareOutput( size_t file_number) {
	char input_file_name[80];
	char output_file_name[80];
	char answer_file_name[80];
	char message[180];
	char c1, c2;
	int N;
	int N1, N2;
	float f;
	FILE *input_file_ptr;
	FILE *output_file_ptr;
	FILE *answer_file_ptr;

	sprintf( input_file_name, INPUT_FILE_FORMAT, file_number );
	sprintf( output_file_name, OUTPUT_FILE_FORMAT, file_number );
	sprintf( answer_file_name, ANSWER_FILE_FORMAT, file_number );

	/* perform floating decode and write to file */
	input_file_ptr = fopen( input_file_name, "r" );
	output_file_ptr = fopen( output_file_name, "w" );
	fscanf( input_file_ptr, "%d", &N );
	for ( int j = 0; j < N; ++j ) {
		fscanf( input_file_ptr, "%f", &f );
		print_float( output_file_ptr, f );
	}
	fclose( input_file_ptr );
	fclose( output_file_ptr );

	/* compare outputfile size to answer file size */
	N1 = getFileSize( output_file_name );
	N2 = getFileSize( answer_file_name );
	TEST_ASSERT_MESSAGE( N1 == N2, "File size is not correct");
	if ( N1 != N2 ) {
		return;
	}

	/* compare contents of output file and answer file */
	answer_file_ptr = fopen( answer_file_name, "r" );
	output_file_ptr = fopen( output_file_name, "r" );
	fscanf( answer_file_ptr, "%d", &N1 );
	fscanf( output_file_ptr, "%d", &N2 );
	TEST_ASSERT_MESSAGE( N1 == N2, 
			"Files to not lead with same number of lines as meta data" );
	if ( N1 != N2 ) {
		return;
	}
	for ( int j = 0; j < N1; ++j ) {
		fscanf( answer_file_ptr, "%c", &c1);
		fscanf( output_file_ptr, "%c", &c2);
		sprintf( message, "expected %c received %c", c1, c2 );
		TEST_ASSERT_MESSAGE( c1 == c2, message);
	}
	fclose( answer_file_ptr );
	fclose( output_file_ptr );
}

void testCompareOutput1() {
	testCompareOutput(1);
}
void testCompareOutput2() {
	testCompareOutput(2);
}
void testCompareOutput3() {
	testCompareOutput(3);
}
void testCompareOutput4() {
	testCompareOutput(4);
}
void testCompareOutput5() {
	testCompareOutput(5);
}
void testCompareOutput6() {
	testCompareOutput(6);
}
void testCompareOutput7() {
	testCompareOutput(7);
}


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
 	return UNITY_END();
}
#endif // TEST
