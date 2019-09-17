#include<stdio.h>
int main()
{
	int i,j;
	scanf("%d",&i);
	scanf("%d",&j);
	if(i==j)
		printf("==\n");
	else if(i<j)
		printf("<\n");
	else
		printf(">\n");
	return 0;
}
