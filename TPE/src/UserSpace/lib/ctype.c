/***************************************************
  Ctype.c
	
****************************************************/

#include "libc.h"

int toupper (int c) {
	if(islower(c))
		return c - ('a'-'A');
	return c;
}

int tolower (int c) {
	if(isupper(c))
		return c + ('a'-'A');
	return c;
}

int isalnum(int c) {
	return isdigit(c) || isalpha(c);
}

int isdigit(int c) {
	return (c <= '9' && c >= '0');
}

int isalpha(int c) {
	return isupper(c) || islower(c);
}

int isupper(int c) {
	return (c <= 'Z' && c >= 'A');
}

int islower(int c) {
	return (c <= 'z' && c >= 'a');
}

