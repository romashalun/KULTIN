// Узор из окружностей
//  случайного радиуса и цвета
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "time.h"
#include "dos.h"

#define PATHTODRIVER "c:\\borlandc\\bgi\\"

// узор из окружностей
void cuzor(int n)
{
    #define DELAY  // задержка между выводом окружностей
    int x,y,r; // координаты центра и радиус окружности
    time_t t;

    srand((unsigned)time(&t)); // инициализация ГСЧ
    for (int i = 0; i < n; i++)
    {
        x = rand() % 640;
        y = rand() % 480;
        r = rand() % 240;
        setcolor(rand() %16);
        circle(x,y,r);
        #ifdef DELAY
        delay(5);
        #endif
    }
}

void main(void)
{
   int gdriver = DETECT; // драйвер
   int gmode;            // режим
   int errorcode;        // код ошибки

   initgraph(&gdriver, &gmode, PATHTODRIVER);
   errorcode = graphresult();

   if (errorcode != grOk)  // ошибка инициализации графического режима
   {
      printf("Ошибка: %d\n", errorcode);
      puts("Для завершения программы нажмите <Enter>");
      getch();
      exit(1);
   }

   cuzor(200); // узор из окружностей

   getch();
   closegraph(); // выход из графического режима
}

