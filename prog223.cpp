// Рисует кораблик (с использованием метода базовой точки)
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#define dx  10  // шаг сетки по Х
#define dy  10  // шаг сетки по Y

void ship(int x, int y) // x,y - координаты базовой точки
{
    //  корпус
    moveto(x,y);
    lineto(x,y-2*dy);
    lineto(x+10*dx,y-2*dy);
    lineto(x+11*dx,y-3*dy);
    lineto(x+17*dx,y-3*dy);
    lineto(x+14*dx,y);
    lineto(x,y);
    // надстройка
    moveto(x+3*dx,y-2*dy);
    lineto(x+4*dx,y-3*dy);
    lineto(x+4*dx,y-4*dy);
    lineto(x+13*dx,y-4*dy);
    lineto(x+13*dx,y-3*dy);
    line(x+5*dx,y-3*dy,x+9*dx,y-3*dy);
    // капитанский мостик
    rectangle(x+8*dx,y-4*dy,x+11*dx,y-5*dy);
    // труба
    rectangle(x+7*dx,y-4*dy,x+8*dx,y-7*dy);
    // иллюминаторы
    circle(x+12*dx,y-2*dy,dx/2);
    circle(x+14*dx,y-2*dy,dx/2);
    // мачта
    line(x+10*dx,y-5*dy,x+10*dx,y-10*dy);
    // оснастка
    moveto(x+17*dx,y-3*dy);
    lineto(x+10*dx,y-10*dy);
    lineto(x,y-2*dy);
}

#define PATHTODRIVER "c:\\borlandc\\bgi\\"

void main(void)
{
    int gdriver = DETECT; // драйвер
    int gmode;            // режим
    int errorcode;        // код ошибки

    initgraph(&gdriver, &gmode, PATHTODRIVER);
    errorcode = graphresult();

    if (errorcode != grOk) // ошибка инициализации граф. режима
    {
      printf("Ошибка: %d\n", errorcode);
      puts("Для завершения программы нажмите <Enter>");
      getch();
      exit(1);
    }

    ship(50,150);
    getch();
    closegraph(); // выход из графического режима
}

