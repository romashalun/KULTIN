// Функция upcase
#include "stdio.h"
#include "conio.h"

// функция преобразования строчных букв в прописные
char* upcase(char *st)
{
    int i = 0;
    while ( st[i] )
    {
        if (st[i] >= 'a' && st[i] <= 'z' ||   // латинские
                st[i] >= 'а' && st[i] <= 'п')  // русские
            st[i] -= 32;
        else if (st[i] >= 'р' && st[i] <= 'я')
                st[i] -= 80;
        i++;
    }
    return st;
}

//  пример использования функции upcase
void main()
{
    char st[80];

    puts(" Введите строку текста и нажмите <Enter>");
    printf("->");
    gets(st);
    puts(upcase(st));

    puts("\nДля завершения нажмите <Enter>");
    getch();
}

