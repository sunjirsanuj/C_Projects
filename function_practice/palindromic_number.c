#include<stdio.h>

int isPaldro(int num)
{
    int originalNum, remainder;
    int returnNum = 0;
    originalNum = num;

    while(num != 0){
        remainder = num%10;
        returnNum = returnNum*10+remainder;
        num /= 10;
    }
    if(originalNum == returnNum){
        return 1;
    }
    return 0;
}

int main()
{
    int num;

    printf("Enter any number: ");
    scanf("%d",&num);

    if(isPaldro(num)){
        printf("%d is a palindromic number.",num);
    }
    else{
        printf("%d is not a palindromic number.",num);
    }
    return 0;
}