#include <stdio.h>
#include <string.h>

#define MAXSTACK 100

typedef char ItemType;
typedef struct {
    char item[MAXSTACK];
    int count;
} Stack;

Stack tumpukan;

void InitializeStack(Stack *);
int Empty (Stack *);
int Full(Stack *);
void Push(ItemType, Stack *);
ItemType Pop(Stack *);

int main(int argc, char const *argv[])
{
    InitializeStack(&tumpukan);
    char input[MAXSTACK];
    printf("Input : ");
    fflush(stdin);
    fgets(input, sizeof(input), stdin);
    printf("Output : ");
    for (int i = 0; i <= sizeof(input); i++)
    {
        if (input[i] == '*')
        {
            printf("%c", Pop(&tumpukan));
        } else
        {
            Push(input[i], &tumpukan);
        }
        
    }
    
    fflush(stdin);
    printf("\n");
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