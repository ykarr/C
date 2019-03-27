//백준-11721번
//n개의 단어를 한줄에 10글자씩 끊어서 출력 
//입력은 주어짐 
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
