#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "file.h"
#include "employee.h"

//function prototypes

void print_usage(void);
int main(int argc , char *argv[]){
	bool newfile = false;
	char *filepath = NULL;
	char *employee = NULL; 
	int filedesc;
	if(argc < 3){
		print_usage();
		return 0;
	}
	int opt;
	while((opt = getopt(argc, argv, "nf:a:d:"))!= -1){
		switch(opt){
			case 'n':
				//printf("A newfile should be created\n");
				newfile = true;		
				break;
			case 'a':	
				printf("A new employee %s should be added\n", optarg);
				employee = optarg;		
				break;
			case 'd':
				printf("employee %s should be deleted\n", optarg);
				break;
			case 'f':
				//printf("%s should be filepath\n", optarg);
				filepath = optarg;
				break;
			case '?':
				printf("Unknow option!\n");
				break;
			default:
				printf("Something went wrong\n");
				return -1;
		}
	
	}

	if(newfile){
			filedesc = create_db_file(filepath);
			if(filedesc == -1){
				printf("File could not be created\n");
				close(filedesc);
				return -1;
			}
		}
	else{
		if(filepath != NULL){
			filedesc = open_db_file(filepath);
			if(filedesc == -1){
				printf("Bad file descriptor\n");
				close(filedesc);
				return -1;
			}
			if(employee != NULL){
				add_employee(filedesc, employee);
				printf("Added the employee %s\n",employee);
			}

			
		}
	}
	//printf("%d\n%s\n", newfile, filepath);
	
}



void print_usage(void){
	printf("Usage: cdb -n -f <filepath> -ad <employeename> \n");

	printf("\t -n create a new database file\n");
	printf("\t -f (requiered) filepath to database file\n");
	printf("\t -a create a new employee structure\n");
	printf("\t -d delete an existing employee structure\n");
}

