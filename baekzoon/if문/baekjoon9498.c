//백준-9498번 시험성적 문제 
//숫자는 주어짐 
#include<stdio.h>
int main(){
	int s;
	scanf("%d",&s);
	switch(s/10){
		case 10:
		case 9:
			printf("A");
			break;
		case 8:
			printf("B");
			break;
		case 7:
			printf("C");
			break;
		case 6:
			printf("D");
			break;
		default:
			printf("F");
	}
	return 0;
}
