//����-10430������ ��� 
//������ �ڿ����� ������. 
#include<stdio.h>
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c); //�Է¹��� 

	printf("%d\n",(a+b)%c);
	printf("%d\n",(a%c+b%c)%c);
	printf("%d\n",(a*b)%c);
	printf("%d\n",(a%c*b%c)%c);
	return 0;
}
