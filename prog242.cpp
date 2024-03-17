// добавляет данные в файл
#include "stdio.h"
#include "conio.h"

#define FNAME " numbers.txt\0" // имя файла
#define N 3                    // количество чисел

// Дописывает в находящийся на диске файл numbers.txt 
// целые числа, введенные пользователем
void main()
{
     char fname[20] = FNAME;
     FILE *f;     // файл чисел
     int n;       // число

     puts("\nДобавление в файл");
     printf("Веденные числа будут добавлены в файл %s\n",
             fname);
     puts("После ввода каждого числа нажимайте <Enter>\n");

     // Открыть файл в режиме добавления (а) текста (t)
     // Если файла с таким именем нет, то он будет создан
     if ((f = fopen(fname, "at")) == NULL)
     {
        printf("Ошибка открытия файла для добавления");
        getch();
        return;
     }

     for (int i = 0; i < N; i++)
     {
        printf("->");
        scanf("%i", &n);
        fprintf(f,"%i\n",n);
    }
    fclose(out);     // закрыть файл
    printf("Введенные числа добавлены в файл %s\n", fname);
    puts("\nДля завершения нажмите <Enter>");
    getch();
}

