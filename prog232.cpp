// График функции
#include <graphics.h>
#include <stdio.h>
#include <conio.h>

#define PATHTODRIVER "c:\\borlandc\\bgi\\"

void grafik()
{
    float x,dx;   // аргумент и его приращениение
    float x1,x2;  // диапазон изменения аргумента
    float y;      // значение функции
    int mx,my;    // масштаб по X и Y - кол-во точек
                  // экрана, соответствующее единице
                  // по осям координат
    int x0,y0;    // начало осей координат
    int px,py;    // координаты точки графика на экране

    x0 = 320; y0 = 240;
    mx = 20; my = 20;
    // оси координат
    line(10,y0,630,y0);
    line(x0,10,x0,470);
    // график
    x1 = -15;
    x2 = 5;
    dx = 0.1;
    x = x1;
    while ( x < x2 )
    {
        y =  0.5*x*x + x*4 - 3;  // функция
        px = x0 + x*mx;
        py = y0 - y*my;
        putpixel(px,py,WHITE);
        x += dx;
    }
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

   grafik();

   getch();
   closegraph(); // выход из графического режима
}

