#include<stdio.h>
int main(){
	int i, j;
	double high=0,sum=0,array[1000],n;
	scanf("%d",&j);
	for(i=0;i<j;i++){
		scanf("%d",&n);
		array[i]=n;
		if(high<array[i])
			high=array[i];
	}
	for(i=0;i<j;i++){
		sum+=((array[i]/high)*100);
	}
	printf("%.2lf",sum/j);
	return 0;
}
