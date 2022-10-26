#include <stdio.h>
//#include <stdlib.h>

int bs(unsigned int arr[], unsigned int l, unsigned int h, unsigned int x){
    if(h>=l){
        int m;
        if(l%2==1 && h%2==1)
            m=(l/2) + (h/2) +1;
        else
            m=(l/2) + (h/2);
        if(arr[m]==x)
            return m;
        if(arr[m]>x){
                //printf("\n> wala %d",m);
            return bs(arr, 0, m-1, x);
        }
        else{
            //printf("\n< wala %d %d", arr[m], m);
            return bs(arr, m+1, h, x);
        }
    }
    else
        return -1;
}

int main(){
    unsigned int n, x;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the elements of array:");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    printf("\nEnter the element you want to search for: ");
    scanf("%d", &x);
    int a = bs(arr, 0, n-1, x);
    if(a==-1)
        printf("\nElement not found");
    else
        printf("\nElement found at index %d", a);

}
