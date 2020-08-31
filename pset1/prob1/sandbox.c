#include <stdio.h>
#include <stdint.h>

#define SIGN_MASK 0x80000000


int main() {
	// uint32_t word = 0xFFFFFFFF;
	uint32_t word = 0x7FFFFFFF;
	printf("word >> 31: %X\n", word>>31);

	return 0;
}
