// Функция "факториал"
#include "stdio.h"
#include "conio.h"

unsigned long factorial(int x)
{
    unsigned long f = 1;
    for (int i = 2; i <= x; i++)
        f *= i;
    return(f);
}

void main()
{
    unsigned long f;
    puts("\nТаблица факториалов");
    for (int n = 1; n <= 12; n++)
    {
        f = factorial(n);
        printf("%2i  %10u\n", n, f);
    }
    
    puts("\nДля завершения работы нажмите <Enter>");
    getch();
}

