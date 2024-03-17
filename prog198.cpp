// Вычисление значения арифметического выражения
#include <stdio.h>
#include <conio.h>
#include "stdlib.h"
void main()
{
   char st[40];  // строка
   char buf[10]; // изображение очередного числа
   char op;      // оператор
   int rez;      // значение выражения
   int n;        // очередное число

   int i,j;

   printf("\nВведите арифметическое выражение,\n");
   printf("например, 45+5-3-125+2 и нажмите <Enter>");
   printf("(пробелы и другие знаки недопустимы)\n");
   printf("->");
   scanf("%s", &st);

   rez = 0; // значение выражения
   op = ' ';
   i = j = 0;
   while( st[i] )
   {
      // выделить число
      j = 0;
      while (st[i] >= '0' && st[i] <= '9')
         buf[j++] = st[i++];
      buf[j] = '\0';
      n = atoi(buf); // преобразовать строку в целое

      // выполнить действие
      switch ( op )
      {
        case '+': rez += n; break;
        case '-': rez -= n; break;
        case ' ': rez = n;  break; // первое число примера
      }

      // выделить знак операции
      op = st[i++];
   }
   printf("Значение введенного выражения: %d", rez);
   printf("\nДля завершения нажмите <Enter>");
   getch();

