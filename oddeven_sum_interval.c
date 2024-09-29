#include<stdio.h>

int main()
{
    int lowLimit, upLimit;
    int i;
    int evenSum = 0, oddSum = 0;

    printf("Enter lower value: ");
    scanf("%d",&lowLimit);
    printf("Enter upper value: ");
    scanf("%d",&upLimit);

    for(i=lowLimit ; i<=upLimit ; i++)
    {
        if(i%2 == 0){
            evenSum += i;
        }
    }
    printf("Summation of even numbers between %d and %d is %d",lowLimit,upLimit,evenSum);

    for(i=lowLimit ; i<=upLimit ; i++)
    {
        if(i%2 != 0){
            oddSum += i;
        }
    }
    printf("\nSummation of odd numbers between %d and %d is %d",lowLimit,upLimit,oddSum);

    return 0;
}