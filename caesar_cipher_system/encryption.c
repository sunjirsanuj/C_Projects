#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
    char plain_ch, encrypted_ch;
    char plain_text[500], encrypted_text[500];
    int i;
    int key = 3;

    start:
    printf("Enter text to encryption: ");
    fgets(plain_text, sizeof(plain_text), stdin);
    plain_text[strcspn(plain_text, "\n")] = '\0';

    for(i=0 ; plain_text[i] != '\0' ; ++i){
        plain_ch = plain_text[i];

        if(isalnum(plain_ch)){

            if(isdigit(plain_ch)){
                encrypted_ch = (plain_ch - '0' + key) % 10 + '0';
            }
            else if(isupper(plain_ch)){
                encrypted_ch = (plain_ch - 'A' + key) % 26 + 'A';
            }
            else if(islower(plain_ch)){
                encrypted_ch = (plain_ch - 'a' + key) % 26 + 'a';
            }
        }
        else if(ispunct(plain_ch)){
            encrypted_ch = plain_ch;
        }
        else if(isspace(plain_ch)){
            encrypted_ch = plain_ch;
        }
        else{
            printf("\n\n*******INVALIED INPUT*******\nTry again\n\n");
            goto start;
        }

        encrypted_text[i] = encrypted_ch;
    }

    printf("Encrypted text: %s\n",encrypted_text);

    return 0;

}