#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int n = 26;
string substitution(string word);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Please provide one command line argument only.\n");
        return 1;
    }
    int key[n];
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // check that the key contains only letters
    for (int i = 0; i < n; i++)
    {
        if (!((argv[1][i] >= 'a' && argv[1][i] <= 'z') || (argv[1][i] >= 'A' && argv[1][i] <= 'Z')))
        {
            printf("Key must contain only letters\n");
            return 1;
        }
        // convert the string to uppercase
        else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
        {
            argv[1][i] = toupper(argv[1][i]);
        }
        // for each letter of the key we loop through the array to look for repeated letters
        for (int j = 0; j < i; j++)
        {
            if (argv[1][i] == key[j])
            {
                printf("Key must not contain repeated  letters.\n");
                return 1;
            }
        }
        key[i] = argv[1][i];
    }
    string word = get_string("plaintext: \n");
    char substitute[strlen(word) + 1];

    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i]) != 0) // Upper characteres
        {
            for (int j = 0; j < n; j++)
            {
                if (word[i] == alphabet[j])
                {
                    substitute[i] = argv[1][j];
                }
            }
        }
        else if (islower(word[i]) != 0) // Lower characteres
        {
            for (int j = 0; j < n; j++)
            {
                if (word[i] == tolower(alphabet[j]))
                {
                    substitute[i] = tolower(argv[1][j]);
                    break;
                }
            }
        }
        else // Non letter character
        {
            substitute[i] = word[i];
        }
    }
    substitute[strlen(word)] = '\0'; // termination character
    printf("ciphertext: %s\n", substitute);
}
