#include <stdio.h>
#include <math.h>

int main()
{
    double bs,vr,hy;
    int choice;

    printf("Choice which side value you want.\n");
    printf("1. Hypotenuse.\n");
    printf("2. Vertical.\n");
    printf("3. Base.\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    if(choice<1 || choice>3){
        printf("Sorry! Please enter your choice again.\n");
    }
    else{
        if(choice==1){
            printf("Enter the value of Vertical: ");
            scanf("%lf",&vr);
            printf("Enter the value of Base: ");
            scanf("%lf",&bs);

            if(vr==0 || bs==0){
                printf("The triangle does not exist.\n");
            }
            else{
                hy = pow((pow(vr,2)+pow(bs,2)),.5);
                printf("Hypotenuse: %.2lf",hy);
            }
        }
        else if(choice==2){
            printf("Enter the value of Hypotenuse: ");
            scanf("%lf",&hy);
            printf("Enter the value of Base: ");
            scanf("%lf",&bs);

            if(hy<bs || hy==0 || bs==0){
                printf("The triangle does not exist.\n");
            }
            else{
                vr = pow((pow(hy,2)-pow(bs,2)),.5);
                printf("Vertical: %.2lf",vr);
            }
        }
        else{
            printf("Enter the value of hypotenuse: ");
            scanf("%lf",&hy);
            printf("Enter the value of Vertical: ");
            scanf("%lf",&vr);

            if(hy<vr || hy==0 || vr ==0){
            printf("The triangle does not exist.\n");
            }
            else{
                bs = pow((pow(hy,2)-pow(vr,2)),.5);
                printf("Base: %.2lf",bs);
            }
        }
    }
    return 0;
}
