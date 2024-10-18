#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>

int menu();
void signup();
void login();
void forget();
void change_pass();
void del_account();
void takepassword();
void divider();

typedef struct {
    char first[20];
    char last[20];
    char user[20];
    char phone[20];
    char gender;
    char DOB[20];
    char pass1[20];
} account;

int main()
{
    while (1)
    {
        switch (menu())
        {
        case 1:
            signup();
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
            printf("\nINVALIED CHOICE !!\nTry again.....\n");
            break;
        }
    }

    return 0;
}

int menu()
{
    int c;
    printf("\n**************MAIN MENU**************\n");
    printf("\n1. SIGNUP\n");
    printf("2. LOGIN\n");
    printf("3. FORGET PASSWORD OR USERNAME\n");
    printf("4. CHANGE PASSWORD\n");
    printf("5. DELETE ACCOUNT\n");
    printf("6. EXIT\n");
    printf("\nEnter your choice: ");
    scanf("%d",&c);
    return c;
}

void divider()
{
    int i;

    for (i = 0; i < 60; i++){
        printf("-");
    }
}

void takepassword(char pass[20])
{
    char ch;
    int i = 0;

    while (1){
        ch = getch();

        if (ch == 13){
            pass[i] = '\0';
            break;
        }
        else if (ch == 8){
            if (i > 0){
                i--;
                printf("\b \b");
            }
        }
        else if (ch == 9 || ch == 32){
            continue;
        }
        else{
            pass[i++] = ch;
            printf("*");
        }
    }
}

