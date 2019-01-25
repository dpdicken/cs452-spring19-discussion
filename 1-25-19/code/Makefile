all: process thread linear_sort 

process: process.c
	gcc process.c -o process

thread: thread.c
	gcc -o thread thread.c -lpthread

linear_sort: linear_sort.c
	gcc -o linear_sort linear_sort.c

clean:
	rm linear_sort thread process
