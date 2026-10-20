
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char key[5][5];

void locate(char ch, int *r, int *c) {
    if (ch == 'J') ch = 'I';

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (key[i][j] == ch) {
                *r = i;
                *c = j;
                return;
            }
}

int main(void) {
    char cipher[500], ch;
    int r1, c1, r2, c2;

    printf("Enter the 25-letter key matrix: ");
    if (scanf("%25s", cipher) != 1)
        return 1;

    if (strlen(cipher) != 25) {
        printf("Invalid matrix.\n");
        return 1;
    }

    for (int i = 0; i < 25; i++)
        key[i / 5][i % 5] =
            toupper((unsigned char)cipher[i]);

    getchar();
    printf("Enter ciphertext: ");
    if (!fgets(cipher, sizeof(cipher), stdin))
        return 1;

    printf("Plaintext: ");

    for (int i = 0; cipher[i]; ) {
        if (!isalpha((unsigned char)cipher[i])) {
            i++;
            continue;
        }

        ch = toupper((unsigned char)cipher[i++]);
        if (ch == 'J') ch = 'I';
        if (!cipher[i]) break;

        while (cipher[i] &&
               !isalpha((unsigned char)cipher[i]))
            i++;

        if (!cipher[i]) break;

        char b = toupper((unsigned char)cipher[i++]);
        if (b == 'J') b = 'I';

        locate(ch, &r1, &c1);
        locate(b, &r2, &c2);

        if (r1 == r2) {
            putchar(key[r1][(c1 + 4) % 5]);
            putchar(key[r2][(c2 + 4) % 5]);
        } else if (c1 == c2) {
            putchar(key[(r1 + 4) % 5][c1]);
            putchar(key[(r2 + 4) % 5][c2]);
        } else {
            putchar(key[r1][c2]);
            putchar(key[r2][c1]);
        }
    }

    printf("\n");
    return 0;
}
