// string.h covers the C-style string functions.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystring.h"
#include "structs.h"
#include <time.h>

#define STRUCT_SIZE 3
/** tester.c
 * description here
 * @author Krishna Garg
 */
int main(){
  srand(time(NULL));
  
  //this is here to show the creation and printing of a struct
  Employee *e1 = make_employee("name", 2005, 2016);
  print_struct(e1); //should print e1 data
  
  Employee *e2 = make_employee("krishna garg", 1987, 2004);
  print_struct(e2); //should print e2 data
  
  //generating a random array of structs of Employee with random names and birth years
  printf("\n");
  printf("Array of employees\n");
  Employee **struct_list =  struct_array(STRUCT_SIZE);
  print_employees(struct_list, STRUCT_SIZE);
  
  //shallow copy of the struct
  printf("\nThe copy\n");
  Employee **copy = shallow_copy(struct_list, STRUCT_SIZE);
  print_employees(copy, STRUCT_SIZE);
  
  //free the memory
  free_structs(struct_list, STRUCT_SIZE);
}
