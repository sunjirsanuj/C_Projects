#include<stdio.h>
#include<math.h>

int isPrime(int num)
{
    int i;

    for(i=2 ; i<num ; i++)
    {
        if(num%i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int isArmstrong(int num)
{
    int lastDigit, digits, originalNum;
    int sum = 0;
    originalNum = num;

    digits = (int)log10(num)+1;

    while(num>0)
    {
        lastDigit = num%10;
        sum = sum + round(pow(lastDigit,digits));
        num = num/10;
    }

    if(originalNum == sum)
    {
        return 1;
    }
    return 0;
}

int isPrefect(int num)
{
    int i;
    int sum = 0;

    for(i=1 ; i<num ; i++)
    {
        if(num%i == 0)
        {
            sum += i;
        }
    }
    if(num == sum)
    {
        return 1;
    }
    return 0;
}


int main()
{
    int num;

    printf("Enter any number to check: ");
    scanf("%d",&num);

    if(isPrime(num)){
        printf("%d is Prime.\n",num);
    }
    else{
        printf("%d is not Prime.\n",num);
    }
    if(isArmstrong(num)){
        printf("%d is armstrong.\n",num);
    }
    else{
        printf("%d is not armstrong.\n",num);
    }
    if(isPrefect(num)){
        printf("%d is perfect.\n",num);
    }
    else{
        printf("%d is not perfect.\n",num);
    }
    return 0;
}

