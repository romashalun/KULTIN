// Поиск в телефонном справочнике
#include "stdio.h"
#include "conio.h"

#define FNAME "contacts.txt\0" // имя файла
void main()
{
    char fname[20] = FNAME;
    FILE *f;  // файл - телефонный справочник

    char obr[15];  // фамилия - образец для поиска в БД

    // найденная информация
    char fam[15];  // фамилия
    char name[15]; // имя
    char tel[9];   // номер телефона

    int n = 0; // количество записей, удовлетворяющих запросу

    puts("\nПоиск в телефонном справочнике");

    // Открыть файл в режиме чтения (r) текста (t)
    if ((f = fopen(fname, "rt")) == NULL)
    {
        printf("Ошибка открытия файла %s", fname);
        getch();
        return;
    }

    // получим данные от пользователя
    printf("Фамилия ->");
    scanf("%s", &obr);   // образец для поиска в БД
    while (!feof(f))
    {
        fscanf(f,"%s %s %s", &fam, &name, &tel);
        if (fam == obr)
        {
            printf("%s %s %s",fam, name, tel);
            n++;
        }
    }
    if (n )
        printf("Найдено записей: %i", n);
    else
        printf("Данных об абоненте %s в БД нет", obr);

    fclose(f);     // закрыть файл

    puts("\nДля завершения работы нажмите <Enter>");
    getch(); 
}

