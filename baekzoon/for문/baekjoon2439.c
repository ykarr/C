//백준-2439번 별찍기-2 
//n은 정해짐 
#include<stdio.h>
int main(){
	int i,j,k,d;
	scanf("%d",&j);
	for(i=1;i<=j;i++){
		for(k=0;k<j-i;k++)
			printf(" ");
		for(k=1;k<=i;k++)
			printf("*");
		printf("\n");
		
	}
	return 0;
}
