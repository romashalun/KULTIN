// График функции
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

#define PATHTODRIVER "c:\\borlandc\\bgi\\"

// функции, график которых надо построить
float f1(float x)
{
    return(2 * sin(x) * exp(x/5));
}

void grafik()
{
    float x1=0,   // границы изменения аргумента функции
          x2=25;
    float y1,y2;  // границы изменения значения функции
    float x;      // аргумент функции
    float y;      // значение функции в точке x
    float dx=0.01;   // приращение аргумента
    int l=50,     // левый нижний угол области графика
        b=400;
    int w=300,    // ширина и высота области графика
        h=200;
    float mx,my;  // масштаб по осям X и Y
    int x0,y0;    // точка - начало координат
    char st[25];  // изображение числа

    // найдем максимальное и минимальное значение
    // функций на отрезке [x1,x2]
    y1 = f1(x1); // минимум
    y2 = f1(x1); // максимум
    x = x1 + dx;
    do {
        y = f1(x);
        if (y < y1)  y1 = y;
        if (y > y2)  y2 = y;
        x += dx;
    } while (x <= x2);

    // вычислим масштаб по осям
    my = h/fabs(y2-y1);
    mx = w/fabs(x2-x1);
    // оси
    x0 = l;
    y0 = b-abs(y1*my);
    line(l,b,l,b-h);
    line(x0,y0,x0+w,y0);
    // максимальное и минимальное значение функции
    sprintf(st,"%3.2f",y2);
    outtextxy(l+5,b-h,st);
    sprintf(st,"%3.2f",y1);
    outtextxy(l+5,b,st);
    // построение графика
    x = x1;
    do {
        y = f1(x);
        putpixel(x0+x*mx,y0-y*my,15);
        x += dx;
    } while (x <= x2);
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
        grafik();
        getchar();
        closegraph();
   }
   else {
      printf("Ошибка: %d\n", errorcode);
      puts("Для завершения программы нажмите <Enter>");
      getch();
   }
}

