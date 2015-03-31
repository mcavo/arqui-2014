/***************************************************
  Stdlib.c
	
****************************************************/

#include "libc.h"

void itoa(int n,char*s) {
	int i=0, rem;
	while (n!=0) {
		rem=n%10;
		*(s+i)=rem+'0';
		n/=10;
		i++;
	}
	*(s+i)=0;
	strrev(s);
}

void xtoa(int n,char* s) {
	int i=0,rem;
    	while (n!=0)
    	{
        	rem=n%16;
        	switch(rem)
        	{
		    case 10:
			      s[i]='A';
			      break;
		    case 11:
			      s[i]='B';
			      break;
		    case 12:
			      s[i]='C';
			      break;
		    case 13:
			      s[i]='D';
			      break;
		    case 14:
			      s[i]='E';
			      break;
		    case 15:
			      s[i]='F';
		              break;
		    default:
		      	      s[i]=rem+'0';
			      break;
		}
		++i;
		n/=16;
	}
	s[i]='\0';
	strrev(s); 
}

int atoi(char * string){
	int size=0;
	int res=0,j=0;
	while(*(string+size)!='\0'){
		size++;
	}
	while(*(string+j)!='\0'){
		res=res+((*(string+j)-'0')*pow(10,size-1));
		size--;
		j++;
	}
	return res;
}
