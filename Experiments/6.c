
#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int mod26(int n) {
    return (n % 26 + 26) % 26;
}

int main(void) {
    int a, b, p, c;
    int inv;

    printf("Possible affine keys:\n");

    /* Assume E -> B and T -> U */
    for (a = 1; a < 26; a++) {
        if (gcd(a, 26) != 1)
            continue;

        for (b = 0; b < 26; b++) {
            if (mod26(4 * a + b) == 1 &&
                mod26(19 * a + b) == 20) {

                inv = 1;
                while ((a * inv) % 26 != 1)
                    inv++;

                printf("a = %d, b = %d\n", a, b);
                printf("Decryption formula: P = %d(C - %d) mod 26\n",
                       inv, b);
            }
        }
    }

    return 0;
}
