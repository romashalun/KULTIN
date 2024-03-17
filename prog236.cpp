// Столбчатая диаграмма
#include "stdio.h"
#include "conio.h"
#include "graphics.h"

#define HB 10 // максимальное количество значений
#define WS 300
#define HS 150

   char  head[40];    // заголовок
   float kurs[HB];    // данные
   char* date[HB][5]; // подписи данных - дата в формате dd.mm

   int nrec; // количество элементов данных (пар дата-курс)

   int dx;     // шаг по х
   int py[HB]; // y-координаты точек на графике

// ввод и обработка исходных данных
void  LoadData()
{

     FILE* f; // файл данных

     int i;

    if ( (f = fopen("c:\\borlandc\\cpp\\kurs.txt",
                     "rt")) == NULL)
    {
        printf("Ошибка доступа к файлу данных\n");
        getch();
        return;
    }

    // заголовок
    //fgets(head,sizeof(head),f);

    fscanf(f,"%s",head);
    printf("%s\n",head);

    i = 0;
    while ((! feof(f) ) && ( i < HB ))
    {
        fscanf(f,"%s",&date[i]);
        printf("%s\n",date[i]);

        fscanf(f,"%f",&kurs[i]);
        printf("%5.2f\n",kurs[i]);
        i++;
    }
    nrec = i;
    fclose(f);

    // обработка данных:

    // найти минимальный элемент массива
    float min = kurs[0];
    float max = kurs[0];

    for ( i = 1; i < nrec; i++ )
    {
        if ( kurs[i] < min)
            min = kurs[i];

        if ( kurs[i] > max)
            max = kurs[i];
     }

    // вычислить y-координаты точек
    for (i=0; i < nrec; i++)
        py[i] = (HS-20) * (kurs[i]- min)/(max - min)+2;

    return;
}

void Diagr()
{
    int x0, y0;
    int x;

    int dx;
    int i;

    char st[20];

    x0 = 10;
    y0 = HS + 20;
    dx = (WS - 2* x0)/ (nrec );

    outtextxy(x0,10, head ); // заголовок
    rectangle(1,1,WS,y0+10); // рамка

    // столбики
    x = x0;
    setfillstyle(SOLID_FILL,GREEN);
    for ( i = 0; i < nrec; i++)
    {
       bar(x,y0,x+dx,y0-py[i]);
       rectangle(x,y0,x+dx,y0-py[i]);
       x= x+dx;
    }

    // подписи данных
    x=x0;
    for ( i = 0; i < nrec; i++)
    {
       sprintf(st,"%5.2f", kurs[i]);
       outtextxy(x,y0 - py[i]-10,st);
       x= x+dx;
    }
}

void main(void)
{
   int gdriver = DETECT;
   int gmode;            
   int errorcode;        
   initgraph(&gdriver, &gmode, "c:\\borlandc\\bgi\\");
   errorcode = graphresult();

   if (errorcode != grOk)  
   {
      printf("Ошибка: %d\n", errorcode);
      puts("Для завершения нажмите <Enter>");
      getch();
      return;
   }

   LoadData(); // загрузить данные

   Diagr();    // построить диаграмму

   getch();
   closegraph();
}

