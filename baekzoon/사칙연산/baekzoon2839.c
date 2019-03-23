//백준-2839
//3kg, 5kg으로 최소 봉지의 개수 
#include <stdio.h>
int main(){
	int a=0,num;
	scanf("%d",&num);
	for(;;a++){
		if(num%5==0){
			a+=num/5;
			break;
		}
		num-=3;
		if(num<0)
			break;
	}
	if(num<0)
  		printf("-1");
	else	
		printf("%d",a);
	return 0;
}
