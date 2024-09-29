#include <stdio.h>

int main()
{
    double num1, num2, rs;
    int choice;

    printf("Choice which operation(+,-,*,/) you want.\n\n");
    printf("1. +\n");
    printf("2. -\n");
    printf("3. *\n");
    printf("4. /\n");
    printf("\nChoice your operation: ");
    scanf("%d",&choice);

    switch(choice){
        case 1:
        printf("\nEnter Number 1: ");
        scanf("%lf",&num1);
        printf("Enter Number 2: ");
        scanf("%lf",&num2);

        rs = num1 + num2;
        printf("\nResult: %.2lf\n",rs);
        break;

        case 2:
        printf("\nEnter Number 1: ");
        scanf("%lf",&num1);
        printf("Enter Number 2: ");
        scanf("%lf",&num2);

        rs = num1 - num2;
        printf("\nResult: %.2lf\n",rs);
        break;

        case 3:
        printf("\nEnter Number 1: ");
        scanf("%lf",&num1);
        printf("Enter Number 2: ");
        scanf("%lf",&num2);

        rs = num1 * num2;
        printf("\nResult: %.2lf\n",rs);
        break;

        case 4:
        printf("\nEnter Number 1: ");
        scanf("%lf",&num1);
        printf("Enter Number 2: ");
        scanf("%lf",&num2);

        if(num2==0){
            printf("\nResult is infinity!\n");
        }
        else{
            rs = num1 / num2;
        printf("\nResult: %.2lf\n",rs);
        }
        break;
    }
    return 0;
}
