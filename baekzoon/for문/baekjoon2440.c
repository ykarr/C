//����-2440�� �����-3
//n�� �־���
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
