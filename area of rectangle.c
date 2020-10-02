#include<stdio.h>
int main()
{
	int length, area=0, breadth;
	printf("What is the length of rectangle \n");
	scanf("%d", &length);
	printf("What is the breadth of rectangle \n");
	
	scanf("%d", &breadth);
	area=length*breadth;
	printf("The area of your rectangle is %d \n", area);
	return 0;
}
