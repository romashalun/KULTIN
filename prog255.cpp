// �����ᨢ�� 㧮� �� ���㦭��⥩
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

#define PATHTODRIVER "c:\\borlandc\\bgi\\"

// ����� 㧮�
void elem(int x, int y, int r, int p)
{
     // x,y,r - ���न���� � ࠤ��� 業��
     //            �᭮����� ����� 㧮�
     // p - ���冷� 㧮�

     if ( p )
     {
        circle(x, y, r);
        delay(100);
        elem(x+r, y,   r/2, p-1);
        elem(x,   y-r, r/2, p-1);
        elem(x-r, y,   r/2, p-1);
        elem(x,   y+r, r/2, p-1);
    }
}

void main(void)
{
   int gdriver = DETECT; // �ࠩ���
   int gmode;            // ०��
   int errorcode;        // ��� �訡��

   initgraph(&gdriver, &gmode, PATHTODRIVER);
   errorcode = graphresult();

   if (errorcode == grOk)
   {
        elem(320, 240, 60, 5); // ��㥬 㧮� 5-�� ���浪�
        outtext("��� �����襭�� ������ <Enter>");
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

