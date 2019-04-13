#include<stdio.h>
void insert_sort(int a[],int n);
int main(){
	int a[]={987,546,24,56,87,98,45,65,47,68,423};
	int n=11;
	int j; //need to print
	/*start print*/
	printf("0-{");
	for(j=0;j<n;j++){
			printf("%d ",a[j]);
	}
	printf("}\n\n");
	/*stop print*/
	insert_sort(a,n);
	return 0;
}
void insert_sort(int a[],int n){
	int i,loc,newitem;
	int j; //need to print
	for(i=1;i<n;i++){
		loc=i-1;
		newitem=a[i];
		while(loc>=0&&newitem<a[loc]){
			a[loc+1]=a[loc];
			loc=loc-1;
			//printf(" %d -",a[loc+1]);
		}
		a[loc+1]=newitem;
		/*start print*/
		printf("\n%d-{",i);
		for(j=0;j<n;j++)
			printf("%d ",a[j]);
		printf("}\n\n");
		/*stop print*/
	}
}
