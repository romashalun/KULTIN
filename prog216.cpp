// Функция starline выводит строку из звездочек
#include "stdio.h"
#include "conio.h"

// выводит строку из звездочек
void starline(int len)
{
    for (int i = 0; i < len; i++)
        putch('*');
}

void main()
{
    starline(10);
    puts("\nДля завершения работы программы нажмите <Enter>");
    getch();
}

