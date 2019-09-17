#include<stdio.h>
int main(){
	int a,b,count;
	scanf("%d",&count);
	for(;count>0;count--){
		scanf("%d",&a);
		scanf("%d",&b);
		printf("%d\n",a+b);
	}
	
	return 0;
}


