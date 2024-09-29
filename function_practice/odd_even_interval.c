#include<stdio.h>

void oddeven(int x, int y)
{
    int i;
    printf("Even numbers are ");
    for(i=x ; i<=y ; i++){
        if(i%2 == 0){
            printf("%d, ",i);
        }
    }
    printf("\nOdd numbers are ");
    for(i=x ; i<=y ; i++){
        if(i%2 != 0){
            printf("%d, ",i);
        }
    }
}

int main()
{
    int lowLimit, upLimit;

    printf("Enter lower value: ");
    scanf("%d",&lowLimit);
    printf("Enter upper value: ");
    scanf("%d",&upLimit);

    oddeven(lowLimit, upLimit);
}