/*����-1924�� 2007�� ����
     1,3,5,7,8,10,12��    ==31��
     4��,6��,9��,11��    == 30��
2017 1��1��==������  2��==28�� 
x(1<=x<=12), y(1<=y<=31)*/
#include<stdio.h>
int main(){
	int i,j,n=0,a,b;
	scanf("%d%d",&i,&j);
	switch(i){
		case 1:
			for(b=1;b<=j;b++,n++);break;
		case 2:n=31;
			for(b=1;b<=j;b++,n++);break;
		case 3:n=59;
			for(b=1;b<=j;b++,n++);break;
		case 4:n=90;
			for(b=1;b<=j;b++,n++);break;
		case 5:n=120;
			for(b=1;b<=j;b++,n++);break;
		case 6:n=151;
			for(b=1;b<=j;b++,n++);break;
		case 7:n=181;
			for(b=1;b<=j;b++,n++);break;
		case 8:n=212;
			for(b=1;b<=j;b++,n++);break;
		case 9:n=243;
			for(b=1;b<=j;b++,n++);break;
		case 10:n=273; //?
			for(b=1;b<=j;b++,n++);break;
		case 11:n=304;
			for(b=1;b<=j;b++,n++);break;
		default:n=334;
			for(b=1;b<=j;b++,n++);break;
	}
	printf("%d",n);
	switch(n%7)
	{
		case 0:
			printf("SUN");break;
		case 1:
			printf("MON");break;
		case 2:
			printf("TUE");break;
		case 3:
			printf("WED");break;
		case 4:
			printf("THU");break;
		case 5:
			printf("FRI");break;
		case 6:
			printf("SAT");break;			
	}
	return 0;
}  
