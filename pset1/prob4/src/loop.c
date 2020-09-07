/*
 * loop.c
 * Problem Set 1, Problem 4
 * MIT OCW 6s096
 * John L. Jones IV
 */


#include <stdlib.h>
#include <stdio.h>
#include "loop.h"

#define FILE_INPUT "loop.1.in"
#define FILE_OUTPUT "loop.1.out"


size_t getStr( char **str, FILE *input ) {
	return fread(*str, 1, BLOCK_SIZE, input) - 1;
}


void flipStr( char* str, size_t len ) {
	char tmp;
	for ( size_t i = 0; i < len/2; ++i ) {
		tmp = str[len - 1 - i];
		str[len - 1 - i] = str[i];
		str[i] = tmp;
	}
}


void encrypt( char* string, size_t length ) {
	if ( length == 1 || length == 2 ) {
	// if length is 1 or 2, stop recursion
		return;
	}

	// otherwise
	size_t k = length/2;
	flipStr( string, k );
	flipStr( (string + k), length - k );
	encrypt( string, k );
	encrypt( (string + k), length - k );
}


#ifndef TEST
int main() {
	char *str = calloc( BLOCK_SIZE, sizeof(char) );

 	FILE *input = fopen( FILE_INPUT, "r" );
	size_t l = getStr( &str, input );
 	fclose( input );

	encrypt( str, l );

	FILE *output = fopen( FILE_OUTPUT, "w" );
	fprintf( output, "%ld\n%s", l, str );
	fclose( output );

	free( str );

	return 0;
 }
#endif // TEST
