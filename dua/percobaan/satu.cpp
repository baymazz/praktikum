#include <stdio.h>
#define MAXSTACK 5

typedef int ItemType;

typedef struct
{
    int Item[MAXSTACK];
    int Count;
}Stack;

void InitializeStack(Stack *S)
{
    S->Count = 0;
}

int Empty(Stack *S)
{
    return (S->Count == 0);
}

int Full(Stack *S)
{
    return (S->Count == MAXSTACK);
}

void Push(ItemType x, Stack *S)
{
    if (S->Count == MAXSTACK)
    {
        printf("Stack penuh! Data tidak dapat masuk!");
    } else {
        S->Item[S->Count] = x;
        ++(S->Count);
    }
}

int Pop(Stack *S)
{
    if (S->Count == 0)
    {
        printf("Stack masih kosong!");
        return 0;
    } else {
        --(S->Count);
        return (S->Item[S->Count]);
    }
    
}

int main(int argc, char const *argv[])
{
    int i, input;
    Stack tumpukan;
    
    InitializeStack(&tumpukan);

    for (i = 0; i < MAXSTACK; i++)
    {
        printf("Masukkan isi stack ke-%d : ", i+1);
        scanf("%d", &input);
        Push(input, &tumpukan);
    }
    
    puts("");

    for (i = MAXSTACK; i > 0; i--)
    {
        printf("Isi stack ke-%d : ", i);
        printf("%d \n", Pop(&tumpukan));
    }
    
    
    return 0;
}