// Выводит на экран содержимое файла
#include "stdio.h"
#include "conio.h"

#define FNAME "numbers.txt\0" // имя файла

void main()
{
     char fname[20] = FNAME;
     FILE *f;     // текстовый файл
     char st[80];  // строка из файла

     printf("\nСодержимое файла %s\n", fname);
     puts("---------------------------------");

     // Открыть файл в режиме чтения (r) текста (t)
     if ((f = fopen(fname, "rt")) == NULL)
     {
        printf("Ошибка открытия файла для чтения");
        getch();
        return;
     }

     while (!feof(а))
     {
        fscanf(f,"%s", &st);
        printf("%s\n", st);
     }
     fclose(f);     // закрыть файл
     
     puts("---------------------------------");
     puts("\nДля завершения нажмите <Enter>");
     getch();
}

