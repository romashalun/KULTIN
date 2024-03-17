// Плывущий корабль
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

#define dx  5  // шаг сетки по Х
#define dy  5  // шаг сетки по Y

// Рисует кораблик
void ship(int x, int y, int color )
{
    // x,y - координаты базовой точки
    // color - цвет линий 

    setcolor(color);
    
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
    int x,y;  // координаты корабля (базовой точки)
    int maxx; // коорд. крайней правой точки экрана


    int gdriver = DETECT; // драйвер
    int gmode;            // режим
    int errorcode;        // код ошибки

    initgraph(&gdriver, &gmode, PATHTODRIVER);
    errorcode = graphresult();

    if (errorcode != grOk) // ошибка инициализации графического режима
    {
      printf("Ошибка: %d\n", errorcode);
      puts("Для завершения программы нажмите <Enter>");
      getch();
      return;
    }

    maxx = getmaxx();
    x = -10 ; // корабль выплывает из-за правой границы экрана
    y = 100;
    while ( x <  maxx)
    {
        ship(x,y, GREEN);  // нарисовать корабль
        delay(20);
        ship(x,y,BLACK);   // стереть корабль
        x += 5;
    }
    setcolor(GREEN);
    outtextxy(10,10,"Рейс завершен!");
    outtextxy(10,24,"Нажмите <Enter>");
    getch();
    closegraph(); // выход из графического режима
}

