// Игра "21"
#include "stdio.h"
#include "conio.h"
#include "stdlib.h" // функция rand
#include "time.h"   // функция time


int koloda[12];     // колода карт
int karta();        // функция "выдает" карту из колоды

void main()
{
    int igrok = 0;  // очки игрока
    int comp = 0;   // очки компьютера
    char otv;       // ответ игрока
    time_t t;

    // создадим колоду
    for (int i=2; i <=11; i++)
        koloda[i] = 4;
    koloda[5] = 0; // "пятерок" в колоде нет

    // инициализация генератора случайных чисел
    srand((unsigned)time(&t));

    printf("\nИгра в карты до хорошего не доведет!\n");

    do
    {
        // карта игроку
        igrok += karta();

        // карта компьютеру
        if (igrok < 21)
            comp += karta();

        if (igrok < 21 && comp < 21)
        {
            printf("У вас %d\n",igrok);
            printf("Еще карту? (введите y или n) ");
            otv = getchar();

            // Игрок нажимает две клавиши: с буквой и <Enter>.
            // Предыдущий вызов getchar прочитал букву.
            // В буфере клавиатуры остался код
            // клавиши <Enter>. Прочитаем его.
            int b;
            b = getchar();
        }

    }
    while (igrok <= 21 && comp <= 21 && otv != 'n') ;

    if (igrok == 21 || (igrok < 21 && igrok > comp) 
                    || comp > 21)
        printf("Вы выиграли!\n");
    else
        printf("Вы проиграли!\n");

    printf ("У вас %d\n", igrok);
    printf ("У компьютера %d\n", comp);

    printf("Для завершения нажмите <Enter>");
    getch();
}

// выдает карту из колоды
int karta()
{
    int i;
    do
        i = rand() % 10 + 2;
    while (koloda[i] == 0);
    koloda[i]--;
    return i;
}

