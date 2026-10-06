#include <stdio.h>
#include <string.h>

int gcd(int a, int b)
{
    while(b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int main()
{
    char text[100], cipher[100];
    int a, b, i, p, c;

    printf("Enter plaintext: ");
    scanf("%s", text);

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    if(gcd(a, 26) != 1)
    {
        printf("Invalid value of a");
        return 0;
    }

    for(i = 0; text[i] != '\0'; i++)
    {
        p = text[i] - 'A';
        c = (a * p + b) % 26;
        cipher[i] = c + 'A';
    }

    cipher[i] = '\0';

    printf("Ciphertext: %s", cipher);

    return 0;
}
