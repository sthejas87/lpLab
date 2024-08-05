#include<stdio.h>
#include<string.h>

int isAccepted(const char* str){
	int cstate=0;
	for(int i=0;i<strlen(str);i++){
		if(str[i]!='1' && str[i]!='2' && str[i]!='3')	return -1;
		switch(cstate){
			case 0: if(str[i]=='1')	cstate=1;
				else if(str[i]=='2')	cstate=2;
				else if(str[i]=='3') cstate=3;
				break;
			case 1: if(str[i]=='1') cstate=1;
				else if(str[i]=='2') cstate=2;
				else if(str[i]=='3') cstate=3;
				break;
			case 2: if(str[i]=='1') cstate=11;
				else if(str[i]=='2') cstate=2;
				else if(str[i]=='3') cstate=3;
				break;
			case 3: if(str[i]=='3') cstate=3;
				else cstate=11;
				break;
		}
	}
	return cstate!=11 ? 1 : 0;
}

int main(){
	char str[100];
	printf("Enter an input string to validate using 1,2,3: ");
	scanf("%s",str);
	int result = isAccepted(str);
	if(result==-1) printf("Invalid Input!!\n");
	else if(result==1)	printf("Valid String!!\n");
	else if(result==0)	printf("Invalid String!!\n");
	return 0;
}
