
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int mod26(int n) {
    return (n % 26 + 26) % 26;
}

int main(void) {
    char msg[1000], p[1000];
    int n = 0, choice;

    int K[2][2] = {{9, 4}, {5, 7}};
    int invK[2][2] = {{5, 12}, {15, 25}};

    printf("1. Encrypt\n2. Decrypt\nChoice: ");
    scanf("%d", &choice);
    getchar();

    printf("Enter message: ");
    if (!fgets(msg, sizeof(msg), stdin))
        return 1;

    for (int i = 0; msg[i]; i++)
        if (isalpha((unsigned char)msg[i]))
            p[n++] = toupper((unsigned char)msg[i]);

    if (choice == 1 && n % 2 != 0)
        p[n++] = 'X';

    if (choice != 1 && choice != 2) {
        printf("Invalid choice.\n");
        return 1;
    }

    printf("Result: ");

    for (int i = 0; i < n; i += 2) {
        int x = p[i] - 'A';
        int y = p[i + 1] - 'A';
        int a, b;

        if (choice == 1) {
            a = mod26(K[0][0] * x + K[0][1] * y);
            b = mod26(K[1][0] * x + K[1][1] * y);
        } else {
            a = mod26(invK[0][0] * x + invK[0][1] * y);
            b = mod26(invK[1][0] * x + invK[1][1] * y);
        }

        putchar('A' + a);
        putchar('A' + b);
    }

    printf("\n");
    return 0;
}
