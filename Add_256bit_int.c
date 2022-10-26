#include <stdio.h>
#include <stdlib.h>

typedef unsigned char arr[32];

int int_to_bin(int x);
void printbin(arr x);

//Representation in little endian
void printbin(arr x) {
    for (int i=31; i>=0; i--) {
        printf("%d", int_to_bin(x[i]));
    }
}

int int_to_bin(int x) {
    if (x == 0)
        return 0;
    if (x == 1)
        return 1;
    return (x % 2) + 10 * int_to_bin(x / 2);
}

void add(arr a1, arr a2, arr a3){
    int sum;
    int car = 0;
    for (int i=0; i<=31; i++) {
        sum = a1[i] + a2[i] + car;
        a3[i] = sum % 256;
        car = sum / 256;
    }
}

int main(){
    arr a1 = { 123,132,109,123,132,109,123,132,109,123,132,109,123,132,109,123,132,109,123,132,109,123,132,109,123,132,109,123,132,109,123,132};
    arr a2 = { 129,142,107,129,142,107,129,142,107,129,142,107,129,142,107,129,142,107,129,142,107,129,142,107,129,142,107,129,142,107,129,142};
    arr a3 = {0};
    add(a1, a2, a3);
    printbin(a1);
    printf("\n+ ");
    printbin(a2);
    printf("\n= ");
    printbin(a3);
    printf("\n");

    return 0;
}
