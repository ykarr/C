//백준-8393번 합 (펙토리얼)
//숫자는 주어짐 
#include<stdio.h>
int main(){
	int i,j,sum=0;
	scanf("%d",&i);
	for(j=1;j<=i;j++){
		sum+=j;
	}
	printf("%d",sum);
	return 0;
}
