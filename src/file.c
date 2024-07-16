#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "file.h"



int create_db_file(char *filepath){
	
	int fd;
	fd = open(filepath, O_RDONLY);
	if(fd != -1){
		printf("This file already exists\n");
		close(fd);
		return -1;
	}
	fd = open(filepath, O_CREAT | O_WRONLY, S_IRWXU);
	if(fd == -1){
		perror("open");
		close(fd);
		return -1;
	}
	return fd;

}

int open_db_file(char *filepath){
	int fd;
	fd = open(filepath, O_RDWR);
	if(fd == -1){
		perror("open");
		close(fd);
		return -1;
	}
	printf("Filename to be read : %s\n", filepath);
	return fd;

}
