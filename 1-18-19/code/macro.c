#define DOUBLE(x) ((x)*(x)) 
#define NUMBER 5

// Compile with gcc -E to see whats happening!

int main() {

	printf("%d\n", DOUBLE(4));
	printf("%d\n", DOUBLE('c'));
	printf("%d\n", DOUBLE(NUMBER));	

}
