#include <stdio.h>
//#include <stdlib.h>

int main(){
    int a, b, c, n;
    printf("Enter the first variable:");
    scanf("%d", &a);
    printf("\nEnter the second variable:");
    scanf("%d", &b);
    printf("\nEnter the size of arrays:");
    scanf("%d", &n);
    int a1[n], a2[n], a3[n];
    printf("Enter elements of first array:");
    for(int i = 0; i < n; i++)
    scanf("%d",&a1[i]);
    printf("\nEnter elements of second array:");
    for(int i = 0; i < n; i++)
    scanf("%d",&a2[i]);
    printf("\nSwapping the first and second variable");
    c=a;
    a=b;
    b=c;
    printf("\nFirst variable: %d, Second variable: %d", a, b);
    printf("\nSwapping the elements of first and second array");
    for(int i = 0; i < n; i++){
        a3[i]=a1[i];
        a1[i]=a2[i];
        a2[i]=a3[i];
    }
    printf("\nElements of first array:");
    for(int i = 0; i < n; i++){
        printf("\n%d", a1[i]);
    }
    printf("\nElements of second array:");
    for(int i = 0; i < n; i++){
        printf("\n%d", a2[i]);
    }

    return 0;
}
