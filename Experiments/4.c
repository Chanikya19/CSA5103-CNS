#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[100], key[100], cipher[100];
    int i, j = 0, k;

    printf("Enter plaintext: ");
    scanf("%s", text);

    printf("Enter key: ");
    scanf("%s", key);

    for(i = 0; text[i] != '\0'; i++)
    {
        if(isalpha(text[i]))
        {
            k = toupper(key[j % strlen(key)]) - 'A';

            if(isupper(text[i]))
                cipher[i] = (text[i] - 'A' + k) % 26 + 'A';
            else
                cipher[i] = (text[i] - 'a' + k) % 26 + 'a';

            j++;
        }
        else
        {
            cipher[i] = text[i];
        }
    }

    cipher[i] = '\0';

    printf("Ciphertext: %s", cipher);

    return 0;
}
