#include<stdio.h>

int main()
{
    int lowLimit, upLimit;
    int i;

    printf("Enter lower value: ");
    scanf("%d",&lowLimit);
    printf("Enter upper value: ");
    scanf("%d",&upLimit);

    for(i=lowLimit ; i<=upLimit ; i++){
        printf("%d, ",i);
    }
    return 0;
}