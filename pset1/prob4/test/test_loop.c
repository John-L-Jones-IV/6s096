/*
 * test_loop.c
 * Problem Set 1, Problem 4
 * MIT OCW 6s096
 * John L. Jones IV
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "unity.h"
#include "loop.h"

#define INPUT_FILE_FORMAT "test/data/loop.%zu.in"
#define ANSWER_FILE_FORMAT "test/data/loop.%zu.out"
#define OUTPUT_FILE_FORMAT "test/output/loop.%zu.out"


void setUp( void ) {}
void tearDown( void ) {}


void test_flipStr_singleLetter( void ) {
	char str1[1] = "a";
	flipStr( str1, 1 );
	TEST_ASSERT_EQUAL_STRING( "a", str1 );

}


void test_flipStr_exampleString( void ) {
	char str2[8] = "12345678";
	flipStr( str2, 8 );
	TEST_ASSERT_EQUAL_STRING( "87654321", str2 );
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
	char *str = calloc( BLOCK_SIZE, sizeof(char) );
	input_file_ptr = fopen( input_file_name, "r" );
	size_t l = getStr( &str, input_file_ptr );
	fclose( input_file_ptr );

	/* run FUT */
	encrypt( str, l );

	/* write result to file */
	output_file_ptr = fopen( output_file_name, "w" );
	fprintf( output_file_ptr, "%ld\n%s", l, str);
	fclose( output_file_ptr );
	free( str );

	/* compare contents of output file and answer file */
	answer_file_ptr = fopen( answer_file_name, "r" );
	output_file_ptr = fopen( output_file_name, "r" );

 	char c1, c2;
	while( (c1 = fgetc( answer_file_ptr )) != EOF ) {
		c2 = fgetc( output_file_ptr );
		if ( c1 != c2 ) {
			sprintf( message, "FAIL: %c != %c in file %ld", c1, c2, file_number );
			TEST_FAIL_MESSAGE( message );
			TEST_FAIL();
			return;
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


#ifdef TEST
int main( void ) {
 	UNITY_BEGIN();
	RUN_TEST( test_flipStr_singleLetter );
	RUN_TEST( test_flipStr_exampleString );
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
 	return UNITY_END();
}
#endif // TEST
