#define GET_BIT(bit, val) ((val >> bit) & 1)

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

}
