#include<stdio.h>
#include<math.h>

int main()
{
    int originalNum, num, lastDigit, digits;
    int sum = 0;

    printf("Enter any number to check armstrong: ");
    scanf("%d",&num);
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
        printf("%d is armstrong number.",originalNum);
    }
    else{
        printf("%d is not armstrong number.",originalNum);
    }
    return 0;

}