#include<stdio.h>
#include "func.h"

int main()
{
	int a, b;
	printf("Enter two numbers : ");
	scanf("%d %d",&a, &b);
	add(a, b);
	sub(a, b);
	mul(a, b);
	div(a, b);

	return 0;
}	
