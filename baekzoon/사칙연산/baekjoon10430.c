//백준-10430번문제 계산 
//세개의 자연수는 제공됨. 
#include<stdio.h>
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c); //입력받음 

	printf("%d\n",(a+b)%c);
	printf("%d\n",(a%c+b%c)%c);
	printf("%d\n",(a*b)%c);
	printf("%d\n",(a%c*b%c)%c);
	return 0;
}
