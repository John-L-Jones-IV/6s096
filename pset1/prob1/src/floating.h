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

void print_float( FILE *output, float f );
