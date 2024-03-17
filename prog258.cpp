// �ਢ�� ���졥��

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
#define PATHTODRIVER "c:\\borlandc\\bgi\\"

#define DT  3  // ����প� �� �뢮�� ����� �� �窠�
#define u 10   // ����稭� ���� �ਢ�� ���졥��

void Gilbert(int p); // ����稢��� �ਢ�� ���졥��

void main(void)
{
   int gdriver = DETECT; // �ࠩ���
   int gmode;            // ०��
   int errorcode;        // ��� �訡��

   initgraph(&gdriver, &gmode, PATHTODRIVER);
   errorcode = graphresult();

   if (errorcode == grOk) {
      outtextxy(10,10,"�ਢ�� ���졥�� ...");
      Gilbert(4);
      outtextxy(10,25,"��� �����襭�� ������ <Enter>");
      getch();
      closegraph();
   }
   else {
      printf("�訡��: %d\n", errorcode);
      printf("\��� �����襭�� �ணࠬ�� ������ <Enter>");
      getch();
   }
}

// �ਢ�� ���졥�� ��⮨� �� ����� ����⮢: a,b,c � d.
// ����� ����� ��ந� ᮮ⢥������� �㭪��.
void a(int i);
void b(int i);
void c(int i);
void d(int i);

void my_lineto(int x2, int y2); // ����稢��� �� �窠� �����

void Gilbert(int p) // p - ���冷� �ਢ�� ���졥��
{
   moveto(450,50);
   a(p);
}

// �������� �ਢ��.
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

// ����稢��� �� �窠� �����
void my_lineto(int x2, int y2)
{
    int x1,y1;  // ���न���� ��砫� ��אַ�
                // x2,y2 -  ���न���� ����
    int x,y;    // ���न���� ⥪�饩 �窨
    int dx;     // ���饭�� ��㬥��
    int dy;     // ���饭�� y �� �ᮢ����
                // ���⨪��쭮� �����
    int color;  // 梥� �����
    int a,b;    // �����樥��� �ࠢ����� ��אַ�
    int n;      // ���-�� �祪
    int i;

    x1 = getx();
    y1 = gety();
    if ( x1 != x2 )
    {
      // �� ���⨪��쭠� �����
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
    else { //  ���⨪��쭠� �����
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

