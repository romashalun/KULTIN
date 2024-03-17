// ������ ᮯ�⨢�����
// ४��ᨢ��� n-������� �����᪮� 楯�
#include <stdio.h>
#include <conio.h>

float r1,r2,r3; // ����稭� ᮯ�⨢�����,
                // �� ������ ��⮨� 楯�

// ������ ᮯ�⨢����� 楯� n-�� ���浪�
float rcep(int n)
{
   float r; // ᮯ�⨢����� 楯� (n-1)-�� ���浪�

   if (n == 1)
      return(r1 + r2 + r3);
   else
   {
      r = rcep(n-1);
      return (r1 + r2*r/(r2+r) + r3);
   }
}

void main()
{
     int n;          // ������⢮ ����쥢 (���冷�) 楯�
     float rc;       // ᮯ�⨢����� 楯�

     puts("\n���᫥��� ᮯ�⨢����� �����᪮� 楯�");
     puts("������ ����稭� ᮯ�⨢����� (��):");
     printf("r1 ->");
     scanf("%f", &r1);
     printf("r2 ->");
     scanf("%f", &r2);
     printf("r3 ->");
     scanf("%f", &r3);
     printf("���冷� 楯� ->");
     scanf("%i", &n);

     rc = rcep(n);// ����稭� ᮯ�⨢����� ��।�����
                  // �㭪樨 rcep �१ �������� ��६����

     printf("����⨢����� 楯�:");
     if (rc > 100)
     {
         rc /= 1000;
         printf("%5.2f ���\n", rc);
     }
     else
         printf("%5.2f ��\n", rc);

     puts("\n��� �����襭�� ������ <Enter>");
     getch();
}

