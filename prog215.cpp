// Функция решения квадратного уравнения
#include "stdio.h"
#include "conio.h"
#include "math.h"

int kvadur(float a, float b, float c, // коэф-ты уравнения
            float *x1, float *x2)      // корни уравнения
    // значение функции - количество корней
    // или -1, если неверные исходные данные
{
    float d; // дискриминант

    if (a == 0) return(-1);

    d = b*b-4*a*c;
    if (d < 0)
    return(0);    // уравнение не имеет решения

    *x1 = (-b+sqrt(d))/(2*a);
    *x2 = (-b-sqrt(d))/(2*a);

    if (*x1 != *x2) return(2);
        else return(1);
}

// проверка работоспособности функции
void main()
{
    float a,b,c;  // коэффициенты уравнения
    float x1,x2;  // корни уравнения
    int n;        // кол-во корней

    puts("\nРешение квадратного уравнения");
    puts("Введите в одной строке коэффициенты и нажмите <Enter>");
    printf("->");
    scanf("%f%f%f", &a, &b, &c);
    switch (kvadur(a,b,c,&x1,&x2))
    {
        case -1: puts("Ошибка исходных данных.");
                 break;
        case 0:  puts("Уравнение не имеет решения.");
                 break;
        case 1:  printf("Корни одинаковые: x=%3.2f", x1);
                 break;
        case 2:  printf("x1=%3.2f x2=%3.2f", x1, x2);
    }

    puts("\nДля завершения работы нажмите <Enter>");
    getch();
}

