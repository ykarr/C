//����-11720 ������� ���ڸ� ���� 
//���̿� ���ڴ� �־��� 
#include<stdio.h>
int main(){
	int length,i,sum=0;
	char array[100];
	scanf("%d",&length);
	scanf("%s",array);
	for(i=0;i<length;i++){
		sum+=(array[i]-'0');
		//printf("%d",array[i]-'0');
	}
	printf("%d",sum);
	return 0;
}
