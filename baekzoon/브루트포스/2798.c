//���� ���� 
#include<stdio.h>
#define MAX 100
int main(){
	int n=0;//ī���� ���� 
	int m=0;//ī�� ���� �ѵ� 
	int near=0;//�ѵ��� ��ó�� 
	int sum=0;//ī�尪�� ���� �� 
	int i,j,k; //for���� ����� ����
	 
	int array[MAX];//ī���� ���ڸ� �迭�� ����. 
	scanf("%d%d",&n,&m); //input
	
	for(i=0;i<n;i++){ //�迭�� ī���� ������ŭ ���ڸ� �ִ´�. 
		scanf("%d",&array[i]);
	}
//	for(i=0;i<n;i++){//������ Ȯ�� 
//		printf("%d-",array[i]);
//	}
	//printf("\n");
	for(i=0;i<n;i++){//3��° ī���� ù��° 
		for(j=i+1;j<n;j++){//3��° ī���� �ι�° 
			for(k=j+1;k<n;k++){//3��° ī���� ����° 
				sum=array[i]+array[j]+array[k];//3���� ī�带 ���Ѱ��� sum�� ���� 
				//printf("%d %d %d ��=%d\n",array[i],array[j],array[k],sum);//���Ѱ� Ȯ�� 
				if(near<sum&&sum<=m){//near���� �־���� ���� ���� sum�� ���� �� sum�� �ѵ����� ����. 
					near=sum;//sum���� �ѵ����� �۰� ���� near������ �ѵ��� �����Ƿ� ��ü 
					//printf("near��=%d \n",near);
				}
				//if���� ������� �ʰ� 
				//near=near<sum&&sum<=m?sum:near; 
			}
		}	
	}
	printf("%d",near);//��� 
	return 0;
}
/*����1 
#include<stdio.h>
#define MAX 100
int main(){
	int n=0,m=0,near=0,sum=0,i,j,k;
	int array[MAX];
	scanf("%d%d",&n,&m); 
	for(i=0;i<n;i++){
		scanf("%d",&array[i]);}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			for(k=j+1;k<n;k++){ 
				sum=array[i]+array[j]+array[k];
				near=near<sum&&sum<=m?sum:near;
			}
		}	
	}
	printf("%d",near);
	return 0;
}
*/
/*����2
#include<stdio.h>
int main(){
	int n=0,m=0,near=0,sum=0,i,j,k;
	scanf("%d%d",&n,&m); 
	int array[n];
	for(i=0;i<n;i++){
		scanf("%d",&array[i]);}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			for(k=j+1;k<n;k++){ 
				sum=array[i]+array[j]+array[k];
				near=near<sum&&sum<=m?sum:near;
			}
		}	
	}
	printf("%d",near);
	return 0;
} 
*/
