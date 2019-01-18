#define GET_BIT(bit, val) ((val >> bit) & 1)
#define FLIP_BIT(bit, val) ((1 << bit) ^ val)

void print_bytes_bits(unsigned char byte) {
	int i = 7;
	for (;i >= 0; i--) {
		printf("%d ", GET_BIT(i, byte));
	}
	printf("\n");
}

int main() {
	unsigned char byte1 = 5,   // 00000101 
			byte2 = 4; // 00000100

	// What should be output?
	print_bytes_bits(byte1 << 2);
	print_bytes_bits(byte1 >> 2);
	print_bytes_bits(byte1 & byte2);
	print_bytes_bits(byte1 | byte2);
	print_bytes_bits(byte1 ^ byte2);

	byte1 = 15; // 00001111
	int i = 0;
	for (; i < 8; i++) {
		byte1 = FLIP_BIT(i, byte1);
	} 
	print_bytes_bits(byte1);
}
