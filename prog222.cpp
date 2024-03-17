// Российский флаг
#include <graphics.h>
#include <stdio.h>
#include <conio.h>

#define PATHTODRIVER "c:\\borlandc\\bgi\\"
void rusflag(int x, int y, int l, int h)
{
     // x, y - координаты левого верхнего угла
     // l, h - длина и высота флага
     int w = h / 3;

     // рисуем флаг
     setfillstyle(SOLID_FILL,WHITE);
     bar(x,y,x+l,y+w);
     setfillstyle(SOLID_FILL,BLUE);
     bar(x,y+w,x+l,y+2*w);
     setfillstyle(SOLID_FILL,RED);
     bar(x,y+2*w,x+l,y+3*w);
     outtextxy(x,y+h+5,"Россия\0");
}
void main(void)
{
   int gdriver = DETECT; // драйвер
   int gmode;            // режим
   int errorcode;        // код ошибки

   initgraph(&gdriver, &gmode, PATHTODRIVER);
   errorcode = graphresult();

   if (errorcode != grOk)  // ошибка инициализации граф. режима
   {
      printf("Ошибка: %d\n", errorcode);
      puts("Для завершения программы нажмите <Enter>");
      getch();
      return;
   }

    rusflag(100,100,50,25);

   getch();
   closegraph(); // выход из графического режима
}

