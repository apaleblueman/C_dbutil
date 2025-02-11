#include<stdio.h>
#include<unistd.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

#include "file.h"
#include "employee.h"


void print_usage(void);

int main(int argc, char *argv[]){
	if(argc < 3){
		printf("Not enough arguments for cdb\n");
		print_usage();
		return 0;
	}
	int opt, filedesc;
	bool newfile, addemployee, delemployee;
	char *filepath = NULL;
	char *employeeToAdd = NULL;
	char *employeeToDel = NULL;
	while((opt=getopt(argc, argv, "na:d:f:"))!=-1){
		switch(opt){
			case 'n':
				newfile = true;
				break;
			case 'f':
				filepath= optarg;
				break;
			case 'a':
				addemployee = true;
				employeeToAdd = optarg;
				break;
			case 'd':
				delemployee = true;
				employeeToDel = optarg;
				break;
			case '?':
				printf("Unknown Option\n");
				print_usage();
				break;
			default:
				printf("Something went wrong!\n");
				return -1;				
		}
	}
	if(newfile && filepath!=NULL){
		//create a newdbfile
		printf("%d\n",filedesc);
		filedesc = create_db(filepath);
		if(filedesc!= -1){
			printf("Created a new empty dbfile\n");
			if(addemployee){
				//add new employee in the dbfile
				add_employee(filedesc, employeeToAdd);
				printf("added a new employee %s\n", employeeToAdd);
			}
			else if(delemployee){
				//del_employee(emp_details);
				printf("No employee to delete\n");
				return -1;
			}
		}
		else{
			close(filedesc);
			return -1;
		}
		
		
	}
	else{
		filedesc = open_db(filepath);
		if(filepath != NULL){
			if(addemployee){
				//add new employee to existing db file
				add_employee(filedesc, employeeToAdd);
				printf("Created a new employee in previousdbfile\n");
				
			}
			else if(delemployee){
				//delete employee from dbfile
				printf("deleted an employee in previousdbfile\n");
				
			}
			else{
				//view the dbfile
				char *dataread = malloc(sizeof(char)*1000);
				read_db(filedesc, dataread);
				printf("\n%s\n",dataread);
			}
		}
		else{
			print_usage();
			return -1;
		}
	}

	printf("filepath:%s\nnewfile=%d\nemployeetoadd=%s\nemployeetodel=%s\n", filepath,newfile, employeeToAdd,employeeToDel);

}


void print_usage(void){
	printf("Usage: cdb -nf <filepath> -ad <employeedetails>\n");
	printf("\t -n make new database file\n");
	printf("\t -f (requiered) filepath to database file\n");
	printf("\t -a add employee to database file\n");
	printf("\t -d delete employee from database file\n");
};
