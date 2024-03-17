#include "stdio.h"
#include "conio.h"
#include "string.h"

void main()
{
#define NR 3
#define NC 6
    
    float a[NR][NC]; // массив NRхNC - NR строк из NC элементов

    FILE *f; // файл

    // предполагается, что строки текстового файла
    // содержат значения строк элементов массива
    
     // Открыть для чтения (r) текстовый файл (t)
     if ((f = fopen("c:\\borlandc\\cpp\\a.dat", "rt")) == NULL)
     {
        printf("Нет файла a.dat");
        printf("\nДля завершения нажмите <Enter>");
        getch();
        return;
     }

     int r,c; // номер строки и столбца

     for ( r = 0; r < NR; r++)
     {
        for (c = 0; c < NC; c++)
        {
            fscanf(f, "%f", &a[r][c]);
        }
     }
     fclose(f);

     printf("\nДанные, загруженные в массив из файла:\n");
     // показать прочитанные данные
     for ( r = 0; r < NR; r++)
     {
        for (c = 0; c < NC; c++)
        {
            printf("%7.2f  ", a[r][c]);
        }
        printf("\n");
     }

    printf("\nДля завершения нажмите <Enter>");
    getch();
}

