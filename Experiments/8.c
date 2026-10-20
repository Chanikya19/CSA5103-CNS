
#include <stdio.h>
#include <ctype.h>

int main(void) {
    char plain[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char cipher[] = "CIPHERABDFGJKLMNOQSTUVWXYZ";
    char msg[500];

    printf("Enter plaintext: ");
    if (!fgets(msg, sizeof(msg), stdin))
        return 1;

    printf("Ciphertext: ");

    for (int i = 0; msg[i]; i++) {
        char ch = toupper((unsigned char)msg[i]);

        if (ch >= 'A' && ch <= 'Z')
            putchar(cipher[ch - 'A']);
        else
            putchar(msg[i]);
    }

    return 0;
}
