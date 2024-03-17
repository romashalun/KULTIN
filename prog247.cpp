// Выводит на экран содержимое файла
// имя которого указано пользователем
#include "stdio.h"
#include "conio.h"
#include "string.h"

#define  MAXLEN 80    // максимальная длина строки в файле
void main()
{
    char fname[40];   // имя файла
    FILE *а;         // текстовый файл

    char st[MAXLEN+2];// строка, прочитанная из файла
    int n = 0;        // кол-во строк, выведенных на экран
    char key;         // клавиша, нажатая пользователем

    puts("Просмотр текстового файла");
    puts("Введите полное имя файла и нажмите <Enter>");
    printf("->");
    scanf("%s",&fname);

    // Открыть файл в режиме чтения (r) текста (t)
    if ((f = fopen(fname, "rt")) == NULL)
    {
        printf("Ошибка при обращении к файлу %s\n", fname);
        getch();
        return;
    }

    clrscr();
    while (!feof(f))
    {
        fgets(st, MAXLEN, f);
        printf("%s", st);
        if (++n > 21)
        {
          printf("\nДля продолжения нажмите ");
          printf("любую клавишу...");
          key = getch();
          gotoxy(1,wherey()); // курсор в начало текущей строки
          delline;            // удалить сообщение "Для
                              // продолжения ..."
            n = 0;
        }
    }
    fclose(f);     // закрыть файл

    printf("\nДля завершения нажмите <Enter>");
    getch();
}

