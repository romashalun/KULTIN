// Пятиконечная звезда
#include <graphics.h>
#include <stdio.h>
#include <conio.h>

#define PATHTODRIVER "c:\\borlandc\\bgi\\"

// пятиконечная звезда
#include "math.h"
void star(int x0, int y0, int r)
{
    // x0,y0 - координаты центра звезды
    // r - радиус звезды

    int poly[20]; // координаты концов лучей
                  // и впадин
    int a;  // угол между осью ОХ и прямой,
            // соединяющей центр звезды и
            // конец луча или точку впадины
    int r1; // радиус окружности расположения
            // точек впадин

#define RTOR 2.5 // отношение радиуса лучей
                 // к радиусу впадин

    int i;
    a = 18;    // строим от правого гор. луча
    r1 = r/RTOR;
    i=0;
    do {
        poly[i++] = x0+r*cos(a*2*M_PI/360);
        poly[i++] = y0-r*sin(a*2*M_PI/360);
        a = a+36;
        poly[i++] = x0+r1*cos(a*2*M_PI/360);
        poly[i++] = y0-r1*sin(a*2*M_PI/360);
        a = a+36;
        if (a > 360)  a = 18;
    } while(i < 20);
    setfillstyle(SOLID_FILL,RED);
    fillpoly(10,poly);
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
   }
   else {
      star(100, 100, 20);
      getch();
      closegraph(); // выход из графического режима
   }
}

