#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

int main(int argc, char **argv) {

	if (argc != 2) 
		goto error;

	char *filename = *(argv + 1);
	int fd;
	if ((fd = open(filename, O_RDONLY)) == -1)
		goto error;

	void *buffer = mmap(0, 1024, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
	ssize_t nread;
	while ((nread = read(fd, buffer, 1024)) > 0) {
		ssize_t ntotalwritten = 0;
		while (ntotalwritten < nread) {
			ssize_t nwritten = write(STDOUT_FILENO, buffer + ntotalwritten, nread - ntotalwritten);
			if (nwritten < 1)
				goto error;
			ntotalwritten += nwritten;
		}
	}

	if (close(fd) != 0)
		goto error;
	return 0;

error:
	write(STDOUT_FILENO, "error\n", 6);
	return 1;
}
