#include <stdio.h>

struct Kompleks
{
    int real;
    int img;
};

int main(int argc, char const *argv[])
{
    Kompleks a, b, tambah, kurang, kali, bagi;
    int penyebut;

    printf("Masukkan nilai a dan b untuk bilangan kompleks a+bi pertama (pisahkan dengan spasi) :");
    scanf("%d %d", &a.real, &a.img);

    printf("Masukkan nilai a dan b untuk bilangan kompleks a+bi kedua (pisahkan dengan spasi) :");
    scanf("%d %d", &b.real, &b.img);

    // Operasi penjumlahan
    tambah.real = a.real + b.real;
    tambah.img = a.img + b.img;

    // Operasi pengurangan
    kurang.real = a.real - b.real;
    kurang.img = a.img - b.img;

    // Operasi perkalian
    kali.real = (a.real*b.real - a.img*b.img);
    kali.img = (a.real*b.img + a.img*b.real);

    // Operasi pembagian
    bagi.real = (a.real*b.real + a.img*b.img);
    bagi.img = (a.img*b.real - a.real*b.img);
    penyebut = (b.real*b.real + b.img*b.img);

    // Print Hasil
    printf("(%d + %di) + (%d + %di) = %d + %di\n", a.real, a.img, b.real, b.img, tambah.real, tambah.img);
    printf("(%d + %di) - (%d + %di) = %d + %di\n", a.real, a.img, b.real, b.img, kurang.real, kurang.img);
    printf("(%d + %di) * (%d + %di) = %d + %di\n", a.real, a.img, b.real, b.img, kali.real, kali.img);
    printf("(%d + %di) / (%d + %di) = (%d + %di)/%d\n", a.real, a.img, b.real, b.img, bagi.real, bagi.img, penyebut);
    

    return 0;
}
