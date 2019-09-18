//백준 블랙잭 
#include<stdio.h>
#define MAX 100
int main(){
	int n=0;//카드의 개수 
	int m=0;//카드 합의 한도 
	int near=0;//한도의 근처값 
	int sum=0;//카드값을 더한 값 
	int i,j,k; //for문에 사용할 변수
	 
	int array[MAX];//카드의 숫자를 배열로 저장. 
	scanf("%d%d",&n,&m); //input
	
	for(i=0;i<n;i++){ //배열에 카드의 개수만큼 숫자를 넣는다. 
		scanf("%d",&array[i]);
	}
//	for(i=0;i<n;i++){//들어갔는지 확인 
//		printf("%d-",array[i]);
//	}
	//printf("\n");
	for(i=0;i<n;i++){//3번째 카드중 첫번째 
		for(j=i+1;j<n;j++){//3번째 카드중 두번째 
			for(k=j+1;k<n;k++){//3번째 카드중 세번째 
				sum=array[i]+array[j]+array[k];//3개의 카드를 더한값을 sum에 저장 
				//printf("%d %d %d 값=%d\n",array[i],array[j],array[k],sum);//더한값 확인 
				if(near<sum&&sum<=m){//near값에 넣어놓은 값과 현재 sum의 값을 비교 sum은 한도보다 작음. 
					near=sum;//sum값이 한도보다 작고 현재 near값보다 한도에 가까우므로 교체 
					//printf("near값=%d \n",near);
				}
				//if문을 사용하지 않고 
				//near=near<sum&&sum<=m?sum:near; 
			}
		}	
	}
	printf("%d",near);//출력 
	return 0;
}
/*수정1 
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
/*수정2
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
