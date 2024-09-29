#include<stdio.h>

int main()
{
    int num, i, isPrime;
    isPrime = 1;

    printf("Enter any number to check prime: ");
    scanf("%d",&num);

    for(i=2 ; i<num ; i++)
    {
        if(num%i == 0)
        {
            isPrime = 0;
            break;
        }
    }
    
    if(isPrime == 1 && num>1)
    {
        printf("%d is prime number.",num);
    }
    else
    {
        printf("%d is not prime number.",num);
    }
    return 0;
}