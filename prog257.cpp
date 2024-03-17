// ����稢��� �奬� ४��ᨢ��� �����᪮� 楯�
#include <graphics.h>
#include <stdio.h>
#include <conio.h>

#define PATHTODRIVER "c:\\borlandc\\bgi\\"

// ����稢��� �奬� �.楯� �� �窨
// � ���न��⠬� x,y
void drcep(int k, int x, int y)
{
      #define dx 7 // 蠣 �⪨ �� X
      #define dy 7 // 蠣 �⪨ �� Y

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
   int k; // ���冷� 楯�

   int gdriver = DETECT; // �ࠩ���
   int gmode;            // ०��
   int errorcode;        // ��� �訡��

   initgraph(&gdriver, &gmode, PATHTODRIVER);
   errorcode = graphresult();

   if (errorcode == grOk)
   {
      printf("������ ���冷� 楯� -> ");
      scanf("%i", &k);
      drcep(k, 10, 50);

      outtextxy(10,200,
                "��� �����襭�� ������ <Enter>");
      getch();
      closegraph(); // ��室 �� ����᪮�� ०���
   }
   else
   {
      printf("�訡��: %d\n", errorcode);
      puts("��� �����襭�� ������ <Enter>");
      getch();
   }
}

