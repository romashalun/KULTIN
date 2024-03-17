// Функция line выводит на экран строку из символов
#include "stdio.h"
#include "conio.h"

// выводит на экран строку состоящую
// из n ch-символов
void line(char ch, int n)
{
    for (int i = 0; i < n; i++)
        putch(ch);
}

// возвращает длину строки
int length(char* st)
{
    int l = 0;  // длина строки
    char* p = st;  // указатель на символ
    
    while ( *p++  )
        l++;
    return(l);
}

void main()
{
    char mes[] = "Hello, World!\0";
    int len;

    len = length(mes);

    line('*', len);
    
    printf("\nHello, World!\n");
    line('*',len);
    printf("\nДля завершения нажмите <Enter>");
    getch();
}

