#include<stdio.h>
#include<math.h>

int isStrong(int num)
{
    int digits, lastDigit, i, j;
    int sum = 0;
    int originalNum = num;

    digits = (int)log10(num)+1;
    for(i=0 ; i<digits ; i++)
    {
        int mul = 1;
        lastDigit = num%10;
        for(j=1 ; j<=lastDigit ; j++)
        {
            mul = mul*j;
        }
        sum += mul;
        num = num/10;
    }
    if(originalNum == sum){
        return 1;
    }
    return 0;
}

int main()
{
    int num;

    printf("Enter any Number: ");
    scanf("%d",&num);

    if(isStrong(num)){
        printf("%d is strong number.",num);
    }
    else{
        printf("%d is not strong number.",num);
    }
    return 0;
}