#ifndef FILE_H
#define FILE_H


int create_db(char *filepath);
int open_db(char *filepath);
char read_db(int fd, char *dataread);

#endif
