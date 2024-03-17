// Дописывает в файл contacts.txt фамилию, имя и номер телефона
#include "stdio.h"
#include "conio.h"

#define FNAME "contacts.txt\0" // имя файла
void main()
{
    char fname[20] = FNAME;
    FILE *f;  // файл

    char fam[15];  // фамилия
    char name[15]; // имя
    char tel[9];   // номер телефона

    puts("\nДобавление информации в телефонный справочник\n");

    // Открыть файл в режиме добавления (а) текста (t)
    // Если файла с таким именем нет, то он будет создан
    if ((out = fopen(fname, "at")) == NULL)
    {
        printf("Ошибка открытия файла для добавления");
        getch();
        return;
    }

    // получим данные от пользователя
    printf("Фамилия ->");
    scanf("%s", &fam);
    printf("Имя ->");
    scanf("%s", &name);
    printf("Телефон ->");
    scanf("%s", &tel);
    // и запишем их в файл
    fprintf(f,"%s %s %s", fam, name, tel);
    puts("\nИнформация добавлена");
    fclose(f);     // закрыть файл

    printf("\n\nДля завершения нажмите <Enter>\n");
    getch(); 
}

