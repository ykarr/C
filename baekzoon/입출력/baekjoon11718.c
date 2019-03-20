//백준-11718 입력받은 그대로출력
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
