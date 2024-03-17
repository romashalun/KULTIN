// Функция compare возвращает результат сравнения чисел
// в виде символа отношения
#include "stdio.h"
#include "conio.h"

char compare(int a, int b)
{
    char res;
    if (a > b) res = '>';
       else if (a < b)  res = '<';
              else res = '=';
    return(res);
}

void main()
{
    int x1,x2;   // сравниваемые числа
    char res;    // результат сравнения

    puts("Введите два целых числа и нажмите <Enter>");
    printf("->");
    scanf("%i%i", &x1, &x2);
    res = compare(x1,x2);  // вызов функции программиста
    printf("%i %c %i\n", x1, res, x2);

    puts("\nДля завершения работы программы нажмите <Enter>");
    getch();
}

