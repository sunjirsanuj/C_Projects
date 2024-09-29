#include<stdio.h>

int main()
{
    int lowLimit, upLimit;
    int i;
    int sum = 0;

    printf("Enter lower value: ");
    scanf("%d",&lowLimit);
    printf("Enter upper value: ");
    scanf("%d",&upLimit);

    for(i=lowLimit ; i<=upLimit ; i++)
    {
        sum += i;
    }
    printf("Summation of natural numbers between %d and %d is %d",lowLimit,upLimit,sum);
}