#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#include "file.h"

int create_db(char *filepath){
	int fd;
	if((fd = open(filepath, O_RDONLY))!= -1){
		printf("File already exists\n");
		close(fd);
		return -1;
	}
	fd = open(filepath, O_CREAT, S_IRWXU);
	if(fd == -1){
		perror("open");
		close(fd);
		return -1;
	}
	return fd;
};

int open_db(char *filepath){
	int fd;
	fd = open(filepath, O_RDWR);
	if(fd == -1){
		perror("open");
		close(fd);
		return -1;
	}
	return fd;
};

