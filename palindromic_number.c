#include<stdio.h>

int main()
{
    int num, remainder, originalNum;
    int returnNum = 0;

    printf("Enter any number: ");
    scanf("%d",&num);

    originalNum = num;

    while(num != 0)
    {
        remainder = num%10;
        returnNum = returnNum*10+remainder;
        num /= 10;
    }
    if(returnNum == originalNum){
        printf("%d is a palindromic number.",originalNum);
    }
    else{
        printf("%d is not a palindromic number.",originalNum);
    }

    return 0;
}