#include <unistd.h>
#include <string.h>
#include "employee.h"





int add_employee(int fd,char *employeedetails){
	write(fd, employeedetails, strlen(employeedetails));
	
}


