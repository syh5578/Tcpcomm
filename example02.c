#define BUF_SIZE 1024
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

ssize_t read(int fd, void * buf, size_t nbytes);

void error_handling(char * message);
int main(void)
{
	int fd;
	char buf[BUF_SIZE];
	fd=open("data.txt", O_RDONLY);
	if(fd==-1)
		error_handling("open() error!");
	printf("file descriptor: %d \n", fd);

	if(read(fd, buf, sizeof(buf))==-1)
		error_handling("write() error!");
	printf("file data: %s", buf);
	close(fd);
	return 0;
}

void error_handling(char * message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
