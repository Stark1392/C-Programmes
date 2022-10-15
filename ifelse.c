#include <stdio.h>

int main()
{
    int input = -1;
    int power = 1;
    printf("Enter 0 to exit\n");
    printf("Enter 1 to access calculator\n");
    printf("Enter 2 to insert personal information\n");
    printf("Enter 3 to check if eligible for marriage\n");
    printf("Enter 4 to check if eligible to vote\n");
    scanf("%d", &input);
    
    while(power != 0)
    {
        
        printf("Enter 0 to exit\n");
        printf("Enter 1 to access calculator\n");
        printf("Enter 2 to insert personal information\n");
        printf("Enter 3 to check if eligible for marriage\n");
        printf("Enter 4 to check if eligible to vote\n");
        scanf("%d", &input);
        
        if(input == 0)
        {
            power = 0;
            printf("Phone switched off\n");
            printf("\n");
        }
        else if(input == 1)
        {
            printf("calculator started\n");
            printf("\n");
        }
        else if(input == 2)
        {
            printf("calculator started\n");
            printf("\n");
        }
        else if(input == 3)
        {
            printf("calculator started\n");
            printf("\n");
        }
        else if(input == 4)
        {
            printf("calculator started\n");
            printf("\n");
        }
        else
        {
            printf("Please enter valid instruction\n");
            printf("\n");
        }
    }
    
    return 0;
    
}
