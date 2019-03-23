//백준-2441번 별찍기-4 
//n은 정해짐 
#include<stdio.h>
int main(){
	int i,j,k,d;
	scanf("%d",&j);
	for(i=0;i<j;i++){
		for(k=1;k<=i;k++)
			printf(" ");		
		for(k=0;k<j-i;k++)
			printf("*");
		printf("\n");	
	}
	return 0;
}
