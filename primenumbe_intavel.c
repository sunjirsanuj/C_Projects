#include<stdio.h>

int main()
{
    int lowLimit, upLimit, i, j, isPrime;

    printf("Enter lower value: ");
    scanf("%d",&lowLimit);
    printf("Enter upper value: ");
    scanf("%d",&upLimit);
    printf("Prime numbers between %d and %d are: ",lowLimit,upLimit);

    for(i=lowLimit ; i<=upLimit ; i++)
    {
        if(i==1 || i==0){
            continue;
        }
        isPrime = 1;
        for(j=2 ; j<i ; j++)
        {
            if(i%j==0){
                isPrime = 0;
                break;
            }
        }
        if(isPrime == 1){
            printf("%d ",i);
        }
    }
    return 0;
}