// Вычисляет среднее арифметическое чисел,
// находящихся в файлах
#include "stdio.h"
#include "conio.h"

#define FNAME "numbers.txt\0" // имя файла

void main()
{
     char fname[20] = FNAME;
     FILE *f;     // текстовый файл

     int a;       // число
     int n = 0;   // количество чисел
     int sum = 0; // сумма чисел
     float sr;    // среднее арифметическое

     puts("\nВычисление среднего арифметического");
     printf("чисел, находящихся в файле %s", fname);

     // Открыть файл в режиме чтения (r) текста (t)
     if ((f = fopen(fname, "rt")) == NULL)
     {
        printf("Ошибка открытия файла для чтения");
        getch();
        return;
     }

     while (!feof(f))
     {
        fscanf(f,"%i", &a);
        sum += a;
        n++;
     }
     fclose(f);     // закрыть файл

     sr = (float) sum / n;
     printf("Введено чисел: %i\n", n);
     printf("Сумма чисел: %i\n", sum);
     printf("Среднее арифметическое: %3.2f", sr);

     puts("\nДля завершения нажмите <Enter>");
     getch();
}

