#include<stdio.h>

int factorial();

int main()
{
    int num;

    printf("Enter an integer number: ");
    scanf("%d",&num);

    if(factorial(num)){
        printf("Factorial of %d: %llu",num, factorial(num));
    }
    else{
        printf("Error! Factorial of a negative number does not exist.");
    }
}

int factorial(int num)
{
    int i;
    unsigned long long fact = 1;

    if(num < 0){
        return 0;
    }
    else{
        for(i = 1; i <= num; i++){
            fact *= i;
        }
        return fact;
    }
}