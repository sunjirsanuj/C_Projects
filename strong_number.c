#include<stdio.h>
#include<math.h>

int main()
{
    int num,originalNum,i,j,lastDigit,digits;
    int sum = 0;

    printf("Enter any number to check strong: ");
    scanf("%d",&num);
    originalNum = num;

    digits = (int)log10(num)+1;
    for(i=0 ; i<digits ; i++)
    {
        int mul = 1;
        lastDigit = num%10;
        for(j=1 ; j<=lastDigit ; j++)
        {
            mul = mul*j;
        }
        sum = sum+mul;
        num = num/10;
    }
    if(originalNum == sum){
        printf("%d is a strong number.",originalNum);
    }
    else{
        printf("%d is not a strong number.",originalNum);
    }
    return 0;
    
}