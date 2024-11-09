#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
    char encrypted_ch, plain_ch;
    char encrypted_text[500], plain_text[500];
    int i;
    int key;

    printf("Enter encryped text: ");
    fgets(encrypted_text, sizeof(encrypted_text), stdin);
    encrypted_text[strcspn(encrypted_text, "\n")] = '\0';
    printf("\nEnter your key: ");
    scanf("%d",&key);

    for(i=0 ; encrypted_text[i] != '\0' ; i++){
        encrypted_ch = encrypted_text[i];

        if(isalnum(encrypted_ch)){
            if(isdigit(encrypted_ch)){
                plain_ch = (encrypted_ch - '0' - key) % 10 + '0';
            }
            else if(isupper(encrypted_ch)){
                plain_ch = (encrypted_ch - 'A' - key) % 26 + 'A';
            }
            else if(islower(encrypted_ch)){
                plain_ch = (encrypted_ch - 'a' - key) % 26 + 'a';
            }
        }
        else{
            plain_ch = encrypted_ch;
        }

        plain_text[i] = plain_ch;
    }

    plain_text[strlen(encrypted_text)] = '\0';
    printf("Plain text: %s",plain_text);

    return 0;
}