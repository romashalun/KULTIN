// �஢����, ���� �� ��������� ��ப�
//  ��⭠������ �᫮�
#include <stdio.h>
#include <conio.h>
#include "string.h"
void main()
{
    char st[20];  // ��ப�
    int i;        // ����� �஢��塞��� ᨬ����

    printf("\n������ ��⭠����筮� �᫮ ->");
    scanf("%s", &st);

    strupr(st); // �८�ࠧ㥬 � ���孥�� ॣ�����

    i = 0;
    while ((st[i] >= '0' && st[i] <= '9') ||
       (st[i] >= 'A' && st[i] <= 'F'))
      i++;

    printf("C�ப� ");
    // �᫨ st[i] != '\0',
    // � i - ����� ��ࢮ�� �訡�筮�� ᨬ����
    if ( st[i] )
      printf("�� ");
    printf("���� ��⭠������ �᫮�.\n");

    printf("\n��� �����襭�� ������ <Enter>");
    getch();
}

