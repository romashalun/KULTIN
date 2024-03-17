// Контур пятиконечной звезды
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#define PATHTODRIVER "c:\\borlandc\\bgi\\"

// контур пятиконечной звезды
#include "math.h"
void starline(int x0, int y0, int r)
{
    // x0,y0 - координаты центра звезды
    // r - радиус звезды

    int x,y;// координаты конца луча
            // или впадины
    int a;  // угол между осью ОХ и прямой,
            // соединяющей центр звезды и
            // конец луча или точку впадины
    int r1; // радиус окружности расположения
            // точек впадин

#define RTOR 2.5 // отношение радиуса лучей
                 // к радиусу впадин

    a = 18;    // строим от правого гор. луча
    r1 = r/RTOR;
    x = x0+r*cos(a*2*M_PI/360);
    y = y0-r*sin(a*2*M_PI/360);
    moveto(x,y);
    for (int i = 0; i < 5; i++)
    {
        a = a+36;
        x = x0+r1*cos(a*2*M_PI/360);
        y = y0-r1*sin(a*2*M_PI/360);
        lineto(x,y); // от луча к впадине
        a = a+36;
        if (a > 360)  a = 18;
        x = x0+r*cos(a*2*M_PI/360);
        y = y0-r*sin(a*2*M_PI/360);
        lineto(x,y); // от впадины к лучу
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
      exit(1);
   }

   starline(100, 100, 50);
   
   getch();
   closegraph(); // выход из графического режима
}

