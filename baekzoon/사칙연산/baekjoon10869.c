//백준-10869번문제 계산 
//두 자연수는 제공됨. 
#include<stdio.h>
int main(){
	int i,j,c,d,e,f,g;
	scanf("%d%d",&i,&j); //입력받음 
	c=i+j; 
	d=i-j;
	e=i*j;
	f=i/j;
	g=i%j;
	printf("%d\n",c);
	printf("%d\n",d);
	printf("%d\n",e);
	printf("%d\n",f);
	printf("%d\n",g);
	return 0;
}
