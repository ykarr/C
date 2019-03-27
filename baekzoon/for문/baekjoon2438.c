//백준-2438번 별찍기-1 
//n은 정해짐 
#include<stdio.h>
int main(){
	int i,j,k;
	scanf("%d",&j);
	for(i=1;i<=j;i++){
		for(k=1;k<=i;k++){
			printf("*");
		}
		printf("\n");
		
	}
	return 0;
}
