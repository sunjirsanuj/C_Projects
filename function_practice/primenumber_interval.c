#include<stdio.h>

int isPrime(int num)
{
    int i, isPrime;
    isPrime = 1;

    for(i=2 ; i<num ; i++)
    {
        if(num%i==0){
            isPrime = 0;
            break;
        }
    }
    if(isPrime==1){
        return 1;
    }
    return 0;
}

int main()
{
    int lowLimit, upLimit, j;

    printf("Enter low value: ");
    scanf("%d",&lowLimit);
    printf("Enter upper value: ");
    scanf("%d",&upLimit);

    for(j=lowLimit ; j<upLimit ; j++)
    {   
        if(j==1 || j==0){
            continue;
        }
        if(isPrime(j)){
            printf("%d ",j);
        }
    }
}