#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

int main(int argc, char **argv)
{
   int *prime;
   int n;
   int cek;
   std::vector<int> temp;

   
   printf("== Program Print Bilangan Prima Pertama Sampai ke-n ==\n\n");
   printf("input batas bilangan (n) : ");
   scanf("%d", &n);

   prime = (int*)malloc(n * sizeof(int));
    
   temp.push_back(1);
   temp.push_back(2);
   temp.push_back(3);

   for (int i = 4; i <= 1000; i++)
   {
      for (int j = 2; j < i; j++)
      {
         if((i % j)  == 0)
            cek = 0;

         if(cek == 0)
            break;
      }
        
      if (cek == 1)
         temp.push_back(i);
      else
         cek = 1;

      if (temp.size() == n)
         break;
      
   }
    
   for (int i = 0; i < temp.size(); i++)
   {
      *(prime + i + 1) = temp[i];
   }
    
   printf("%d Bilangan Prima Pertama adalah : \n", n);

   for (int i = 1; i <= n; i++)
   {
      if(*(prime + i) != 0)
         printf("%d ", *(prime + i));
   }
    
    putchar('\n');
    free(prime);
    return 0;
}
