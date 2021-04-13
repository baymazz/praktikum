#include <stdio.h>

int main(int argc, char const *argv[])
{
    int y, x = 87;
    int *px;

    x = 87;

    px = &x;
    y = *px;

    printf("Alamat x = %p\n", &x);
    printf("Isi px = %p\n", px);
    printf("Isi x = %p\n", x);
    printf("Nilai yang ditunjuk oleh px = %p\n", *px);
    printf("Nilai y = %p\n", y);
    return 0;
}
