#include<stdio.h>

int calsum_givdigit;

int main()
{
    int num;
    printf("Enter any number: ");
    scanf("%d",&num);

    printf("Sum of the digits of given number: %d",calsum_givdigit(num));

    return 0;
}

int calsum_givdigit(int num)
{
    int lastDigit;
    int sum = 0;

    while(num > 0){
        lastDigit = num % 10;
        sum += lastDigit;
        num /= 10;
    }
    return sum;
}