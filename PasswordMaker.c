// PasscodeChecker

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void printword()
{
    printf("Ayy you are in now!! Check the source code in AbhinavaNoob/PasswordChecker\n");
}

int main()
{
    FILE *text;

    char password[100];
    char passwordname[100];

    if((text = fopen("pass.txt", "r")) == NULL)
    {
        printf("Create Passcode: ");
        scanf("%99s", passwordname);

        text = fopen("pass.txt", "w");

        if(text == NULL)
        {
            printf("Boi, you are cooked");
            return 1;
        }
        else
        {
            fprintf(text, "%s\n", passwordname);
        }
        fclose(text);
        text = fopen("pass.txt", "r");

        char line[100]; 

        if (fgets(line, sizeof(line), text) == NULL) 
        {
            printf("Boi, you are cooked.\n");
            fclose(text);
            return 1;
        }    
        else 
        {
            if(strcmp(passwordname, "RESET") == 0)
            {
                printf("You can't create passcode named %s because it is a command to reset your password if you forgot it.\n", "RESET");
                remove("pass.txt");
                return 1;
                printf("Done Creating Passcode!\n");
                snprintf(password, sizeof(password), "%s", passwordname);
                fclose(text);
            }
            else
            {
                printf("Done Creating Passcode!\n");
                snprintf(password, sizeof(password), "%s", passwordname);
                fclose(text);
            }
        }
    }
    else
    {
        if (fgets(password, sizeof(password), text) == NULL) 
        {
            printf("Boi, you are cooked.\n");
            fclose(text);
            return 1;
        }
        fclose(text);
        
        password[strcspn(password, "\n")] = 0;

        while(1)
        {
        char word[100];
        printf("Enter passcode: ");
        scanf("%99s", word);

        if(strcmp(word, "RESET") == 0)
        {
            printf("Resetting the password. File to remove is \"pass.txt\".\n");
            int rmvd = remove("pass.txt");
            if(rmvd == 1)
            {
                printf("Couldn't delete your password, please remove it by yourself.\n");
            }
            else
            {
                printf("Now it is deleted, you have to re-run this program to make new one.\n");
            }
            return 1;
        }
        else
        {
            if (strcmp(word, password) == 0) 
            {  
                printword(); // You can add anything in the void printword() place, it is at the beginning of the code.
                return 0;
            } else 
            {
                printf("Wrong passcode! To reset, just type RESET\n");
            }
        }
        }
    }
    return 0;
}
