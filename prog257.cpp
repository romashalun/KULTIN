// Вычерчивает схему рекурсивной электрической цепи
#include <graphics.h>
#include <stdio.h>
#include <conio.h>

#define PATHTODRIVER "c:\\borlandc\\bgi\\"

// вычерчивает схему эл.цепи от точки
// с координатами x,y
void drcep(int k, int x, int y)
{
      #define dx 7 // шаг сетки по X
      #define dy 7 // шаг сетки по Y

      setcolor(GREEN);
      line(x,y,x+2*dx,y);
      rectangle(x+2*dx,y-dy,x+6*dx,y+dy);
      line(x+6*dx,y,x+8*dx,y);
      outtextxy(x+3*dx,y-3*dy,"R1");

      setcolor(YELLOW);
      line(x+8*dx,y,x+8*dx,y+2*dy);
      rectangle(x+7*dx,y+2*dy,x+9*dx,y+6*dy);
      line(x+8*dx,y+6*dy,x+8*dx,y+8*dy);
      outtextxy(x+10*dx,y+2*dy,"R2");

      setcolor(LIGHTGRAY);
      line(x,y+8*dy,x+2*dx,y+8*dy);
      rectangle(x+2*dx,y+7*dy,x+6*dx,y+9*dy);
      line(x+6*dx,y+8*dy,x+8*dx,y+8*dy);
      outtextxy(x+3*dx,y+5*dy,"R3");

      if ( k > 1 )  drcep(k-1, x+8*dx, y);
}

void main(void)
{
   int k; // порядок цепи

   int gdriver = DETECT; // драйвер
   int gmode;            // режим
   int errorcode;        // код ошибки

   initgraph(&gdriver, &gmode, PATHTODRIVER);
   errorcode = graphresult();

   if (errorcode == grOk)
   {
      printf("Введите порядок цепи -> ");
      scanf("%i", &k);
      drcep(k, 10, 50);

      outtextxy(10,200,
                "Для завершения нажмите <Enter>");
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

