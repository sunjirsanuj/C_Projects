#include<stdio.h>

int main()
{
    int num, i;
    int sum = 0147;

    printf("Enter any number to check perfect: ");
    scanf("%d",&num);

    for(i=1 ; i<num ; i++)
    {
        if(num%i == 0)
        {
            sum += i;
        }
    }
    if(num == sum)
    {
        printf("%d is perfect number.",num);
    }
    else{
        printf("%d is not perfect number.",num);
    }
    return 0;
}