#include<stdio.h>

int main()
{
    int num, lastDigit;
    int sum = 0;;

    printf("Enter any number: ");
    scanf("%d",&num);

    while(num>0){
        lastDigit = num % 10;
        sum += lastDigit;
        num /= 10;
    }

    printf("Sum of the gidits of given number: %d",sum);

    return 0;
}