#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool confirm_isdigit(string key);

int main(int argc, string argv[])
{
    //Confirms if the user types the correct amount of command line arguments and confirms if the key is a digit
    if (argc != 2 || confirm_isdigit(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    //Asks user for the plaintext to encrypt
    string plaintext = get_string("plaintext: ");

    //Encrypts the plaintext and prints the ciphertext
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        //If the character is uppercase it will start at 65 in the ASCII table.
        if (isupper(plaintext[i]))
        {
            printf("%c", (((plaintext[i] + key) - 65) % 26) + 65);
        }
        //If the character is lowercase it will start at 97 in the ASCII table.
        else if (islower(plaintext[i]))
        {
            printf("%c", (((plaintext[i] + key) - 97) % 26) + 97);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
}


//Confirms if the key is a digit
bool confirm_isdigit(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        char ch = key[i];
        if (!isdigit(ch))
        {
            return true;
        }
    }
    return false;
}
