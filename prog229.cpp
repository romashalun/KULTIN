// Узор из квадратов
#include <graphics.h>
#include <stdio.h>
#include <conio.h>

#define PATHTODRIVER "c:\\borlandc\\bgi\\"
// узор из квадратов
void uzor()
{
    int x;
    int y = 100; 
    int n;        // количество квадратов в ряду
    int d = 30;   // размер квадрата
    int l = 10;   // расстояние между квадратами
    for (int i = 0; i < 5; i++)
    {
        // для ряда определим координату X
        if (i % 2)
        {  // нечетный ряд
            n = 5;   // пять квадратов в ряду
            x = 100;
        }
        else { // четный ряд
            n = 4;
            x = 100 + d/2+l/2;
        }
        for (int j = 0; j < n; j++)
        {
            rectangle(x,y,x+d,y+d);
            x += d+l;
        }
        y += d/2+l/2;
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
      return;
   }

   uzor();

   getch();
   closegraph(); // выход из графического режима
}

