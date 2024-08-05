#include<stdio.h>
#include<string.h>

int isAccepted(const char* str){
	int cstate = 0;
	for(int i=0;i<strlen(str);i++){
		if(str[i]!='0' && str[i]!='1')	return 0;
		switch(cstate){
			case 0: if(str[i]=='1')	cstate=0;
				if(str[i]=='0')	cstate=1;
				break;
			case 1: if(str[i]=='0')	cstate=2;
				if(str[i]=='1')	cstate=0;
				break;
			case 2: if(str[i]=='0')	cstate=2;
				if(str[i]=='1')	cstate=3;
				break;
			case 3: if(str[i]=='0' || str[i]=='1')	cstate=3;
				break;
		}
	}
	return cstate==2||cstate==3 ? 1 : -1;
}

int main(){
	printf("Enter a string using 0 and 1: ");
	char str[100];
	scanf("%s",str);
	int result=isAccepted(str);
	if(result==0)	printf("Invalid Input!!\n");
	else if(result==1)	printf("Valid String!!\n");
	else if(result==-1)	printf("Invalid String!!\n");
	return 0;
}
