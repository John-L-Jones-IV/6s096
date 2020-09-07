/*
 * loop.h
 * Problem Set 1, Problem 4
 * MIT OCW 6s096
 * John L. Jones IV
 */


#define BLOCK_SIZE 16777216 // 16MB


size_t getStr( char **str, FILE *input );
/*	str  	- pointer to char array starting with desired text to proccess.
 *			Must contain NULL characters after desired text
 *			(is guarenteed if freeing with calloc).
 *	input	- file buffer pointer to input file
 *
 *	return the number of leading non NULL characters in str
 */


void flipStr( char* str, size_t len );
/* 	str	- pointer to char array startin
 *  	len	- length of char array str
 *
 *  	flip the string in place.
 *  	for example
 *
 *  	str = "abd";
 *  	flipStr( str );
 *	// str is not "dba"
 */


void encrypt( char* string, size_t length );
/*	encyrpt char array string with length length
 *	per alogrithm in problem set.
 */
