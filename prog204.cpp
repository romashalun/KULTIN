// Функция Barrel2Ton пересчитывает
// цену за баррель в цену за тонну

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"

// пересчитывает цену за баррель
// в цену за тонну
float Barrel2Ton(float b)
{
    // b - цена барреля 
    float t; // цена тонны

    t = b* (1000/136.4);
    
    //return (t);

    // Вместо приведенных выше инструкций
    // можно написать: 
     return ( b* (1000/136.4) );
    //
}


void main()
{
    float barrel; // цена барреля
    float ton;    // цена тонны

    printf("\nЦена барреля-> ");
    scanf("%f", &barrel);

    ton = Barrel2Ton(barrel);

    printf("\Цена тонны:%6.2f", ton);
    
    printf("\nДля завершения нажмите <Enter>");
    getch();
}


