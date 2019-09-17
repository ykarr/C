#include<stdio.h>
int main(){
	int a,b,count,i=1;
	scanf("%d",&count);
	for(;count>0;count--,i++){
		scanf("%d",&a);
		scanf("%d",&b);
		printf("Case #%d: %d\n",i,a+b);
	}
	
	return 0;
}


