//백준-2742번 거꾸로 n찍기
//n은 주어짐 

#include<stdio.h>
int main(){
	int j;
	scanf("%d",&j);
	do{
		printf("%d\n",j);
		--j;
	}while(j!=0);
	return 0;
}
