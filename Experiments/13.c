
#include <stdio.h>

int mod26(int x) {
    return (x % 26 + 26) % 26;
}

int inverse26(int x) {
    for (int i = 1; i < 26; i++)
        if (mod26(x * i) == 1)
            return i;
    return -1;
}

int main(void) {
    int p[2][2], c[2][2];
    int det, inv, adj[2][2], key[2][2];

    printf("Enter plaintext matrix P (4 numbers):\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &p[i][j]);

    printf("Enter ciphertext matrix C (4 numbers):\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &c[i][j]);

    det = mod26(p[0][0] * p[1][1] -
                p[0][1] * p[1][0]);

    inv = inverse26(det);

    if (inv == -1) {
        printf("Cannot recover key: P is not invertible mod 26.\n");
        return 1;
    }

    adj[0][0] = p[1][1];
    adj[0][1] = -p[0][1];
    adj[1][0] = -p[1][0];
    adj[1][1] = p[0][0];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            adj[i][j] = mod26(adj[i][j] * inv);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            key[i][j] = 0;
            for (int k = 0; k < 2; k++)
                key[i][j] += c[i][k] * adj[k][j];

            key[i][j] = mod26(key[i][j]);
        }
    }

    printf("Recovered Hill key:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            printf("%d ", key[i][j]);
        printf("\n");
    }

    return 0;
}
