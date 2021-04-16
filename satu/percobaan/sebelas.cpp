#include <stdio.h> 
#include <string.h> 

struct dtnilai
{
    char nim[11];
    char nama[20];
    double nilai;
};

struct dtnilai data[10];
int j = 0;

void tambah_data()
{
    char jawab[2];
    while (1)
    {
        fflush(stdin);
        printf("\nNIM\t\t; ");
        scanf("%s", &data[j].nim);

        printf("Nama\t\t: ");
        scanf("%s", &data[j].nama);

        printf("Nilai test\t: ");
        scanf("%lf", &data[j].nilai);

        printf("Ada data lagi? [y/t] :");
        scanf("%s", &jawab);

        if((strcmp(jawab, "Y") == 0) || (strcmp(jawab, "y") == 0))
        {
            j++;
            continue;
        } else if((strcmp(jawab, "T") == 0) || (strcmp(jawab, "t") == 0))
            break;

    }
    
}

void tampil()
{
    int i;
    printf("\nData Mahasiswa yang telah diinputkan :\n");
    printf("NIM\t\tNama\t\tNilai\n");

    for ( i = 0; i <= j; i++)
    {
        printf("%s\t%s\t\t%6.2f\n", data[i].nim, data[i].nama, data[i].nilai);
    }
    
}

int main(int argc, char const *argv[])
{
    tambah_data();
    tampil();
    return 0;
}
