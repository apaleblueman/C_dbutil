#include "employee.h"
#include <unistd.h>
#include <string.h>

int add_employee(int fd, char *employee){
	if(fd !=-1){
		write(fd, employee, strlen(employee));
		return 0;
	}
	return -1;
};
