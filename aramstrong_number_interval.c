#include<stdio.h>
#include<math.h>

int main()
{
    int lowLimit, upLimit;
    int lastDigit, digits, originalNum;
    int i;
    int sum = 0;

    printf("Enter lower value: ");
    scanf("%d",&lowLimit);
    printf("Enter upper value: ");
    scanf("%d",&upLimit);

    for(i=lowLimit ; i<=upLimit ; i++)
    {
        digits = (int)log10(i)+1;
        originalNum = i;
        while(i>0)
        {
            lastDigit = i%10;
            sum = sum + round(pow(lastDigit,digits));
            i = i/10;
        }

        if(originalNum == sum){
            printf("%d ",i);
        }
    }
}