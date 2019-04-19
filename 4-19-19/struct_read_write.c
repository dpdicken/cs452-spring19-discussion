/*
 * The purpose of this file is to illustrate how to read and write
 * structs to a file in C. This will be useful for reading and 
 * writing structs when managing blocks in your assignment.
 *
 * You can execute this program in two modes, read or write. Read
 * will read a coordinate point from a file and write will write
 * a point to the file. Each of these operations takes an index.
 * Write takes an additional three parameters which represent the
 * x, y, and z values for the point. You can see example invocations
 * below.
 *
 * Read invocation (arguments are r index):
 * ./a.out r 5
 *
 * Write invocation (arguments are w index x y z):
 * ./a.out w 5 1 2 3
 *
 */

#include <stdio.h>

FILE *fp;

typedef struct Point {
	long x;
	long y;
	long z;
} Point;

void read_struct(FILE *fp, int index);
void write_struct(FILE *fp, int index, Point p);

int main(int argc, char **argv) {
	if (argc == 3 && *argv[1] == 'r') {
		int index;
		int ret = sscanf(argv[2], "%d", &index);
		if (ret < 1) {
			printf("err\n");
			return -1;
		}
		fp = fopen("./myfile", "r");
		read_struct(fp, index);
	} else if (argc == 6 && *argv[1] == 'w') {
		Point p;
		int index;
		int reti = sscanf(argv[2], "%d", &index);
		int retx = sscanf(argv[3], "%ld", &p.x);
		int rety = sscanf(argv[4], "%ld", &p.y);
		int retz = sscanf(argv[5], "%ld", &p.z);
		if (reti < 1 || retx < 1 || rety < 1 || retz < 1) {
			printf("err\n");
			return -1;
		}
		fp = fopen("./myfile", "w");
		write_struct(fp, index, p);
	} 
	fclose(fp);	
}

void write_struct(FILE *fp, int index, Point p) {
	int offset = index * sizeof(Point);
	fseek(fp, offset, SEEK_SET);	
	fwrite(&p, sizeof(Point), 1, fp);
	printf("Finished logging point (%ld,%ld,%ld).\n", p.x, p.y, p.z);
}


void read_struct(FILE *fp, int index) {
	Point result;
	int offset = index * sizeof(Point);
	fseek(fp, offset, SEEK_SET);	
	fread(&result, sizeof(Point), 1, fp);
	printf("Point:\n\tx: %ld\n\ty: %ld\n\tz: %ld\n", 
		result.x, result.y, result.z);
}


