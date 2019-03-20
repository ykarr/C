//아래의 프로그램이 정상적으로 동작하도록 바꾸시오 
//문제1 
# include <stdio.h>
void main(){ 
	int i, num, j;  
	printf ("Enter the number: "); 
	scanf ("%d", &num );
	for (i=1; i<num; i++) 
		j=j*i;    
	printf("The factorial of %d is %d\n", num, j);
}

//방법 1 
//#include<stdio.h>
//void main(){
//	int i, num, j;
//	printf("Enter the number: " );
//	scanf("%d",&num);
//	for(i=1;i<=num;i++)
//		j=j*i;
//	printf("The factorial of %d is %d\n",num,j);
//}

//방법 2 
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
