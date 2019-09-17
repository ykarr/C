#include<stdio.h>
int main(){
	//À±³â==1
	int inputyear,i,j,k; 
	scanf("%d",&inputyear);
	i=inputyear%4;
	j=inputyear%100;
	k=inputyear%400;
	if((i==0&&j!=0)||k==0){
		printf("1\n");
	}
	else
		printf("0\n");
	return 0;
}

