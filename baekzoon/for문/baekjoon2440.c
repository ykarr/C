//백준-2440번 별찍기-3
//n은 주어짐
#include<stdio.h>
int main(){
	int i,j,k;
	scanf("%d",&j);
	for(i=0;i<=j;i++){
		for(k=0;k<j-i;k++)
			printf("*");
		printf("\n");
	}
	return 0;
} 
