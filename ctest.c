// string.h covers the C-style string functions.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystring.h"

/** ctest.c
 * Program to demonstrate character arrays and dynamically-allocated memory.
 * @author Mike Ciaraldi, Blake Nelson
 */

const int MAX_CHARS = 20;       // Maximum number of characters in array

int main()
{
  char a1[MAX_CHARS + 1]; 	// Character array--initially empty
  char a2[] = "Hello"; 		// Character array--unsized but initialized
  char a3[MAX_CHARS + 1]; 	// Character array--we will underfill it
  const char *p1 = "Hello";     // Pointer to constant string
  char *p2;           		// Will be a pointer to dynamically-allocated string
  int copy_limit;     		// Maximum characters to copy.


  /* Print the pointers.
     Note: this example prints
     the values of the pointers themselves, not the targets.
  */
  printf("Arrays:   a1: %p, a2: %p, a3: %p\n", a1, a2, a3);
  printf("Pointers: p1: %p, p2: %p\n", p1, p2);

  mystrcpy(a1, "Hi"); 		// Initialize character array a1 with some text
  mystrcpy(a3, "Hello, also");    // Initialize uinderfilled character array


  // Print the values of the C-style strings
  printf("\n");
  printf("C-string values:\n");
  printf("a1: %s\n", a1);
  printf("a2: %s\n", a2);
  printf("a3: %s\n", a3);

  /* Concatenate two character arrays, then print.
  *  Terminator character in the last element of the array as well as after "Hi"
  */
  a1[MAX_CHARS] = '\0';		
  mystrcat(a1, a2);
  printf("\n");
  printf("After concatenating a2 to the end of a1\n");
  printf("a1: %s\n", a1);

  // Concatenate two character arrays safely, then print.
  copy_limit = MAX_CHARS - mystrlen(a1); 	// How much space is left?
  
  printf("\n");
  printf("Concatenating a2 to a1, with copy_limit = %d\n", copy_limit);
  if (copy_limit > 0) {
	mystrncat(a1, a2, copy_limit);
  }
  printf("a1: %s\n", a1);

  // Concatenate two character arrays safely, then print.
  copy_limit = MAX_CHARS - mystrlen(a1); 	// How much space is left?
  printf("\n");
  printf("Concatenating a3 to a1, with copy_limit = %d\n", copy_limit);
  if (copy_limit > 0) {
	mystrncat(a1, a3, copy_limit);
  }
  printf("a1: %s\n", a1);

  // Duplicate a string, using my function, then print
  printf("\n");
  printf("Before dup, array a2 = %p, contents = %s\n", a2, a2);
  p2 = mystrdup(a2);
  printf("After dup, pointer p2 =  %p, contents = %s\n", p2, p2);


  char a[20];    // Initially-empty character array 
  strcpy(a, "ABCDEFGHIJ"); // Fill the first 10 elements, 
         // plus the terminator in a[10]. 
  printf("String a = %s\n", a); 
  
  mystrncpy(a, "TUVWXYZ", 3); // Only copy first 5 characters. 
  printf("String a after copy = %s\n", a); 	//Should print TUVDEFGHIJ
  // Free the memory allocated on our behalf by mystrdup()
  
  
  char b[20];    // Initially-empty character array 
  strcpy(b, "ABCDEFGHIJ"); // Fill the first 10 elements, 
         // plus the terminator in a[10]. 
  printf("String b = %s\n", b); 
  mystrncpy(b, "TUVWXYZ", 10); // Only copy first 5 characters. 
  printf("String b after copy = %s\n", b); 	//should print TUVWXYZ
  // Free the memory allocated on our behalf by mystrdup()
  
  
  
  char source[] = "GeeksForGeeks";
 
    // 5 bytes of source are copied to a new memory
    // allocated dynamically and pointer to copied
    // memory is returned.
    char* target = mystrndup(source, 20);
 
    printf("First 13 and rest 7 null: %s\n", target);

    char* target2 = mystrndup(source, 5);
    printf("First 5: %s\n", target2);
    
    char* target3 = mystrndup(source, 10);
    printf("First 10: %s\n", target3);
    
    
    printf("Normal Function:\n");
    char* target4 = strndup(source, 20);
    printf("First 13 and rest 7 null: %s\n", target4);
    
    char* target5 = strndup(source, 5);
    printf("First 5: %s\n", target5);
    
    char* target6 = strndup(source, 10);
    printf("First 10: %s\n", target6);
    
    free(p2);

  return 0;
}
