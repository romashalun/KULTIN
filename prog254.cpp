// �����ᨢ��� �㭪�� "����ਠ�"
#include "stdio.h"
#include "conio.h"

unsigned int factor(unsigned int k)
{
    if ( k == 1 )
        return(1);
    else
        return(k*factor(k-1));
}

void main()
{
    unsigned int n; // �᫮, 䠪�ਠ� ���ண� ���� ���᫨��
    unsigned int f; // 䠪�ਠ� �᫠ n

    puts("���᫥��� 䠪�ਠ��\n");
    puts("������ �᫮, 䠪�ਠ� ���ண� ���� ���᫨��");
    printf("->");
    scanf("%u", &n);
    f = factor(n);
    printf("����ਠ� �᫠ %u ࠢ�� %u", n, f);

    printf("\n��� �����襭�� ������ <Enter>");
    getch();
}

