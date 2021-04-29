#include <iostream>
#include <stdlib.h>
#include <curses.h>
#include <string.h>
#define max 100

using namespace std;

struct Tumpukan
{
    char isi[max];
    int atas;
} T;

void push (char x)
{
    if (T.atas == max)
    {
        cout<<"Tumpukan sudah penuh";
        getch;
    } else
    {
        T.atas++;
        T.isi[T.atas]=x;
    }
}

char pop()
{
    char hasil;
    if (T.atas == 0)
        cout<<"Tumpukan sudah kosong";
    else
    {
        hasil = T.isi[T.atas];
        T.atas--;
    }

    return hasil;
}

int main(int argc, char const *argv[])
{
    int i;
    char kalimat[max];
    T.atas = 0;
    cout<<"Input : ";
    cin.getline(kalimat, sizeof(kalimat));
    cout<<"\nKalimat Asli : "<<kalimat;

    for (int i = 0; i < strlen(kalimat); i++)
    {
        push(kalimat[i]);
    }

    cout<<"\nKalimat setelah dibalik : ";
    
    for (int i = 0; i < strlen(kalimat); i++)
    {
        cout<<pop();
    }
    
    cout<<endl;
    
    return 0;
}
