//백준-11719 입력 받은 그대로 출력하기2
#include<stdio.h>
int main(){
	char i;
	i=getchar();
	while(i!=EOF){
		putchar(i);
		i=getchar();
	}
	return 0;
} 
