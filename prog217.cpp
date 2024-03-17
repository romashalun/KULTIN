// Функция length вычисляет длину строки символов
#include "stdio.h"
#include "conio.h"


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
    char st[80]; // строка
    int len;     // длина строки

    printf("Введите строку символов и нажмите <Enter>\n");
    printf("->");
    
    // если во введенной строке есть пробелы, то scanf
    // введет только часть строки - до первого пробела
    // поэтому будем использовать функцию gets 
    gets(st);
    len = length(st);

    printf("Длина введенной строки: %i",len);

    printf("\nДля завершения нажмите <Enter>");
    getch();
}

