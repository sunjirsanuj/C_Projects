#include<stdio.h>
#include<string.h>

typedef struct {
    char first[20];
    char last[20];
} nametype;

typedef struct {
    int id;
    nametype name;
} studenttype;

int main()
{
    int i, n;
    printf("\nEnter number of students: ");
    scanf("%d",&n);
    printf("\n");

    studenttype student[n];

    for(i = 0; i < n; i++){
        printf("Enter the ID of student %d: ",i+1);
        scanf("%d",&student[i].id);
        getchar();

        printf("Enter first name of student %d: ",i+1);
        fgets(student[i].name.first, sizeof(student[i].name.first), stdin);
        student[i].name.first[strcspn(student[i].name.first, "\n")] = '\0';

        printf("Enter last name of student %d: ",i+1);
        fgets(student[i].name.last, sizeof(student[i].name.last), stdin);
        student[i].name.last[strcspn(student[i].name.last, "\n")] = '\0';

        printf("\n");
    }

    printf("Output: \n\n");

    for(i = 0; i < n; i++){
        printf("ID: %d\n",student[i].id);
        printf("Name: %s %s\n",student[i].name.first, student[i].name.last);

        printf("\n");
    }

    return 0;
}