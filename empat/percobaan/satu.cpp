#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
    int *fibo;
    int n;

    printf("== Program Print Bilangan Fibonacci Pertama Sampai ke-n ==\n\n");
    printf("input batas bilangan (n) : ");
    scanf("%d", &n);

    fibo = (int*)malloc(n * sizeof(int));

    *(fibo + 1) = 1;
    *(fibo + 2) = 1;

    for (int i = 3; i <= n; i++)
    {
        *(fibo + i) = (*(fibo + i - 2) + *(fibo + i - 1));
    }
    
    printf("%d Bilangan Fibonaci Pertama adalah : \n", n);

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", *(fibo + i));
    }
    
    putchar('\n');
    free(fibo);
    return 0;
}
