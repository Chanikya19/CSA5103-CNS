
#include <stdio.h>
#include <math.h>

int main(void) {
    long double factorial = 1.0L;

    for (int i = 1; i <= 25; i++)
        factorial *= i;

    printf("Total possible keys = 25! = %.0Lf\n", factorial);
    printf("Approximate power of 2 = 2^%.2Lf\n",
           log2l(factorial));

    factorial /= 25.0L;

    printf("Effectively unique keys (row/column cyclic shifts)\n");
    printf("= 24! = %.0Lf\n", factorial);
    printf("Approximate power of 2 = 2^%.2Lf\n",
           log2l(factorial));

    return 0;
}
