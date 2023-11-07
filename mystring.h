/** mystring.h
 * @author Mike Ciaraldi, Blake Nelson
 * My own versions of some of the C-style string functions
*/
#ifndef MYSTRING_H		// Remember guard
#define MYSTRING_H

// Function prototype(s):
char* mystrdup(const char* src);
int mystrlen(const char * s);
char *mystrcpy(char * dest, const char * src);
char *mystrcat(char *dest, const char *src);
char *mystrncat(char *dest, const char *src, size_t n);
char *mystrncpy(char *dest, const char *src, size_t n);
char *mystrndup(const char *s, size_t n);
char rand_char_gen();
const char* rand_str_gen(size_t size);
#endif
