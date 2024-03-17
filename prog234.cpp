// Столбчатая диаграмма
#include <graphics.h>
#include <stdio.h>
#include <conio.h>

#define PATHTODRIVER "c:\\borlandc\\bgi\\"

    char *mes[] ={"двоек\0","троек\0",
                 "четверок\0","пятерок\0"};

    int n[4];   // количество пятерок, четверок,
                // троек и двоек

    float p[4]; // процент каждой оценки
    
    int h[4];   // высота столбиков диаграмм

// ввод и обработка исходных данных
void obr()
{
    int s;      // всего оценок
    int m;      // номер максимального эл-та массива n
    int i;      // индекс массива

    puts("Введите исходные данные:");
    for (i = 3; i >= 0; i--)
    {
        printf("%s ->", mes[i]);
        scanf("%i", &n[i]);
    }
    
    // обработка
    s = 0;

    // всего оценок
    for (i = 0; i < 4; i++)
        s += n[i];

    // процент каждой оценки
    for (i = 0; i < 4; i++)
        p[i] = (float)n[i]/s*100;

    // вычислим высоту каждого столбика диаграммы,
    // но сначала определим, каких оценок больше
    m = 3; // пусть больше всего пятерок
    for (i = 2; i >= 0; i--)
        if (n[i] > n[m])  m = i;

    // Пусть количеству оценок, которых больше,
    // соответствует столбик высотой 200 пикселов.
    // Вычислим высоту остальных столбиков.
    for (i = 0; i < 4; i++)
        h[i] = 200 * n[i]/n[m];
}

// строит диаграмму
void diagr()
{
    int x,y; // координаты левого нижнего угла
             // столбика диаграммы
    int i;   // индекс массива

    // цвет столбиков
    int color[4] = {YELLOW, BLUE, GREEN, RED};
    char buf[10];

    outtextxy(40,50,"Результаты контрольной работы\0");
    rectangle(40,80,170,310);
    x = 50; y = 300; // левый нижний угол первого столбика
    // столбики диаграммы
    for (i = 3; i >= 0; i--)
    {
        setfillstyle(SOLID_FILL, color[i]);
        bar(x,y,x+10,y-h[i]); // столбик
        sprintf(buf,"%2.1f",p[i]);
        outtextxy(x,y-h[i]-10,buf);
        x += 20;
    }
    // численные значения
    x = 50;
    for (i = 3; i >= 0; i--)
    {
      setfillstyle(SOLID_FILL,color[i]);
      //bar(x,y,x+10,y-h[i]); // столбик
      //OutTextXY(x,y-h[i]-10,RealToStr(p[i],5,1)+'%\n");
      x = x+20;
    }
    // легенда
    x = 200;y = 100;
    for (i = 3; i >= 0; i--)
    {
      setfillstyle(SOLID_FILL,color[i]);
      bar(x,y,x+20,y+10); // столбик
      outtextxy(x+25,y,mes[i]);
      y += 20;
    }
}

void main()
{
   int gdriver = DETECT; // драйвер
   int gmode;            // режим
   int errorcode;        // код ошибки

   obr(); // ввод и обработка результатов

   initgraph(&gdriver, &gmode, PATHTODRIVER);
   errorcode = graphresult();

   if (errorcode == grOk)
     diagr();  // вывод диаграммы
   else
   {
      printf("Ошибка: %d\n", errorcode);
      puts("Для завершения программы нажмите <Enter>");
   }
   getch();
}

