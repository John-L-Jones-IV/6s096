/*
PROG: floating
LANG: C
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define SIGN_MASK	0x80000000U
#define EXPONENT_MASK 	0x7F800000U
#define EXPONENT_BIAS	127
#define MANTISSA_MASK	0x007FFFFFU
#define MANTISSA_WIDTH	23

// union allows diffent data types to be stored at the same place in memory.
union float_bits {
	float f;	// 32-bit by default
	uint32_t bits;
};


void print_float(FILE *output, float f) {
	union float_bits t;
	t.f = f;

	uint32_t sign_bit = t.bits >> 31;
	int32_t exponent = (t.bits & EXPONENT_MASK) >> MANTISSA_WIDTH;
	uint32_t mantissa = t.bits & MANTISSA_MASK;

	if (sign_bit) {
		fprintf(output, "-");
	}

	if (exponent) {
		fprintf(output, "1.");
		exponent = exponent - EXPONENT_BIAS;
	}
	else {
		fprintf(output, "0.");
		exponent = exponent - 126;
	}

	for (int32_t i = MANTISSA_WIDTH - 1; i >= 0; --i) {
		printf("%ld\n", i);
		fprintf(output, "%u", (mantissa >> i) & 1);
	}

	fprintf(output, " * 2^%d\n", exponent);
}


int main() {
	FILE *input = fopen("floating.1.in",  "r");
	FILE *output = fopen("floating.1.out", "w");
	size_t N;
	float f;
	fscanf(input, "%zu", &N);

	for(size_t i = 0; i < N; ++i) {
		fscanf(input, "%f", &f);
		print_float(output, f);
	}

	fclose(input);
	fclose(output);
	return 0;
}

