#include <stdio.h>
#include <string.h>

#define MAXSTACK 100

typedef int ItemType;
typedef struct {
    ItemType item[MAXSTACK];
    int count;
} Stack;

Stack tumpukan;

void InitializeStack(Stack *);
int Empty (Stack *);
int Full(Stack *);
void Push(ItemType, Stack *);
ItemType Pop(Stack *);
void biner(int);
void oktal(int);
void heksa(int);
int MAX;

int main(int argc, char const *argv[])
{
    InitializeStack(&tumpukan);
    int input;
    printf("Input (desimal) : ");
    scanf("%d", &input);
    printf("Dalam biner : ");
    biner(input);
    printf("Dalam oktal : ");
    oktal(input);
    printf("Dalam heksadesimal : ");
    heksa(input);
}

void InitializeStack(Stack *S)
{
    S->count = 0;
}

int Empty(Stack *S)
{
    return (S->count == 0);
}

int Full(Stack *S)
{
    return (S->count == MAXSTACK);
}

void Push(ItemType x, Stack *S)
{
    if (Full(S))
    {
        printf("Stack penuh! Data tidak dapat masuk!");
    } else
    {
        ++(S->count);
        S->item[S->count] = x;
    }
}

ItemType Pop(Stack *S)
{
    ItemType x;

    if (Empty(S))
    {
        printf("STACK KOSONG!");
        return 0;
    } else
    {
        x = (S->item[S->count]);
        --(S->count);
        return x;
    }   
}

void biner(int n)
{
    for (int i = 1, m; n > 0; n = n/2, i++)
    {
        MAX = i;
        m = n % 2;
        Push(m, &tumpukan);
    }

    for (int i = MAX; i > 0; i--)
    {
        printf("%d", Pop(&tumpukan));
    }

    printf("\n");
}

void oktal(int n)
{
    for (int i = 1, m; n > 0; n = n/8, i++)
    {
        MAX = i;
        m = n % 8;
        Push(m, &tumpukan);
    }

    for (int i = MAX; i > 0; i--)
    {
        printf("%d", Pop(&tumpukan));
    }

    printf("\n");
}

void heksa(int n)
{
    for (int i = 1, m; n > 0; n = n/16, i++)
    {
        MAX = i;
        m = n % 16;
        Push(m, &tumpukan);
    }

    for (int i = MAX; i > 0; i--)
    {
        int p = Pop(&tumpukan);
        if (p <= 9)
        {
            printf("%d", p);
        } else
        {
            switch (p)
            {
            case 10:
                printf("A");
                break;
            
            case 11:
                printf("B");
                break;

            case 12:
                printf("C");
                break;

            case 13:
                printf("D");
                break;

            case 14:
                printf("E");
                break;

            case 15:
                printf("F");
                break;

            default:
                break;
            }
        }
    }

    printf("\n");
}