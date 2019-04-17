#include<stdio.h>

void Quick_sort(int a[],int p,int r);
int partition(int a[],int p, int r);
void SWAP(int a[],int i,int j);
int main(){
	int a[]={987,546,24,56,87,98,45,65,47,68,423};
	int n=10;
	int j; //need to print

	Quick_sort(a,0,n);
	printf("----------------------------------\n");
		for(j=0;j<=n;j++)
			printf("%d ",a[j]);
	return 0;
}
void Quick_sort(int a[],int p,int r){
	int q,j;
	if(p<r){
		q=partition(a,p,r);
		Quick_sort(a,p,q-1);
		Quick_sort(a,q+1,r);
	}
}
int partition(int a[],int p, int r){
	int x=a[r];//pivot
	int i=p-1;
	//printf("%d",i);
	int j;//start
	for(j=p;j<r;j++)
		if(a[j]<x)
			SWAP(a,++i,j);
	SWAP(a,++i,r);
	for(j=p;j<=r;j++)
			printf("%d ",a[j]);
	printf("\n\n");
	return i;
}
void SWAP(int a[],int i,int j){
	int temp;
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}

			
