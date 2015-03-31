/***************************************************
  String.c
	
****************************************************/


void strrev( char* s ) {
	int dim = 0, i=0;
	char aux;
	for (i=0; s[i]!=0;i++){
		dim++;
	}
	for (i=0; i<dim/2 ;i++) {
		aux=*(s+i);
		s[i]=s[dim-1-i];
		s[dim-1-i]=aux;
	}
}

int strcmp(char* s1, char* s2){
	int i;
	for(i=0;s1[i]!='\0'&& s2[i]!='\0';i++){
		if(s1[i]!=s2[i]){
			return 0;
		}
	}
	if(s1[i]=='\0' && s2[i]=='\0'){
		return 1;
	}
	return 0;
}
