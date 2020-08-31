#include <stdlib.h>
#include <stdio.h>

#define BLOCK_SIZE 16777216 // 16MB
#define FILE_INPUT "loop.1.in"
#define FILE_OUTPUT "loop.1.out"


/*	str  	- pointer to char array starting with desired text to proccess. 
 *			Must contain NULL characters after desired text
 *			(is guarenteed if freeing with calloc).
 *	input	- file buffer pointer to input file
 *
 *	return the number of leading non NULL characters in str */
size_t getstr(char** str, FILE* input) {
	return fread(*str, 1, BLOCK_SIZE, input) - 1;
}

void flipstr(char* str, size_t len) {
	char tmp;
	for (size_t i = 0; i < len/2; ++i) {
		tmp = str[len - 1 - i];
		str[len - 1 - i] = str[0];
		str[0] = tmp;
	}
}


void encrypt(char* string, size_t length) {
	// if length is 1 or 2, stop recursion
	if (length == 1 || length == 2) {
		return;
	}

	// otherwise
	size_t k = length/2;
	flipstr(string, k);
	flipstr((string + k), length - k);
	encrypt(string, k);
	encrypt((string + k), length - k);
}


int main() {
	char *str = calloc(BLOCK_SIZE, sizeof(char));

 	FILE *input = fopen(FILE_INPUT, "r");
	size_t l = getstr(&str, input);
 	fclose(input);

	encrypt(str, l);

	FILE *output = fopen(FILE_OUTPUT, "w");
	fprintf(output, "%ld\n%s", l, str);
	fclose(output);

	free(str);

	return 0;
}
