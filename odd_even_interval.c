#include<stdio.h>

int main()
{
    int lowLimit, upLimit;
    int i;

    printf("Enter lower value: ");
    scanf("%d",&lowLimit);
    printf("Enter upper value: ");
    scanf("%d",&upLimit);

    printf("Even numbers are ");
    for(i=lowLimit ; i<=upLimit ; i++){
        if(i%2 == 0){
            printf("%d, ",i);
        }
    }
    printf("\nOdd numbers are ");
    for(i=lowLimit ; i<=upLimit ; i++){
        if(i%2 != 0){
            printf("%d, ",i);
        }
    }
    return 0;
}