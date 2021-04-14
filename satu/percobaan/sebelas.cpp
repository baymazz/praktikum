#include <stdio.h>
#include <string.h>

struct dtnilai
{
    char nim[10];
    char nama[20];
    double nilai;
};

struct dtnilai data[10];
int j = 0;

int tambah_data()
{
    char jawab[2];
    while (1)
    {
        fflush(stdin);
        printf("NIM\t:");
        scanf("%s", &data[j].nim);

        printf("Nama\t:");
        scanf("%s", &data[j].nama);

        printf("Nilai test\t:");
        scanf("%lf", &data[j].nilai);

        printf("Ada data lagi? [y/t]\t:");
    }
    
}