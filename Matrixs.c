#include<stdio.h>

int main()
{
    int a[10][10],b[10][10],c[10][10],d[10][10],row,col,i,j;

    printf("Enter the rows number for both matrices: ");
    scanf("%d",&row);
    printf("Enter the columns for both matrices: ");
    scanf("%d",&col);

    printf("\nEnter elements for matrix A: \n\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("Enter the element at [%d%d]: ",i,j);
            scanf("%d",&a[i][j]);
        }
        printf("\n");
    }
    printf("Enter elements for matrix B: \n\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("Enter the element at [%d%d]: ",i,j);
            scanf("%d",&b[i][j]);
        }
        printf("\n");
    }

    printf("A Matrix: \n\t\t");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf(" %d ",a[i][j]);
        }
        printf("\n\t\t");
    }

    printf("\nB Matrix: \n\t\t");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf(" %d ",b[i][j]);
        }
        printf("\n\t\t");
    }

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }


    printf("\nAddition of A and B: \n\t\t");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf(" %d ",c[i][j]);
        }
        printf("\n\t\t");
    }

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            d[i][j] = a[i][j] - b[i][j];
        }
    }

    printf("\nSubtraction of A and B: \n\t\t");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf(" %d ",d[i][j]);
        }
        printf("\n\t\t");
    }
    return 0;
}
