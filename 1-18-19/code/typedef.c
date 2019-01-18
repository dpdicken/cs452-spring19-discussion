
typedef unsigned long unsigned_long;

typedef struct coordinates {
	unsigned_long x;
	unsigned_long y;
} Coordinate;

typedef struct line {
	Coordinate p1, p2;
} Line;


Coordinate midpoint(Line *line) {
	Coordinate mid;

	mid.x = (line->p1.x + line->p2.x) / 2;
	mid.y = (line->p1.y + line->p2.y) / 2;

	return mid;
}

int main() {

	unsigned_long value = 5;
	
	Coordinate one, two;

	one.x = 20;
	one.y = 10;

	two.x = 10;
	two.y = 20;
	
	Line line;
	line.p1 = one;
	line.p2 = two;
	
	Coordinate res = midpoint(&line);
}
