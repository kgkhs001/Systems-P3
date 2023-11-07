/** mystring.c
 * @Krishna Garg
 * Custom versions of some of the C-style string functions
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
// Have to #include stdlib.h because it is needed to use malloc()
#include "mystring.h"
#include <time.h>

/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrdup(const char* src) {
  int length; 	// Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = mystrlen(src) + 1;  		// Leave space for the terminator
  newstr = (char*) malloc(length); 	// Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) {
	return (char *) 0;
  }

  // Otherwise, copy the string and return pointer to new string
  mystrcpy(newstr, src);
  return newstr;
}

/** Calculates the length of an inputted string of characters
* If nothing is entered than the function will return 0
* @param The string that you want to find the length of
* @return The length of the inputted string in memory without the \n
**/
int mystrlen(const char* s){
	int length = 0;
	
	while(*s != '\0'){
		length++;
		s++;
	}
	
	return length;
}
/** Copies the second string inputted to the memory of the first input.
* @param destination of the copied product
* @param the product you want to copy
* @return the pointer defined in the funtion to the destination
**/
char *mystrcpy(char * dest, const char * src){
	char *ptr = dest;	//declare a pointer pointing to the destination 
	while(*src != '\0'){
		*dest = *src;
    		dest++;
    		src++;
  	}
  *dest = '\0';
  return ptr;
}
// HOMEWORK 3 FUNCTIONS
/** 
* mystrcat() fucntion appends the src string to the dest string overwriting the terminatiing null byte ('\0')
* at the end of dest and then adds a terminating null byte. the strings may not overlap and the dest string must have enough space for the result. 
* If dest is not large enough, program behavior is unpredictable this is where the content will be copied
* @param *dest is a pointer to the destination array
* @param *src is a pointer to the source array
* @return a pointer to the concatenated string
**/
char *mystrcat(char *dest, const char *src){
	char *temp = dest;
	
	while(*temp != '\0'){
		temp++;
	}
	
	while(*src != '\0'){
		*temp++ = *src++;
	}
	
	*temp = '\0';
	return dest;
}

/**
* mystrncat() is the same as mystrcat() except for
* it will use at most n bytes from src
* src does not need to be null terminated if it contains n or more bytes 
* the resulting string in dest is always null terminated (same as mystrcat)
* @param *dest is a pointer to the destination array
* @param *src is a pointer to the source array
* @param n is the maximum number of characters to be appended
* @return a pointer to the concatenated string
**/
char *mystrncat(char *dest, const char *src, size_t n){
	char *temp = dest;
	
	while(*temp != '\0'){
		temp++;
	}
	
	while(n != 0){
		n--;
		*temp++ = *src++;
	}
	
	*temp = '\0';
	return dest;
}

/**
* *mystrncpy() function is similar to strcpy() except that at most n bytes of src are copied. 
* Warning: If there is no null byte among the first n bytes of src, the string placed in dest will
* not be null-terminated
* If the length of src is less than n, mystrncpy() writes additional null bytes to dest to ensure that 
* a total of n bytes are written
* @param dest is where you are copying the string to
* @param src is the string you want to copy
* @param n is the size in length of how much of the src you want to copy
* @return return a pointer to the destination string dest
**/
char *mystrncpy(char *dest, const char *src, size_t n){
	char *ptr = dest;	//declare a pointer pointing to the destination 
	while(n != 0){
		n--;
		if(*src != '\0'){
			*dest = *src;
    			dest++;
    			src++;
  		}
		else{
		while(*dest != '\0'){
		   *dest = NULL;
		   dest++;  
		 }
	     }
		}
 	*dest = '\0';
  return ptr;
}

/** mystrndup() function returns a pointer to a new string which is a duplicate of thes tring s (inputted string)
* Memory for the new string is obtained wih malloc(3) and can be freed with free(3)
* this function only copies at most n bytes of the s string. If s is longer than n bytes then only n bytes
* are copied and a null teriminating byte ('\0') is added
* Upon success the strdnup function returns a pointer to the duplicated string. It returns NULL if
* insufficient memory was available, with errno set to indicate the cause of the error.
* @param *s is a pointer to string s. The source string essentially
* @param n is how many bytes you want to copy of s
* @return a pointer to the duplicated string
**/
char *mystrndup(const char *s, size_t n){
	char *dup = malloc(n+1);    //pointer to the allocated memory
	if(dup == NULL){
    return NULL;
  }
  mystrncpy(dup, s, n);
	return dup;
  free(dup);
}


//PROGRAMMERS NOTE: ASCII CHAR VALUES : LOOK AT DEC
/** rand_char_gen() randomly generates an upper case letter in the english alphabet (A-Z)
*
**/
char rand_char_gen(){
  //srand(time(0));   // Initialization, should only be called once. This is called in the random string generator because otherwise this won't work correctly
  char rand_val = (char) (rand() % 26) + 'A'; 
  return rand_val;
}

/** rand_str_gen generates a random string with characters that are only upper case letters from the english alphabet
* @param size is the length of the string that you want generated
* @return a string of randomly generated characters
* Enough memory for the size entered plus one is stored using malloc. It is plus one because of the terminating character. After all the memory is allocated and the function is done
* the memory is freed. 
**/
const char *rand_str_gen(size_t size){
  char *ptr =  malloc(sizeof(char) * (size+1));
  int i;
  //srand(time(NULL));
  for(i = 0; i < size; i++){
    ptr[i] = rand_char_gen();
  }
  ptr[size] = '\0';
  return ptr;
  free(ptr);
}
















