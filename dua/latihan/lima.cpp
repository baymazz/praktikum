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
int drjt(char);
void konversi_cetak(char []);
int cek(char []);

int main(int argc, char const *argv[])
{
    char tampung[MAXSTACK], jawab;
    int check;

    puts("MENGUBAH NOTASI INFIX MENJADI POSTFIX");
    puts("DENGAN MEMANFAATKAN STRUKTUR STACK");
    do
    {
        InitializeStack(&tumpukan);
        fflush(stdin);
        puts("");
        printf("Masukkan ekspresi dalam notasi infix : ");
        fgets(tampung, sizeof(tampung), stdin);
        check = cek(tampung);
        if (check == 0)
        {
            printf("Ungkapan postfixnya = ");
            konversi_cetak(tampung);
            puts("");
        }
        fflush(stdin);
        printf("\nMau mencoba lagi (y/t) ? ");
        scanf("%c", &jawab);
    } while ((jawab == 'y') || (jawab == 'Y'));
    
    return 0;
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

int drjt(char x)
{
    if(x == '(')
        return 0;
    else if((x == '+') || (x == '-'))
        return 1;
    else if((x == '*') || (x == '/'))
        return 2;
    else if(x == '^')
        return 3;
    else
        return -1;
}

void konversi_cetak(char temp[])
{
    int i, pjg, valid = 1;
    char kar, smtr;

    pjg = strlen(temp) - 1;
    for (i = 0; i < pjg; i++)
    {
        kar = temp[i];
        switch (kar)
        {
        case '(':
            Push(kar, &tumpukan);
            break;
        
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            printf("%c", kar);
            break;

        case '+': case '-': case '*': case '/': case '^':
            if ((Empty(&tumpukan)) || ((drjt(kar) > drjt(tumpukan.item[tumpukan.count]))))
            {
                Push(kar, &tumpukan);
            } else
            {
                do 
                {
                    smtr = Pop(&tumpukan);
                    printf("%c", smtr);
                } while (drjt(kar) < drjt(tumpukan.item[tumpukan.count]));
                Push(kar, &tumpukan);
            }
            break;
        
        case ')':
            while(tumpukan.item[tumpukan.count] != '(') {
                smtr = Pop(&tumpukan);
                printf("%c", smtr);
            }
            Pop(&tumpukan);
            break;

        default :
            valid = 0;
            puts("INVALID STATEMENT");
            break;
        }
    }
    
    if((valid != 0) && (!Empty(&tumpukan)))
    {
        smtr = Pop(&tumpukan);
        printf("%c", smtr);
    }
}

int cek(char temp[])
{
    int i, pjg, kurung = 1, operatr = 1, operand = 0, x;
    char kar, smtr;

    // printf("MULAI CEK\n");

    pjg = strlen(temp) - 1;
    for (i = 0; i < pjg; i++)
    {
        kar = temp[i];
        switch (kar)
        {
        case '(':
            operand = 0;
            kurung = 0;
            if (operatr == 0)
            {
                operatr = 2;
            }
            break;
        
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            if (operand == 0)
            {
                operand = 1;
            }
            if (operatr != 2)
            {
                operatr = 0;
            }
            
            break;

        case '+': case '-': case '*': case '/': case '^':
            if (operand == 0 || operand == 2)
            {
                operand = 2;
                break;
            }
            operand = 0;
            if (operatr == 0)
            {
                operatr = 1;
            }
            
            break;
            
        
        case ')':
            if (kurung == 0)
            {
                kurung = 1;
            } else if (kurung == 1)
            {
                kurung = 0;
            }

            if (operand == 0 || operand == 2)
            {
                operand = 2;
                break;
            }
            
            break;
            
            
        }

        // printf("saat char nya '%c', operand nya '%d', operator nya '%d', dan kurungnya '%d'\n", kar, operand, operatr, kurung);
    }

    // printf("kurungnya '%d'", kurung);

    x = 0;

    if (operatr == 2)
    {
        printf("Output : Notasi infix salah, operator tidak lengkap\n");
        x = 1;
    }
    
    if (operand == 2)
    {
        printf("Output : Notasi infix salah, operand tidak lengkap\n");
        x = 2;
    }

    if (kurung == 0)
    {
        printf("Output : Notasi infix salah, kurung tidak lengkap\n");
        x = 3;
    }

    // printf("SELESAI CEK\n");

    return x;
}