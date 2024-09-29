#include<stdio.h>

int narutralNumber(int i, int j)
{   
    int a;
    for(a=i ; a<=j ; a++){
        printf("%d, ",a);
    }
}

int main()
{
    int lowLimit, upLimit;

    printf("Enter lower value: ");
    scanf("%d",&lowLimit);
    printf("Enter upper value: ");
    scanf("%d",&upLimit);
    printf("Netural numbers between %d and %d are ",lowLimit,upLimit);
    narutralNumber(lowLimit,upLimit);
    return 0;
}