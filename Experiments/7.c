
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char cipher[1000];
    char key[27];

    printf("Enter key (26 letters, cipher-to-plain): ");
    scanf("%26s", key);
    getchar();

    printf("Enter ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);

    for (int i = 0; cipher[i]; i++) {
        if (isalpha((unsigned char)cipher[i])) {
            int c = toupper((unsigned char)cipher[i]) - 'A';
            putchar(toupper((unsigned char)key[c]));
        } else {
            putchar(cipher[i]);
        }
    }

    return 0;
}
