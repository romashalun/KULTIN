// Узор из линий
// случайного цвета
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "time.h"

#define PATHTODRIVER "c:\\borlandc\\bgi\\"

// узор из линий
void luzor(int n)
{
    int x,y;   // координаты конца линии
    int c;     // цвет линии
    time_t t;

    srand((unsigned)time(&t)); // инициализация ГСЧ
    for (int i = 0; i < n; i++)
    {

        x = rand() % 640;
        y = rand() % 480;
        c = rand() % 16;
        setcolor(c);
        lineto(x,y);
     }
}

void main(void)
{
   int gdriver = DETECT; // драйвер
   int gmode;            // режим
   int errorcode;        // код ошибки

   initgraph(&gdriver, &gmode, PATHTODRIVER);
   errorcode = graphresult();

   if (errorcode != grOk)  // ошибка инициализации граф.режима
   {
      printf("Ошибка: %d\n", errorcode);
      puts("Для завершения программы нажмите <Enter>");
      getch();
      exit(1);
   }

   luzor(200); // узор из окружностей

   getch();
   closegraph(); // выход из графического режима
}

