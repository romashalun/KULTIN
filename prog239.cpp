// Часы с минутной и секундной стрелками
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <dos.h>

#define PATHTODRIVER "c:\\borlandc\\bgi\\"

// выводит вектор заданной длины из текущей точки
// используется для вывода изображения стрелки
void vector(int a,   //  угол между вектором и осью OX
            int l)  //  длина вектора
{
    #define G 0.0174532 // коэф. угла из градусов в радианы
    int x0,y0; //  координаты начала вектора
    int x1,y1; // координаты конца вектора

    x0 = getx();
    y0 = gety();
    x1 = x0 + l*cos(a*G);
    y1 = y0 - l*sin(a*G);
    lineto(x1,y1);
}

void clock()
{
    int x0 = 80,   // координаты центра часов
        y0 = 80;
    int d = 50;    // диаметр циферблата
    int s = 0;     // время, кол-во секунд
    int m = 0;     // время, кол-во минут
    int as = 90;   // угол наклона секундной стрелки
    int am = 90;   // угол наклона минутной стрелки

    circle(x0,y0,d+5);
    setfillstyle(SOLID_FILL, 0);
    do {
       // вывести секундную стрелку
       moveto(x0,y0);
       setcolor(YELLOW);
       vector(as,d);

       // вывести минутную стрелку
       moveto(x0,y0);
       setcolor(GREEN);
       vector(am,d-10);

       delay(1000); // задержка

       // стереть стрелки
       setcolor(0);
       // секундную
       moveto(x0,y0);
       vector(as,d);

       // минутную
       moveto(x0,y0);
       vector(am,d-10);

       s++;
       if (s > 60) {
         m++;
         s = 0;
         am -= 6; // шаг движения минутной стрелки 6 градусов
         if (am < 0)  am = 354;
       }
       as -= 6;
       if (as < 0)  as = 354;

     } while ( !kbhit() );
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
      clock();
      closegraph(); // выход из графического режима
   }
   else
   {
      printf("Ошибка: %d\n", errorcode);
      puts("Для завершения программы нажмите <Enter>");
      getch();
   }
}

