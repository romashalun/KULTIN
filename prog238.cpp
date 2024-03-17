// Круговая диаграмма
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

#define PATHTODRIVER "c:\\borlandc\\bgi\\"

    #define N 4 // количество категорий

void krdiagr(char* *name, float* dol)
{
    int a1,a2;     // угол начала и конца сектора
    int color[4] = {BLUE, YELLOW, GREEN, RED};
    int x,y;       // координаты вывода легенды
    char st[25];   // изображение числа
    int i;

    // строим диаграмму
    a1 = 0;            // от оси ОХ
    x = 350; y = 100;  // левый верхний угол области легенды
    for (i = 0; i < N; i++)
    {
      // сектор
      a2 = a1 + 3.6 * dol[i];  // 1% - 3.6 градуса
      if (i == N-1) a2 = 360; // последний, по счету, сектор
      setfillstyle(SOLID_FILL, color[i]);
      sector(200,200,a1,a2,100,100);
      // pieslice(200,200,a1,a2,100);
      a1 = a2;  // следующий сектор - от конца текущего
      // легенда
      bar(x,y,x+30,y+10);
      rectangle(x,y,x+30,y+10);
      sprintf(st, "%s - %2.1f%\0", name[i], dol[i]);
      outtextxy(x+50,y,st);
      y += 20;
    }
}

void main(void)
{
    char *name[N] = {"Книги\0","Журналы\0",
                     "Канцтовары\0","Прочее\0"};
    float kol[N];  // количество для категории
    float dol[N];  // доля категории в общем количестве
    float sum = 0; // общее кол-во по всем категориям
    int i;

    int gdriver = DETECT; // драйвер
    int gmode;            // режим
    int errorcode;        // код ошибки

    // ввод исходных данных
    puts("Введите количество по каждой категории");
    for (i = 0; i < N; i++)
    {
      printf("%s -> ", name[i]);
      scanf("%f", &kol[i]);
      sum += kol[i];
    }

    // вычислим долю каждой категории в общей сумме
    for (i = 0; i < N; i++)
      dol[i] = kol[i]/sum*100;

    // инициализация графического режима
    initgraph(&gdriver, &gmode, PATHTODRIVER);
    errorcode = graphresult();

    if (errorcode == grOk)
    {
        krdiagr(name, dol);// строим диаграмму
        getch();
        closegraph(); // выход из графического режима
   }
   else {
        printf("Ошибка: %d\n", errorcode);
        puts("Для завершения нажмите <Enter>");
        getch();
   }
}

