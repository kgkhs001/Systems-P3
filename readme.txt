Author: Krishna Garg


PROGRAMS
tester.c
Description: This program is used to demonstrate all the functions that we created to show what we can do with our struct of Employee.
This program references structs.h 
which holds the signatures 
	Employee *make_employee(const char* name, int birth_year, int start_year);
	void print_struct(Employee *e1);
	int rand_int_gen(int range);
	Employee *random_employee_gen();
	Employee **struct_array(size_t size);
	void print_employees(Employee **array, size_t count);
	Employee **shallow_copy(Employee **og, size_t size);
	void free_structs(Employee **structs, size_t size);
	
These are all used to make and manipulate structs as well as other things.

How to Generate Executable
This is what is done in the makefile
compiling
tester.o: tester.c structs.h mystring.h
	gcc -c tester.c
	

linking
tester: tester.o structs.o mystring.o
	gcc tester.o structs.o mystring.o -o tester

How to Run
./tester
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
ctest.c
Description
This program is used to demonstrate our recreations of the built in string manipulating functions

This program uses mystring.h which holds the signatures to
	int mystrlen(const char * s);
	char *mystrcpy(char * dest, const char * src);
	char *mystrcat(char *dest, const char *src);
	char *mystrncat(char *dest, const char *src, size_t n);
	char *mystrncpy(char *dest, const char *src, size_t n);
	char *mystrndup(const char *s, size_t n);
	char rand_char_gen();
	const char* rand_str_gen(size_t size);


How to Generate Executable
this is what is done in the makefile
compiling
ctest.o: ctest.c mystring.h
	gcc -c ctest.c

linking
ctest: ctest.o mystring.o
	gcc ctest.o mystring.o -o ctest

How to Run
./ctest

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
MAKE COMMANDS
make clean - deletes all executable and object files
make docs - transfers all the files in the html file in the local directory to the public directory in public_html/cs2303_hw03
make - creates all executable and object files

