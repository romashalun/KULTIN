// Оцифрованные координатные оси
#include <graphics.h>
#include <stdio.h>
#include <conio.h>

#define PATHTODRIVER "c:\\borlandc\\bgi\\"

void grid()
{
    int x0,y0; // координаты начала координатных осей
    int dx,dy; // шаг координатной сетки (в пикселях)
    int h,w;   // высота и ширина области вывода
               // координатной сетки
    int x,y;

    float lx,ly;    // метки линий сетки по X  Y
    float dlx,dly;  // шаг меток линий сетки по X и Y
    char st[8];     // изображение метки линии сетки

    x0 = 50; y0 = 400; // оси начинаются в точке (50,400)
    dx = 40; dy = 40;  // шаг координатной сетки 40 пикселей
    dlx = 0.5;        // шаг меток оси X
                      // метками будут: 0.5, 1.0, 1.5 ...
    dly = 1;          // шаг меток оси Y
                      // метками будут: 1, 2, 3 ...
    h = 300;
    w = 400;

    lx = 0;           // начало координат помечается метками 0
    ly = 0;

    line(x0,y0,x0,y0-h);  // ось X
    line(x0,y0,x0+w,y0);  // ось Y

    // засечки, сетка и оцифровка по оси X
    x = x0;
    do {
        // засечка
        setlinestyle(SOLID_LINE, 0, 1);
        line(x,y0-3,x,y0+3);
        // оцифровка
        sprintf(st,"%2.1f",lx);
        outtextxy(x-8,y0+5,st);
        lx += dlx;
        // линия сетки
        setlinestyle(DOTTED_LINE, 0, 1);
        line(x,y0-3,x,y0-h);
        x += dx;
    } while (x < x0+w);

    // засечки, сетка и оцифровка по оси Y
    y = y0;
    do {
        // засечка
        setlinestyle(SOLID_LINE, 0, 1);
        line(x0-3,y,x0+3,y);
        // оцифровка
        sprintf(st,"%2.1f",ly);
        outtextxy(x0-40,y,st);
        ly += dly;
        // линия сетки
        setlinestyle(DOTTED_LINE, 0, 1);
        line(x0+3,y,x0+w,y);
        setlinestyle(SOLID_LINE, 0, 1);
        y -= dy;
    } while (y > y0-h);
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

   grid();

   getch();
   closegraph(); // выход из графического режима
}

