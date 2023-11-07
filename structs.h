/** mystring.h
 * @author Krishna Garg
 * Functions for the structs functions
*/
#ifndef STRUCTS_H	
#define STRUCTS_H
#define STRING_SIZE 15
#define YEAR 2022
#define MAX_AGE 90
typedef struct _employee Employee;
struct _employee {
  //char *name = malloc(sizeof(char) * STRING_SIZE);
  char name[STRING_SIZE];
  int field_one;
  int field_two;
};

// Function prototype(s):
Employee *make_employee(const char* name, int birth_year, int start_year);
void print_struct(Employee *e1);
int rand_int_gen(int range);
Employee *random_employee_gen();
Employee **struct_array(size_t size);
void print_employees(Employee **array, size_t count);
Employee **shallow_copy(Employee **og, size_t size);
void free_structs(Employee **structs, size_t size);
#endif
