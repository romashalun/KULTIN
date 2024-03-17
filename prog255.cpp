// Рекурсивный узор из окружностей
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

#define PATHTODRIVER "c:\\borlandc\\bgi\\"

// элемент узора
void elem(int x, int y, int r, int p)
{
     // x,y,r - координаты и радиус центра
     //            основного элемента узора
     // p - порядок узора

     if ( p )
     {
        circle(x, y, r);
        delay(100);
        elem(x+r, y,   r/2, p-1);
        elem(x,   y-r, r/2, p-1);
        elem(x-r, y,   r/2, p-1);
        elem(x,   y+r, r/2, p-1);
    }
}

void main(void)
{
   int gdriver = DETECT; // драйвер
   int gmode;            // режим
   int errorcode;        // код ошибки

   initgraph(&gdriver, &gmode, PATHTODRIVER);
   errorcode = graphresult();

   if (errorcode == grOk)
   {
        elem(320, 240, 60, 5); // рисуем узор 5-го порядка
        outtext("Для завершения нажмите <Enter>");
        getch();
        closegraph(); // выход из графического режима
   }
   else
   {
      printf("Ошибка: %d\n", errorcode);
      puts("Для завершения нажмите <Enter>");
      getch();
   }
}

