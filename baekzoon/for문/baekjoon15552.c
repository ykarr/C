//백준-15552번 빠른a+b 
//입력은 주어짐 
#include<stdio.h>
int main(){
	int i,j,a,b;
	scanf("%d",&j);
	for(i=0;i<j;i++){
		scanf("%d%d",&a,&b);
		printf("%d\n",a+b);
	}
	return 0;
}
