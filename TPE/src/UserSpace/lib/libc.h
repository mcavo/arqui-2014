/**********************
 libc.h
**********************/

#ifndef _libc_
#define _libc_

/* stdio.h */
void printf (const char *format,...);
void scanf (const char * format, ...);
int putchar (char c);
char getchar ();
void getd(int * d);

/* string.h */
int strcmp(char* s1, char* s2);
void strrev( char* s );

/* stdlib.h */
void itoa(int n,char*s);
void xtoa(int n,char* s);
int atoi(char * string);

/* math.h */
int pow(int base,int exp);

/* ctype.h */
int toupper (int c);
int tolower (int c);
int isalnum(int c);
int isdigit(int c);
int isalpha(int c);
int isupper(int c);
int islower(int c);

#endif
