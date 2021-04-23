#include <stdio.h>

int main(int argc, char const *argv[])
{
    int P1[10] = {15, 0, 0, 1, 0, 5, 0, 8, 6, 0};
    int P2[10] = {10, 0, 2, 2, 3, 0, 0, 4, 0, 3};
    int P3[10] = {5, 0, 1, 0, 0, 0, 0, 0, 0, 0};
    int tambah[10], kurang[10], turun[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int perkalian[11] = {0,0,0,0,0,0,0,0,0,0};

    // Operasi Penambahan P1 + P2
    for (int i = 0; i < 10; i++)
    {
        tambah[i] = P1[i] + P2[i];
    }
    
    // Operasi Pengurangan P1 - P2
    for (int i = 0; i < 10; i++)
    {
        kurang[i] = P1[i] - P2[i];
    }

    // Operasi Perkalian P1 * P3
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            perkalian[i+j] += P1[i] * P3[j];
        }
    }
    
    // Operasi Turunan P2'
    for (int i = 9; i < 10; i++)
    {
        turun[i-1] = P2[i] * i;
    }
    
    // Print Hasil
    
    // Penambahan
    printf("P1 + P2 =");
    for (int i = 9; i >= 0; i--)
    {
        if (tambah[i] != 0 && i != 0)
        {
            printf(" %dx^%d +", tambah[i], i);
        } else if (i == 0) 
        {
            printf(" %d\n", tambah[i]);
        }
        
    }
    
    // Pengurangan
    printf("P1 - P2 =");
    for (int i = 9; i >= 0; i--)
    {
        if (tambah[i] != 0 && i != 0)
        {
            printf(" %dx^%d +", kurang[i], i);
        } else if (i == 0) 
        {
            printf(" %d\n", kurang[i]);
        }
        
    }
    

    // Perkalian
    printf("P1 * P3 =");
    for (int i = 10; i >= 0; i--)
    {
        if (perkalian[i] != 0 && i != 0)
        {
            printf(" %dx^%d +", perkalian[i], i);
        } else if (perkalian[i] != 0 && i == 0) 
        {
            printf(" %d\n", perkalian[i]);
        }
        
    }

    // Turunan
    printf("P2' =");
    for (int i = 9; i >= 0; i--)
    {
        if (turun[i] != 0 && i != 0)
        {
            printf(" %dx^%d +", turun[i], i);
        } else if (turun[i] != 0 && i == 0) 
        {
            printf(" %d\n", turun[i]);
        }
        
    }

    return 0;
}
