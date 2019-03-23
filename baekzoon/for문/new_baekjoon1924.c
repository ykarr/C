#include<stdio.h>
int main(){
	//				  1  2  3  4  5  6  7  8  9  10 11 12
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	char day[7][4] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	int i,j,a,b,sum=0;
	scanf("%d%d",&i,&j);
	if(2>i){
		for(b=1;b<=j;b++,sum++);
	}
	else{
		for(a=1;a<i;a++){
			sum+=month[a-1];	
		}
		for(b=1;b<=j;b++,sum++);
	}
	printf("%s",day[sum%7]);
	return 0;
	
}  
