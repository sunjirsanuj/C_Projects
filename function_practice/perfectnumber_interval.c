#include<stdio.h>

int isPerfect(int num)
{
    int i, sum;
    sum = 0;

    for(i=1 ; i<num ; i++){
        if(num%i == 0){
            sum += i;
        }
    }
    if(sum == num){
        return 1;
    }
    return 0;
}

void printPerfect(int start, int end)
{
    while(start<=end){
        if(isPerfect(start)){
            printf("%d, ",start);
        }
        start++;
    }
}

int main()
{
    int start, end;

    printf("Enter starting value: ");
    scanf("%d",&start);
    printf("Enter ending value: ");
    scanf("%d",&end);

    printf("Perfect numbers between %d and %d are ",start,end);
    printPerfect(start, end);
}