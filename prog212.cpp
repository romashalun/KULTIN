// Функция проверяет, является ли символ гласной буквой
int glasn(char ch)
{
    static char gl[] ="АаЕеИиОоУуЫыЭэЮюЯя\0";
    int i = 0;

    while (gl[i] && gl[i] != ch)
        i++;
    if ( gl[i] )
       return(1);
    else return(0);
}

