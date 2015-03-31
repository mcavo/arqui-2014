/***************************************************
  Math.c
	
****************************************************/

int pow(int base,int exp){
	if(base==0){
		return 0;
	}	
	int resp=1;
	while(exp!=0){
		resp=resp*base;
		exp--;
	}
	return resp;
}
