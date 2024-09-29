#include<stdio.h>

int sumNaturalnumber(int num1, int num2)
{
    int i, sum =0;
    for(i=num1 ; i<=num2 ; i++)
    {
        sum += i;
    }
    return sum;
}
int main()
{
    int lowLimit, upLimit, sum;

    printf("Enter lower value: ");
    scanf("%d",&lowLimit);
    printf("Enter upper value: ");
    scanf("%d",&upLimit);

    sum = sumNaturalnumber(lowLimit, upLimit);
    printf("Summation of natural numbers between %d and %d is %d.",lowLimit,upLimit,sum);
}