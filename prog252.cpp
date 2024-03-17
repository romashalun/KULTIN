// ������ᠫ쭠� �ணࠬ�� �஢�ન ������ 
// ��� 䠩�� ��� �������� � ������樨 ����᪠ �ணࠬ��
#include "stdio.h"
#include "conio.h"
#include "string.h"

void main(int argc, char* argv[])
{
    char fname[40]; // ��� 䠩�� ���
    FILE* f;        // 䠩� ���

    int VsegoVopr = 0; // ������⢮ ����ᮢ ���
    int PravOtv = 0;   // ������⢮ �ࠢ����� �⢥⮢

    // ��� ⥪�饣� �����
    int nOtv;     // ������⢮ ����ୠ⨢��� �⢥⮢
    int Prav;     // ����� �ࠢ��쭮�� �⢥�
    int Otv;      // ����� �⢥�, ��࠭���� ���짮��⥫��

    int p;        // ��業� �ࠢ����� �⢥⮢

    char st[80];  // ��ப� 䠩�� ���

    int i; // ���稪 横���

    if ( !argc )
    {
        puts("\n�� ����� 䠩� ����ᮢ ���!");
        puts("��������� ��ப�: test ���������\n");
        return;
    }

    strcpy(fname,argv[1]); // ��� 䠩�� �� ��������� ��ப�
    // ������ 䠩� � ०��� �⥭�� (r) ⥪�� (t)
    if ((f = fopen(fname, "rt")) == NULL)
    {
        printf("�訡�� ������ 䠩�� %s", fname);
        getch();
        return;
    }

    clrscr();
    puts("\n����� ��� �㤥� �।����� ���.");
    puts("� ������� ������ ������ ��᪮�쪮 ��ਠ�⮢ �⢥�.");
    puts("�� ������ ����� ����� �ࠢ��쭮�� �⢥�");
    puts("� ������ ������� <Enter>\n");

    printf
    ("��� ��砫� ���஢���� ������ <Enter>");
    getch();
    textbackground(BLUE);
    clrscr();

    while (!feof(f))
    {
      VsegoVopr++;
      fgets(st, 80, f);         // �⠥� �� 䠩�� �����
      printf("\n%s\n", st);     // ����� �� �࠭

      fscanf(f,"%i %i", &nOtv, &Prav);// ���-�� ��ਠ�⮢
                                      // �⢥�
                                      // � ����� �ࠢ. �⢥�
      fgets(st,80,f); // ������ ����� �।��饩 ��ப�

      //�⠥� � �뢮��� ����ୠ⨢�� �⢥��
      for (i = 1; i <= nOtv; i++)
      {
            fgets(st, 80, f);
            printf("%i. %s", i, st);
      }
      printf("\n��� �롮� ->");
      scanf("%i", &Otv);
      if (Otv == Prav)  PravOtv++;
    }

    // ��ࠡ�⪠ १���� ���஢����
    // ���᫨� ���� �ࠢ����� �⢥⮢
    p = 100 * PravOtv / VsegoVopr;
    printf("\n��� �業�� - ");
    if (p == 100) puts("�������!");
    if (p >= 99 && p <= 80) puts("������.");
    if (p >= 60 && p <= 79) puts("�����������������.");
    if (p < 60) puts("�����!\n");

    puts("\n��� �����襭�� ������ <Enter>");
    getch();
}

