#include <stdio.h>

char strA[80] = "ABCDE";
char strB[80];

int main(int argc, char const *argv[])
{
    char *pA;
    char *pB;
    
    puts(strA);
    pA = strA;
    puts(pA);
    pB = strB;
    putchar('\n');

    while (*pA != '\0')
    {
        *pB++ = *pA++;
    }
    *pB = '\0';
    puts(strB);

    return 0;
}
