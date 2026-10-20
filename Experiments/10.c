
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char key[5][5] = {
    {'M','F','H','I','K'},
    {'U','N','O','P','Q'},
    {'Z','V','W','X','Y'},
    {'E','L','A','R','G'},
    {'D','S','T','B','C'}
};

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

void encrypt(char a, char b) {
    int r1, c1, r2, c2;
    locate(a, &r1, &c1);
    locate(b, &r2, &c2);

    if (r1 == r2) {
        putchar(key[r1][(c1 + 1) % 5]);
        putchar(key[r2][(c2 + 1) % 5]);
    } else if (c1 == c2) {
        putchar(key[(r1 + 1) % 5][c1]);
        putchar(key[(r2 + 1) % 5][c2]);
    } else {
        putchar(key[r1][c2]);
        putchar(key[r2][c1]);
    }
}

int main(void) {
    char msg[500], p[500];
    int n = 0;

    printf("Enter plaintext: ");
    if (!fgets(msg, sizeof(msg), stdin))
        return 1;

    for (int i = 0; msg[i]; i++)
        if (isalpha((unsigned char)msg[i])) {
            char ch = toupper((unsigned char)msg[i]);
            p[n++] = (ch == 'J') ? 'I' : ch;
        }

    printf("Ciphertext: ");

    for (int i = 0; i < n; ) {
        char a = p[i++];
        char b;

        if (i == n || p[i] == a)
            b = 'X';
        else
            b = p[i++];

        encrypt(a, b);
        if (i < n) putchar(' ');
    }

    printf("\n");
    return 0;
}
