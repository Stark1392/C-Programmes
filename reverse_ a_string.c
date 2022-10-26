#include <stdio.h>
//#include <stdlib.h>

int main(){
    char s[100];
    int l=0;
    printf("Enter the string you want to reverse:");
    scanf("%[^\n]s",s);
    while(s[l]!='\0')
        l++;
    //printf("\n%d", l);
    char srev[l];
    int j=l-1, i;
    for(i=0; j>=0; i++){
        srev[i]=s[j];
        j--;
    }
    srev[i]='\0';

    printf("\nThe reversed string is: %s", srev);
}
