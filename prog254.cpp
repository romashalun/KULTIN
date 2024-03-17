// Рекурсивная функция "Факториал"
#include "stdio.h"
#include "conio.h"

unsigned int factor(unsigned int k)
{
    if ( k == 1 )
        return(1);
    else
        return(k*factor(k-1));
}

void main()
{
    unsigned int n; // число, факториал которого надо вычислить
    unsigned int f; // факториал числа n

    puts("Вычисление факториала\n");
    puts("Введите число, факториал которого надо вычислить");
    printf("->");
    scanf("%u", &n);
    f = factor(n);
    printf("Факториал числа %u равен %u", n, f);

    printf("\nДля завершения нажмите <Enter>");
    getch();
}

