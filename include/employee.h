#ifndef EMPLOYEE_H
#define EMPLOYEE_H

struct employee_t{
	int id;
	char name[265];
	char address[265];
	int hours;
};
int add_employee(int fd ,char *employeedetails);
int delete_employee(char *employeename);

#endif
