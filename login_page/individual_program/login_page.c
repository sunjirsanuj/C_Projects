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
void login()
{
    system("cls");
    char log_user[20], log_pass[20];
    account u;

    printf("\n\t\t\tLOGIN\n");
    divider();

    FILE *fp = fopen("account.txt", "r");
    fread(&u, sizeof(account), 1, fp);
enter_user:
    printf("\n\nPlease enter your username: ");
    scanf("%s",log_user);
    
    if(strcmp(log_user, u.user)){
        printf("\n*******INCORRECT USERNAME*******\n");
        printf("Please enter your correct username\n");
        goto enter_user;
    }
    else{
enter_pass:
        printf("Please enter your password: ");
        takepassword(log_pass);
        if(strcmp(log_pass, u.pass1)){
            printf("\n\n*******INCORRECT PASSWORD*******\n");
            printf("Please enter your correct password\n\n");
            goto enter_pass;
        }
        else{
            system("cls");
            printf("\n\t************Welcome %s************\n", u.first);
            divider();
            printf("\n\n\t\t\tYour Details\n");
            divider();
            printf("\n\nUsername: %s \n", u.user);
            printf("First name: %s \n", u.first);
            printf("Last name: %s \n", u.last);
            printf("Phone number: %s \n", u.phone);
            printf("Gender: %c \n", u.gender);
            printf("Password: %s \n", u.pass1);
        }
        getch();
    }
}
void forget(){}
void change_pass(){}
void del_account(){}