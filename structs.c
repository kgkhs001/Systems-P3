// string.h covers the C-style string functions.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystring.h"
#include "structs.h"
#include <time.h>
/** structs.c
 * Program to show how to use structs and other things
 * @author Krishna Garg
*/

/** make_employee() takes in the parameters for the struct Employee and creates an instance of the struct Employee with the inputted values
* @param name is the name of the employee
* @param birth_year is the employees date of birth
* @param start_year is the year that the employee got the job and started
**/
Employee *make_employee(const char* name, int birth_year, int start_year){
	Employee e1;
	Employee *ptr;
	ptr = malloc(sizeof(Employee));
	strcpy(ptr->name, "");
	strcpy(ptr->name, name);
	ptr->field_one = birth_year;
	ptr->field_two = start_year;
	return ptr;
}

/** print_struct() takes in an instance of Employee (an employee) and prints their fields
* @param e1 is the employee whose fields you want printed
**/
void print_struct(Employee *e1){
	printf("Name: %s\n", e1->name);
	printf("Birth Year: %d\n", e1->field_one);
	printf("Start Year: %d\n", e1->field_two);
}
/** Creats a random integer within the given range that cannot be zero
* @param the max value that your number can be minus 1
* @retrun a random integer value in the given range
**/
int rand_int_gen(int range){
	//srand(time(NULL));
	return ((rand() % range) + 1);
}


/** random_employee_gen() returns an instance of Employee filled with random values for name birth year and work start year
* @return  new Employee with random information
**/
Employee *random_employee_gen(){
	//srand(time(NULL));
	Employee e1;		//intialize employee
	const char* name = rand_str_gen(STRING_SIZE);	//create a random name
	int birth = YEAR - rand_int_gen(MAX_AGE);	//create a random birth year
	int age = YEAR - birth;
	int year = rand_int_gen(age) + birth;		//math to get their start year
	
	return make_employee(name, birth, year);
}

/** **struct_array() creates an array of pointers to structs of Employee that were randomly generated
* @param size is the size you want the array to be
* @return this function returns an array of pointers to the structs Employee that were randomly generated
**/
Employee **struct_array(size_t size){		//this will create an array of pointers that point to randomly generated structs
	Employee **ptr;
  	ptr = malloc(sizeof(Employee) * size);
	int i;
	for(i = 0; i < size; i++){
    		ptr[i] = random_employee_gen();
  }
	return ptr;
}

/** print_employees() prints an array of employees (takes in an array of pointers to instances of Employee however)
* @param array is the array of pointers to Employees that you want printed
* @param size is the length of the inputted array
**/
void print_employees(Employee **array, size_t count){
 	int i;
 	for(i = 0; i < count; i++){
 	 	print_struct(array[i]);	//takes in a pointer to a struct or Employee
 	 }
}

/** shallow_copy() creates a shallow copy of the inputted array of pointers
* @param og the array of pointers that you want to make a shallow copy of
* @param size is the size of og
* @return the copied array of pointers
**/
Employee **shallow_copy(Employee **og, size_t size){
	Employee **copy = malloc(sizeof(Employee) * size);
	int i;
	for(i = 0; i < size; i++){
		copy[i] = og[i];
	}
	return copy;
}

/** free_structs() frees the allocated memory from every pointer in the inputted array of pointers
* @param structs the array of structs
* @size is the size of the inputted array
**/
void free_structs(Employee **structs, size_t size){
	int i;
	for(i = 0; i < size; i++){
		free(structs[i]);
	}
}





