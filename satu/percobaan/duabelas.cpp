#include <stdio.h>
#include <string.h>

struct dtnilai
{
    char nim[10];
    char nama[20];
    double nilai;
};

void tampil(struct dtnilai *p)
{
    printf("\n%s ", p->nim);
    printf("%s ", p->nama);
    printf("%.1lf\n ", p->nilai);
}

struct dtnilai my_struct;

int main(int argc, char const *argv[])
{
    struct dtnilai *st_ptr;
    st_ptr = &my_struct;
    strcpy(my_struct.nim, "01");
    printf("\n%s", my_struct.nim);

    strcpy(my_struct.nama, "Arini");
    printf("\n%s", my_struct.nama);
    my_struct.nilai = 63.6;
    tampil(st_ptr);
    return 0;
}

