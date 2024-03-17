// Функции getfloat и pos
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define PATHTODRIVER "c:\\borlandc\\bgi\\"

// возвращает позицию символа в строке
int pos(char* st, char c)
{
    int i = 0;
    while ( st[i] != c && st[i] )
        i++;
    if ( st[i] )
        return(i+1);
    else
        return(0);
}

// вводит дробное число
float getfloat()
{
    #define N 10 // кол-во символов, включая точку и минус
    char ch;
    char buf[N+1];
    int i;

    for (i = 0; i < N+1; i++)
        buf[i++] ='\0';
    i = 0;
    do {
        ch=getch();
        if (ch >= '0' && ch <= '9' && i < 8) {
            putch(ch);
            buf[i++] = ch;
        }
        else
             switch (ch) {
                case '-' : if (!i)
                           {
                              putch(ch);
                              buf[i++] = ch;
                           }
                           break;
                case '.' : if ( !(pos(buf,'.')))
                           {
                              putch(ch);
                              buf[i++] = ch;
                           }
                           break;
                case 8   : if (i)
                            {
                                printf("\b \b");
                                buf[--i] = '\0';
                            }
             }
   } while (ch != 13);
   return(atof(buf));
}

void main(void)
{
   float f;

   printf("Введите дробное число ->");
   f = getfloat();
   printf("\nВведено число %e\n", f);
   getch();
}