void signup()
{
    system("cls");
    char pass2[20];
    account u;
    printf("\n\t\tCREATE NEW ACCOUNT\n");
    divider();
    getchar();

    printf("\n\nEnter your first name: ");
    fgets(u.first, sizeof(u.first), stdin);
    u.first[strcspn(u.first, "\n")] = '\0';

    printf("Enter your last name: ");
    fgets(u.last, sizeof(u.last), stdin);
    u.last[strcspn(u.last, "\n")] = '\0';

    printf("Enter your username: ");
    scanf("%s",u.user);

    printf("Enter your phone number: ");
    scanf("%s",u.phone);

    printf("Enter your gender: ");
    scanf(" %c",&u.gender);

    printf("Enter your DOB: ");
    scanf("%s",u.DOB);

    printf("Enter your password: ");
    takepassword(u.pass1);

cfr_pass:
    printf("\nConfirm your pasaword: ");
    scanf("%s",pass2);

    if(strcmp(pass2, u.pass1)){
        printf("\nINCORRECT PASSWORD\nTry again....");
        goto cfr_pass;
    }
    else{
        printf("\nAccount created succesfully !!\n");

        FILE *fp = fopen("account.txt", "w");
        fwrite(&u, sizeof(account), 1, fp);
        fclose(fp);
        getch();
    }
}
void login()
{
    system("cls");
    account u;
    char log_user[20], log_pass[20];
    FILE *fp = fopen("account.txt", "r");
    fread(&u, sizeof(account), 1, fp);
    printf("\nLOGIN\n");
    divider();
    
log_user:
    printf("\n\nEnter your username: ");
    scanf("%s",log_user);

    if (strcmp(log_user, u.user)){
        printf("\nINCORRECT USERNAME\nTry again....");
        goto log_user;
    }
    else{
    log_pass:
        printf("\n\nEnter your password: ");
        takepassword(log_pass);

        if (strcmp(log_pass, u.pass1)){
            printf("\n\nINCORRECT PASSWORD\nTry again....");
            goto log_pass;
        }
        else{
            system("cls");
            printf("\n\nLOGIN SUCCESFULLY !!\n");
            divider();
            printf("\n\nYour Details\n");
            divider();
            printf("\n\nFirst name: %s\n",u.first);
            printf("Username: %s\n",u.user);
            printf("Phone number: %s\n",u.phone);
            printf("Gender: %c\n",u.gender);
            printf("DOB: %s\n",u.DOB);
            printf("Password: %s\n",u.pass1);
            getch();
        }
    }
}
void forget()
{
    system("cls");
    account u;
    FILE *fp = fopen("account.txt", "r");
    fread(&u, sizeof(account), 1, fp);
    int choice;
    char user[20], pass[20], phone[20];

    printf("\nFORGET PASSWORD OR USERNAME\n");
    divider();
    printf("\n\n1. Search by username\n");
    printf("2. Search by password\n");
    printf("3. Search by phone number\n");
    printf("4. MAIN MENU\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
    user:
        printf("\nEnter your username: ");
        scanf("%s",user);

        if (strcmp(user, u.user)){
            printf("\n\nUSERNAME DOES NOT FOUND\nTry again....");
            goto user;
        }
        else{
            printf("\n\nACCOUNT FOUND\n");
            printf("\nYour Details\n");
            divider();
            printf("\n\nFirst name: %s\n",u.first);
            printf("Username: %s\n",u.user);
            printf("Phone number: %s\n",u.phone);
            printf("Gender: %c\n",u.gender);
            printf("DOB: %s\n",u.DOB);
            printf("Password: %s\n",u.pass1);
            getch();
        }
        break;
    case 2:
    pass:
        printf("\nEnter your password: ");
        takepassword(pass);

        if (strcmp(pass, u.pass1)){
            printf("\n\nACCOUNT DOES NOT FOUND\nTry again....");
            goto pass;
        }
        else{
            printf("\n\nACCOUNT FOUND\n");
            printf("\nYour Details\n");
            divider();
            printf("\n\nFirst name: %s\n",u.first);
            printf("Username: %s\n",u.user);
            printf("Phone number: %s\n",u.phone);
            printf("Gender: %c\n",u.gender);
            printf("DOB: %s\n",u.DOB);
            printf("Password: %s\n",u.pass1);
            getch();
        }
        break;
    case 3:
    phone:
        printf("\nEnter your phone number: ");
        scanf("%s",phone);

        if (strcmp(phone, u.phone)){
            printf("\n\nACCOUNT DOES NOT FOUND\nTry again....");
            goto phone;
        }
        else{
            printf("\n\nACCOUNT FOUND\n");
            printf("\nyour Details\n");
            divider();
            printf("\n\nFirst name: %s\n",u.first);
            printf("Username: %s\n",u.user);
            printf("Phone number: %s\n",u.phone);
            printf("Gender: %c\n",u.gender);
            printf("DOB: %s\n",u.DOB);
            printf("Password: %s\n",u.pass1);
            getch();
        }
        break;
    case 4:
        return;
    default:
        printf("\nINVALIED CHOICE !!\nTry again.....\n");
        break;
    }
}
void change_pass()
{
    system("cls");
    account u;
    int num1, num2;
    char pass2[20], pass3[20];
    FILE *fp = fopen("account.txt", "r");
    fread(&u, sizeof(account), 1, fp);
    srand(time(0));

    printf("\nCHANGE PASSWORD\n");
    divider();
code:
    num1 = rand();
    printf("\n\nThe secrect code is %d",num1);
    printf("\nEnter the above number: ");
    scanf("%d",&num2);

    if (num1 == num2){
    oldPass:
        printf("\nEnter your old password: ");
        takepassword(pass2);

        if(strcmp(pass2,u.pass1)){
            printf("\n\nINCORRECT PASSWORD !!\nTry again.....\n");
            goto oldPass;
        }
        else{
            printf("\n\nEnter your new password: ");
            takepassword(u.pass1);
        newPass:
            printf("\nConfirm password: ");
            scanf("%s",pass3);

            if(strcmp(pass3,u.pass1)){
                printf("\nINCORRECT PASSWORD !!\nTry again.....\n");
                goto newPass;
            }
            else{
                printf("\nPASSWORD CHANGED SUCCESFULLY !!\n");

                FILE *fp = fopen("account.txt", "w");
                fwrite(&u, sizeof(account), 1, fp);
                fclose(fp);
                getch();
            }
        }
    }
    else{
        printf("\nIncorrect code !!\nTry again.....\n");
        goto code;
    }
    fclose(fp);
}
void del_account()
{
    system("cls");
    account u;
    char user[20], pass[20];
    char ch;
    FILE *fp = fopen("account.txt", "r");
    fread(&u, sizeof(account), 1, fp);

    printf("\nDELETE ACCOUNT\n");
    divider();
user:
    printf("\n\nEnter your username: ");
    scanf("%s",user);

    if(strcmp(user,u.user)){
        printf("\nINCORRECT USERNAME !!\nTry again.....\n");
        goto user;
    }
    else{
    pass:
        printf("\nEnter your password: ");
        takepassword(pass);


        if(strcmp(pass,u.pass1)){
            printf("\nINCORRECT PASSWORD !!\nTry again.....\n");
            goto pass;
        }
        else{
            printf("\nDelete account [y/n]: ");
            ch = getche();
            getchar();

            if(ch == 'y' || ch == 'Y'){
                printf("\nAccount delection succesfully !!\n");
                fp = fopen("account.txt", "w");
                fprintf(fp, " ");
                fclose(fp);
                getch();
            }
            else{
                printf("\nAccount delection stoped\n");
                getch();
            }
        }
    }
}