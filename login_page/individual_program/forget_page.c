#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

int menu();
void singup();
void takepassword();
void login();
void forget();
void change_pass();
void del_account();
void divider();

typedef struct {
    char first[20];
    char last[20];
    char user[20];
    char phone[15];
    char gender;
    char DOB[20];
    char pass1[20];
} account;


int main()
{
    while(1){
        switch (menu())
        {
        case 1:
        singup();
        break;
        case 2:
        login();
        break;
        case 3:
        forget();
        break;
        case 4:
        change_pass();
        break;
        case 5:
        del_account();
        break;
        case 6:
        exit(0);
        
        default:
        printf("\n\n******Invalied choice!******\nTry again....\n\n");
        }
    }
}

int menu()
{
    int c;
    printf("\n**********************MAIN MENU**********************\n\n");
    printf("\t1. SIGNUP\n");
    printf("\t2. LOGIN\n");
    printf("\t3. FORGET PASSWORD OR USERNAME\n");   
    printf("\t4. CHANGE PASSWORD\n");
    printf("\t5. DELETE ACCOUNT\n");
    printf("\t6. EXIT\n");

    printf("\nPlease enter your choice: ");
    scanf("%d",&c);
    return c;
}

void takepassword(char pass[20])
{
    char ch;
    int i = 0;

    while(1){
        ch = getch();
        if(ch == 13){
            pass[i] = '\0';
            break;
        }
        else if(ch == 8){
            if(i > 0){
                i--;
                printf("\b \b");
            }
        }
        else if(ch == 9 || ch == 32){
            continue;
        }
        else{
            pass[i++] = ch;
        }
        printf("*");
    }
}

void divider()
{
    int i;
    for(i = 0; i < 60; i++){
        printf("-");
    }
}

void singup(){}
void login(){}
void forget()
{
start:
    system("cls");
    account u;
    int choice;
    char username[20], password[20], phone[20];

    FILE *fp = fopen("account.txt", "r");
    fread(&u, sizeof(account), 1, fp);

    printf("\n\tFORGAT PASSWORD OR USERNAME\n");
    divider();
    printf("\n\n1. Search by Username\n");
    printf("2. Search by Password\n");
    printf("3. Search by Phone number\n");
    printf("4. MAIN MENU\n");

    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        system("cls");
        printf("\nEnter your Username: ");
        scanf("%s",username);

        if(strcmp(username, u.user)){
            printf("\nUSERNAME NOT FOUND !!\n");
            getch();
            goto start;
        }
        else{
            printf("\nACCOUNT FOUND !!\n");
            printf("\n\t\t\tYour Details\n");
            divider();
            printf("\n\nUsername: %s \n", u.user);
            printf("First name: %s \n", u.first);
            printf("Last name: %s \n", u.last);
            printf("Phone number: %s \n", u.phone);
            printf("Password: %s \n", u.pass1);
            getch();
        }
        break;
    case 2:
        system("cls");
        printf("\nEnter your Password: ");
        scanf("%s",password);

        if(strcmp(password, u.pass1)){
            printf("\nACCOUNT NOT FOUND !!\n");
            getch();
            goto start;
        }
        else{
            printf("\nACCOUNT FOUND !!\n");
            printf("\n\t\t\tYour Details\n");
            divider();
            printf("\n\nUsername: %s \n", u.user);
            printf("First name: %s \n", u.first);
            printf("Last name: %s \n", u.last);
            printf("Phone number: %s \n", u.phone);
            printf("Password: %s \n", u.pass1);
            getch();
        }
        break;
    case 3:
        system("cls");
        printf("\nEnter your Phone number: ");
        scanf("%s",phone);

        if(strcmp(phone, u.phone)){
            printf("\nACCOUNT NOT FOUND !!\n");
            getch();
            goto start;
        }
        else{
            printf("\nACCOUNT FOUND !!\n");
            printf("\n\t\t\tYour Details\n");
            divider();
            printf("\n\nUsername: %s \n", u.user);
            printf("First name: %s \n", u.first);
            printf("Last name: %s \n", u.last);
            printf("Phone number: %s \n", u.phone);
            printf("Password: %s \n", u.pass1);
            getch();
        }
        break;
    case 4:
        return;
    default:
        printf("\nInvalied Choice\n");
        break;
    }
    fclose(fp);

}
void change_pass(){}
void del_account(){}