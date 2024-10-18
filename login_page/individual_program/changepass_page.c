#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<time.h>

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
void forget(){}
void change_pass()
{
    int num1, num2;
    system("cls");
    srand(time(0));

    printf("\n\t\tCHANGE PASSWORD\n");
    divider();
random:
    num1 = rand();
    printf("\n\nThe random number is %d\n",num1);

    printf("Enter the above number: ");
    scanf("%d",&num2);
    
    if(num1 == num2){
        char pass2[20];
        account u;
        FILE *fp = fopen("account.txt", "r");
        fread(&u, sizeof(account), 1, fp);
    old_pass:
        printf("\nEnter old password: ");
        takepassword(pass2);
        
        if(strcmp(pass2, u.pass1)){
            printf("\n\n*******INCORRECT OLD PASSWORD*******\nTry again.....\n");
            goto old_pass;
        }
        else{
            char pass3[20];
            printf("\n\nEnter new password: ");
            takepassword(u.pass1);
        cfr_pass:
            printf("\nConfirm password: ");
            scanf("%s",pass3);

            if(strcmp(pass3, u.pass1)){
                printf("\n*******INCORRECT OLD PASSWORD*******\nTry again.....\n");
                goto cfr_pass;
            }
            else{
                printf("\nPASSWORD SUCCESFULLY !!\n");
                FILE *fp = fopen("account.txt", "w");
                fwrite(&u, sizeof(account), 1, fp);
                fclose(fp);
                getch();
            }
        }
        fclose(fp);
    }
    else{
        printf("\n*******INCORRECT NUMBER*******\nTry again.....\n");
        goto random;
    }
}
void del_account(){}