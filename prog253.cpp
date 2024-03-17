// Выводит имена всех файлов программ
// предполагается, что первая строка
// файла - комментарий
#include <stdio.h>
#include <dir.h>
#include <string.h>
#include <conio.h>

// #define DEBUG  // режим отладки

// в качестве параметра программе передается
// имя каталога, список файлов которого надо вывести
void main(int argc, char *argv[])
{
   struct ffblk ffblk;  // информация о файле
   int done;
   FILE *in;   // файл программы

   int n;      // обработано файлов

   char mask[MAXPATH];
   char infile[MAXPATH];
   char outfile[MAXPATH];

   if (argc < 2)
   {
    puts("В командной строке не задан путь");
    puts("к обрабатываемым файлам");
    printf("Командная строка: %s path\\\n", argv[0]);
    return;
   }

   printf("\nПостроение списка файлов\n");

   // маска обрабатываемых файлов
   strcpy(mask, argv[1]);
   strcat(mask,"*.cpp");

   // файл-список обработанных файлов
   strcpy(outfile, argv[1]);
   strcat(outfile,"filelist.txt");

   printf("Обработка: %s",  mask);
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
        // читаем из файла первую строку
        char st[80];
        fgets(st, 80, in);
        printf("%s %s", infile, st);
        fclose(in);
      }
      done = findnext(&ffblk); // выбрать следующий файл
   }
   printf("\nОбработано файлов: %d\n", n);
   printf("Для завершения нажмите <Enter>");
   getch();
}

