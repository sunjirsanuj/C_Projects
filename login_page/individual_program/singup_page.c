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
            printf("*");
        }
    }
}

void divider()
{
    int i;
    for(i = 0; i < 60; i++){
        printf("-");
    }
}

void singup()
{
    account u;
    char pass2[20];
    system("cls");

    printf("\n\t\t\tCREATE NEW ACCOUNT\n");
    divider();
    getchar();
    printf("\n\nEnter your first name: ");
    fgets(u.first, sizeof(u.first), stdin);
    u.first[strcspn(u.first, "\n")] = '\0';
    printf("Enter your last name: ");
    fgets(u.last, sizeof(u.last), stdin);
    u.last[strcspn(u.last, "\n")] = '\0';
    printf("Enter your user name: ");
    scanf("%s",u.user);
    printf("Enter your phone number: ");
    scanf("%s",u.phone);
    getchar();
    printf("Enter your gender: ");
    scanf("%c",&u.gender);
    printf("Enter your DOB: ");
    scanf("%s",u.DOB);
    printf("Enter your password: ");
    takepassword(u.pass1);

cfr_pass:
    printf("\nConfirm your password: ");
    scanf("%s",pass2);

    if(strcmp(u.pass1, pass2)){
        printf("\n******Incorrect password******\nTry again.....\n");
        goto cfr_pass;
    }
    else{
        printf("\nACCOUNT CREATED SUCCESFULLY\n");
        FILE *fp = fopen("account.txt", "w");
        fwrite(&u, sizeof(account), 1, fp);
        fclose(fp);
        getch();
    }

}
void login(){}
void forget(){}
void change_pass(){}
void del_account(){}