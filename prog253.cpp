// �뢮��� ����� ��� 䠩��� �ணࠬ�
// �।����������, �� ��ࢠ� ��ப�
// 䠩�� - �������਩
#include <stdio.h>
#include <dir.h>
#include <string.h>
#include <conio.h>

// #define DEBUG  // ०�� �⫠���

// � ����⢥ ��ࠬ��� �ணࠬ�� ��।�����
// ��� ��⠫���, ᯨ᮪ 䠩��� ���ண� ���� �뢥��
void main(int argc, char *argv[])
{
   struct ffblk ffblk;  // ���ଠ�� � 䠩��
   int done;
   FILE *in;   // 䠩� �ணࠬ��

   int n;      // ��ࠡ�⠭� 䠩���

   char mask[MAXPATH];
   char infile[MAXPATH];
   char outfile[MAXPATH];

   if (argc < 2)
   {
    puts("� ��������� ��ப� �� ����� ����");
    puts("� ��ࠡ��뢠��� 䠩���");
    printf("��������� ��ப�: %s path\\\n", argv[0]);
    return;
   }

   printf("\n����஥��� ᯨ᪠ 䠩���\n");

   // ��᪠ ��ࠡ��뢠���� 䠩���
   strcpy(mask, argv[1]);
   strcat(mask,"*.cpp");

   // 䠩�-ᯨ᮪ ��ࠡ�⠭��� 䠩���
   strcpy(outfile, argv[1]);
   strcat(outfile,"filelist.txt");

   printf("��ࠡ�⪠: %s",  mask);
   n = 0;

   done = findfirst(mask, &ffblk,0);
   while (!done)
   {  n++;
      #ifdef DEBUG
      printf("%s ", ffblk.ff_name);
      #endif
      strcpy(infile, argv[1]);
      strcat(infile,ffblk.ff_name);
      if ((in = fopen(infile, "rt")) != NULL)
      {
        // �⠥� �� 䠩�� ����� ��ப�
        char st[80];
        fgets(st, 80, in);
        printf("%s %s", infile, st);
        fclose(in);
      }
      done = findnext(&ffblk); // ����� ᫥���騩 䠩�
   }
   printf("\n��ࠡ�⠭� 䠩���: %d\n", n);
   printf("��� �����襭�� ������ <Enter>");
   getch();
}

