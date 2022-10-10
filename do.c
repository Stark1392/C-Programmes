#include<stdio.h>
int main()
{
	int i=0;
	int n;
	printf("Enter the value of n\n");
	scanf("%d", &n);

    // This is how you use do-whlie loop
    // Here the loop is ran first and then the loop condition is checked
	do{
		 printf("The value of i is %d\n", i+1);
		 i++;
		}while(i<n);
	
	// Same thing can be implement in while loop as well
	// Only difference is that first the loop condition will be checked
	
	while(i < n)
	{
	    printf("The value of i is %d\n", i + 1);
	    i++;
	}
	
	return 0;
}
