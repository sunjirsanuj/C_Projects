#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
    char plain_ch, encrypted_ch;
    char plain_text[500], encrypted_text[500];
    int i;
    int key;

    printf("Enter text to encryption: ");
    fgets(plain_text, sizeof(plain_text), stdin);
    plain_text[strcspn(plain_text, "\n")] = '\0';
    printf("\nEnter your key: ");
    scanf("%d",&key);

    for(i=0 ; plain_text[i] != '\0' ; i++){
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
        else{
            encrypted_ch = plain_ch;
        }

        encrypted_text[i] = encrypted_ch;
    }

    encrypted_text[strlen(plain_text)] = '\0';
    printf("Encrypted text: %s",encrypted_text);

    return 0;
}