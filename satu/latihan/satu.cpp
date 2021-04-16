#include <stdio.h>

int main(int argc, char const *argv[])
{
    char array[6] = {'p', 'e', 'n', 's', 'i', 't'};

    for (int i = 5; i >= 0; i--)
    {
        printf("%c", array[i]);
    }
    
    return 0;
}
