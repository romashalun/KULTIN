// Функция getint
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

//  Функция getint предназначена для ввода целого положительного
//  числа, состоящего из одной или двух цифр. Во время ввода,
//  для редактирования, может использоваться <Backspace>.
//  При нажатии <Enter> функция возвращает введенное число.

#define K_BACK  8   // код клавиши <Backspace>
#define K_ENTER 13  // код клавиши <Enter>
#define HB      4   // допустимое количество цифр
int getint()
{
  char ch;      // текущий символ
  char buf[HB];  // введенные цифры
  int n = 0;    // кол-во введенных цифр

  buf[0] = '\0';
  while ((ch = getch()) != K_ENTER)
        if (ch >= '0' && ch <= '9'&& n < HB)
        {    putch(ch);
            buf[n++] = ch;
        }
        else if (ch == K_BACK && n)
             {
                printf("\b \b");
                n--;
             }
  if (n)
  {
    buf[n] = '\0';
    return(atoi(buf));
  }
  else return(-1);
}

void main() {
  
  int a; // введенное число

  puts("\nДемонстрация работы функции getint\n");

  puts("Функция getint обеспечивает ввод ");
  puts("целого положительного числа.");
  puts("Во время ввода для редактирования может");
  puts("использоваться клавиша <Backspace>");
  puts("При нажатии <Enter> функция возвращает");
  puts("введенное число или -1, если число не введено.");

  puts("Введите число и нажмите <Enter>");
  printf("->");
  if (a = getint())
        printf("\nВы ввели число %d", a);
  else puts("Число не введено.");

  puts("\nДля завершения нажмите <Enter>");
  getch();
}

