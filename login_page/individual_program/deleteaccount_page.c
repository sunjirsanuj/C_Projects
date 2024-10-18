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

void singup(){}
void login(){}
void forget(){}
void change_pass(){}
void del_account()
{
    system("cls");
    account u;
    char ch;
    char username[20], password[20];
    FILE *fp = fopen("account.txt", "r");
    fread(&u, sizeof(account), 1, fp);
    printf("\n\t\t\tDELETE ACCOUNT\n");
    divider();

    ch:
    printf("\n\nAre you sure[y/n]: ");
    ch = getche();

    if (ch == 'y' || ch == 'Y'){
    username:
        printf("\n\nEnter your username: ");
        scanf("%s",username);

        if (strcmp(username, u.user)){
            printf("\n\n*******INCORRECT USERNAME*******\nTry again.....\n");
            goto username;
        }
        else{
        pass:
            printf("\nEnter your password: ");
            takepassword(password);

            if (strcmp(password, u.pass1)){
                printf("\n\n*******INCORRECT PASSWORD*******\nTry again.....\n");
                goto pass;
            }
            else{
                printf("\nACCOUNT DELETED SUCCESFULLY !!\n");
                fp = fopen("account.txt", "w");
                fprintf(fp, " ");
                fclose(fp);
                getch();
            }
        }

    }
    else if(ch == 'N' || ch == 'n'){
        printf("\n\nYOUR ACCOUNT DELETION STOPED !!\n");
        getch();
    }
    else{
        printf("\n\nINVALIED CHOICE !!\n");
        goto ch;
    }
    fclose(fp);

}