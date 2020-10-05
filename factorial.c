#include<stdio.h>

int main(){
int i=0,n,factorial=1;
printf("Enter the number whose factorial you want\n");
scanf("%d", &n);

for(i=1;i<=n;i++){
	factorial *=i;
}
printf("The value of factorial %d is %d\n", n, factorial);
return 0;
	}
	