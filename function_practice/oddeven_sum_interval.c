#include<stdio.h>

int evenSum(int lowLimit, int upLimit)
{
    int i, sum = 0;
    for(i=lowLimit ; i<=upLimit ; i++)
    {
        if(i%2 == 0){
            sum += i;
        }
    }
    return sum;
}

int oddSum(int lowLimit, int upLimit)
{
    int i, sum = 0;
    for(i=lowLimit ; i<=upLimit ; i++)
    {
        if(i%2 != 0){
            sum += i;
        }
    }
    return sum;
}

int main()
{
    int lowLimit, upLimit;

    printf("Enter lower value: ");
    scanf("%d",&lowLimit);
    printf("Enter upper value: ");
    scanf("%d",&upLimit);

    printf("Summation of all even numbers between %d and %d is %d",lowLimit,upLimit,evenSum(lowLimit, upLimit));
    printf("\nSummation of all odd numbers between %d and %d is %d",lowLimit,upLimit,oddSum(lowLimit, upLimit));

    return 0;
}