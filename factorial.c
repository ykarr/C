//�Ʒ��� ���α׷��� ���������� �����ϵ��� �ٲٽÿ� 
//https://intunknown.tistory.com/356
//����1 
# include <stdio.h>
void main(){ 
	int i, num, j;  
	printf ("Enter the number: "); 
	scanf ("%d", &num );
	for (i=1; i<num; i++) 
		j=j*i;    
	printf("The factorial of %d is %d\n", num, j);
}

//��� 1 
//#include<stdio.h>
//void main(){
//	int i, num, j;
//	printf("Enter the number: " );
//	scanf("%d",&num);
//	for(i=1;i<=num;i++)
//		j=j*i;
//	printf("The factorial of %d is %d\n",num,j);
//}

//��� 2 
//# include <stdio.h>
//void main(){ 
//	int i, num, j;  
//	printf ("Enter the number: "); 
//	scanf ("%d", &num );
//	num++;
//	for (i=1; i<num; i++) 
//		j=j*i;    
//	printf("The factorial of %d is %d\n", num, j);
//}
