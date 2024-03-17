// Шахматная доска
#include <graphics.h>
#include <stdio.h>
#include <conio.h>

#define PATHTODRIVER "c:\\borlandc\\bgi\\"
// шахматная доска
void doska()
{
    int x0 = 100,   // координаты левого верхнего угла доски
        y0 = 100;
    int x,y;        // координаты левого верхнего угла клетки
    int w = 25;     // размер клетки
    int i,j;        // номер строки и колонки

    x = x0;
    y = y0;
    for (i = 0; i < 8; i++)   // восемь строк
    {
        for ( j = 0; j < 8; j++) // восемь клеток в строке
       {
           // если сумма номера строки и номера
           // колонки, на пересечении которых находится
           // клетка, четная, то клетка - коричневая,
           //    иначе - желтая
           if ((i+j) % 2)
              setfillstyle(SOLID_FILL,BROWN);
           else setfillstyle(SOLID_FILL,YELLOW);
           bar(x,y,x+w,y+w);
           x += w;
       }
       x = x0;
       y += w;
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

   doska();

   getch();
   closegraph(); // выход из графического режима
}

