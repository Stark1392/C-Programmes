#include<stdio.h>

int main(){
int i=1,n,factorial=1;
printf("Enter the number whose factorial you want:\n");
scanf("%d", &n);
while(i<=n){
	factorial *= i;
	i++;
}
printf("The factorial of %d is %d\n", n, factorial);
return 0;
	}
	