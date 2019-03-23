//백준-2739번 구구단 
//단은 정해짐 ("%d단",구구) 
#include<stdio.h>
int main(){
	int i,j;
	scanf("%d",&j);
	for(i=1;i<10;i++){
		printf("%d * %d = %d\n",j,i,j*i);
	}
	return 0;
}
