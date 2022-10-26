#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fr, *fw;
    char frnm[50], fwnm[50], a[1];
    printf("Enter the source file name:");
    scanf("%s", frnm);
    printf("\nEnter the destination file name:");
    scanf("%s", fwnm);
    fr = fopen(frnm, "r");
    fw = fopen(fwnm, "w");
    if(fr==NULL){
        printf("\nUnable to open the source file");
        return 0;
    }
    else if(fw==NULL){
        printf("\nUnable to open the destination file");
        return 0;
    }
    // printf("hello");
    fread(a, sizeof(a), 1, fr);
    while (!feof(fr)){
        //fread(a, sizeof(a), 1, fr);
        fwrite(a , 1 , sizeof(a) , fw);
        fread(a, sizeof(a), 1, fr);
        //printf("\n%s",a);
    }
    printf("\nCopied the content from source file to the destination file");
    fclose(fr);
    fclose(fw);
    return 0;

}
