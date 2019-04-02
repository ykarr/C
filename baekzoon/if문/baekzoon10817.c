#include<stdio.h>
#define SWAP(a,b,t) ((t)=(a),(a)=(b),(b)=(t))
int main(){
	int array[3];
	int i=0,j,tmp;
	for(i=0;i<3;i++){
		scanf("%d",&array[i]);
	}
	
	for(i=0;i<2;i++){
		for(j=0;j<2-i;j++){
				if(array[j]>array[j+1])		
					SWAP(array[j],array[j+1],tmp);
		}
	} 
	//for(i=0;i<3;i++){
		printf("%d\n",array[1]);
	//}         	
	return 0;		
}
