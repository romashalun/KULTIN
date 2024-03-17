// Функция вычисляет доход по вкладу
float profit(float sum,     // сумма вклада
             float stavka,  // процентная ставка (годовых)
             int srok)      //срок вклада (дней)
{
    return(sum*(stavka/100/365)*srok); 
}

