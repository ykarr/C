//����-11721��
//n���� �ܾ ���ٿ� 10���ھ� ��� ��� 
//�Է��� �־��� 
#include<stdio.h>
#include<string.h>
int main(){
	int length,i,sum=0;
	char array[100];
	scanf("%s",array);
	length=strlen(array);
	for(i=1;i-1<length;i++){	
		printf("%c",array[i-1]);
		if(i%10==0)
			printf("\n");
	}
	//printf("%d",sum);
	return 0;
}
