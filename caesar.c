# include <cs50.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>


int main (int argc, string argv[])
{
// take key as part of command line argument
    if (argc !=2)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
    //make sure every character in argv[1] is a digit
    for (int key = 0; key < strlen(argv[1]); key++)
    {
        if (isalpha(argv[1][key]))
        {
            printf("Usage: ./caesar key\n");
        }
    }
    //int key
    int key = atoi(argv[1]) % 26;

    //prompt user for plaintest
    string plaintext = get_string("Thy Brief: ");
    //convert argv[1] from 'string' to 'int'
    for (int i = 0, length = strlen(plaintext); i < length; i++)
    {
        if (!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
            continue;
        }
    //for each character in plaintext

    //rotate the character if its a letter
        int n = isupper(plaintext[i]) ? 65 : 97;
        int pi = plaintext[i] - n;
        int ci = (pi + key) % 26;
        printf("%c", ci + n);
    }

//printout coded message
    printf("\n");
    return 0;
}