#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INPUT_FILE "test.txt"
#define OUTPUT_FILE  "test_output.txt"
#define BLOCK_SIZE 16777216


void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until it arrives.
}

int main() {
	printf("\a");
	for (size_t i = 0; i < 5; ++i) {
		printf("\a");
		waitFor(1);
	}
//	size_t chars;
//	size_t length = 0;
//	size_t chars_to_read = BLOCK_SIZE;
//	char* str = calloc(BLOCK_SIZE, sizeof(char));
//
//	FILE *input = fopen(INPUT_FILE, "r");
//	while((chars = fread(*&str + length, 1, chars_to_read, input))) {
//		printf("running while loop...");
//	}
//	fclose(input);
//
//	printf("fread output = %ld\n", chars);
//	printf("%s\n", str);
//
//	FILE *output = fopen(OUTPUT_FILE, "w");
//	fprintf(output, "%s", str);
//	fclose(output);

	return 0;
}
