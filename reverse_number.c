#include<stdio.h>

int main()
{
    int num, remainder;
    int returnNum = 0;

    printf("Enter a number: ");
    scanf("%d",&num);

    while(num != 0){
        remainder = num%10;
        returnNum = returnNum*10+remainder;
        num /= 10;
    }

    printf("Return number: %d",returnNum);
    return 0;
}