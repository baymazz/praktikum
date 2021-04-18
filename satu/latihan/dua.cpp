#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, m, n;
    
    printf("\t\t============ Operasi pada 2 Matriks ============\n\n");
    printf("Masukkan baris (a) dan kolom (b) matriks pertama (pisahkan dengan spasi) : ");
    scanf("%d %d", &a, &b);
    printf("Masukkan baris (m) dan kolom (n) matriks kedua (pisahkan dengan spasi) : ");
    scanf("%d %d", &m, &n);

    int x[a][b], y[m][n];

    printf("\nMasukkan nilai elemen matriks pertama sesuai baris dan kolom :\n");
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            scanf("%d", &x[i][j]);
        }
        
    }
    
    printf("Masukkan nilai elemen matriks kedua sesuai baris dan kolom :\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &y[i][j]);
        }
        
    }

    if (a == m && b == n)
    {
        int tambah[a][b], kurang[a][b];
        
        // Operasi Penjumlahan dan Pengurangan
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                tambah[i][j] = x[i][j] + y[i][j];
                kurang[i][j] = x[i][j] - y[i][j];
            }
            
        }

        // Print hasil Penjumlahan dan Pengurangan
        printf("\nHasil penjumlahan matriks pertama dan kedua : \n");
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                printf("%d ", tambah[i][j]);
                if (j == (b-1))
                {
                    printf("\n");
                }
                
            }
            
        }

        printf("\nHasil pengurangan matriks pertama dan kedua : \n");
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                printf("%d ", kurang[i][j]);
                if (j == (b-1))
                {
                    printf("\n");
                }
                
            }
            
        }
        
    } else if (a != m || b != n)
    {
        printf("\nOperasi penjumlahan dan pengurangan tidak dapat dilakukan, \nkarena kedua matriks memiliki ordo yang berbeda,\n");
    }
    
    // Operasi Perkalian
    if (b == m)
    {
        int kali[a][n];
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < n; j++)
            {
                kali[i][j] = 0;
                for (int k = 0; k < b; k++)
                {
                    kali[i][j] = kali[i][j] + (x[i][k] * y[k][j]);
                }
                
            }
            
        }
        
        printf("\nHasil perkalian matriks pertama dan kedua : \n");
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", kali[i][j]);
                if (j == (n-1))
                {
                    printf("\n");
                }
                
            }
            
        }
        
        printf("\n");
    } else if (b != m)
    {
        printf("Operasi perkalian tidak dapat dilakukan,\nkarena nilai b dan m berbeda.");
    }
    
    
    



    return 0;
}
