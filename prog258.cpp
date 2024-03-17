// Кривая Гильберта

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
#define PATHTODRIVER "c:\\borlandc\\bgi\\"

#define DT  3  // задержка при выводе диний по точкам
#define u 10   // величина штриха кривой Гильберта

void Gilbert(int p); // вычерчивает кривую Гильберта

void main(void)
{
   int gdriver = DETECT; // драйвер
   int gmode;            // режим
   int errorcode;        // код ошибки

   initgraph(&gdriver, &gmode, PATHTODRIVER);
   errorcode = graphresult();

   if (errorcode == grOk) {
      outtextxy(10,10,"Кривая Гильберта ...");
      Gilbert(4);
      outtextxy(10,25,"Для завершения нажмите <Enter>");
      getch();
      closegraph();
   }
   else {
      printf("Ошибка: %d\n", errorcode);
      printf("\Для завершения программы нажмите <Enter>");
      getch();
   }
}

// Кривая Гильберта состоит из четырех элементов: a,b,c и d.
// Каждый элемент строит соответствующая функция.
void a(int i);
void b(int i);
void c(int i);
void d(int i);

void my_lineto(int x2, int y2); // вычерчивает по точкам линию

void Gilbert(int p) // p - порядок кривой Гильберта
{
   moveto(450,50);
   a(p);
}

// Элементы кривой.
void a(int i)
{
    if (i > 0) {
      d(i-1); my_lineto(getx() - u, gety());
      a(i-1); my_lineto(getx(), gety() + u);
      a(i-1); my_lineto(getx() + u, gety());
      b(i-1);
    }
}

void b(int i)
{
   if (i > 0)
   {
      c(i-1); my_lineto(getx(),gety() - u);
      b(i-1); my_lineto(getx() + u, gety());
      b(i-1); my_lineto(getx(),gety() + u);
      a(i-1);
   }
}

void c(int i)
{
   if (i > 0) {
      b(i-1); my_lineto(getx() + u,gety());
      c(i-1); my_lineto(getx(), gety() - u);
      c(i-1); my_lineto(getx() - u,gety());
      d(i-1);
   }
}

void d(int i )
{
   if (i > 0) {
      a(i-1); my_lineto(getx(),gety() + u);
      d(i-1); my_lineto(getx() - u,gety());
      d(i-1); my_lineto(getx(),gety() - u);
      c(i-1);
   }
}

// вычерчивает по точкам линию
void my_lineto(int x2, int y2)
{
    int x1,y1;  // координаты начала прямой
                // x2,y2 -  координаты конца
    int x,y;    // координаты текущей точки
    int dx;     // приращение аргумента
    int dy;     // приращение y при рисовании
                // вертикальной линии
    int color;  // цвет линии
    int a,b;    // коэффициенты уравнения прямой
    int n;      // кол-во точек
    int i;

    x1 = getx();
    y1 = gety();
    if ( x1 != x2 )
    {
      // не вертикальная линия
      a = (y2-y1)/(x2-x1);
      b = y1- a * x1;
      n = abs(x2-x1)+1;
      if (x2 > x1)
        dx = 1;
      else dx = -1;
      x = x1;
      color = getcolor();
      for (i = 1; i<= n; i++)
      {
        y = a*x + b;
        putpixel(x,y,color);
        delay(DT);
        x += dx;
      }
    }
    else { //  вертикальная линия
       n = abs(y2-y1);
       if (y2 > y1)
          dy = 1;
       else dy = -1;
          x = x1;
       y = y1;
       color = getcolor();
       for (i = 1; i<=n; i++)
       {
           putpixel(x, y, color);
           delay(DT);
           y += dy;
       }
    }
    putpixel(x2, y2, color);
    moveto(x2, y2);
}

