#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
Your task is to sort a given string. Each word in the string will contain a single number. This number is the position the word 
should have in the result.

Note: Numbers can be from 1 to 9. So 1 will be the first word (not 0).

If the input string is empty, return an empty string. The words in the input String will only contain valid consecutive numbers.


"is2 Thi1s T4est 3a"  -->  "Thi1s is2 3a T4est"
"4of Fo1r pe6ople g3ood th5e the2"  -->  "Fo1r the2 g3ood 4of th5e pe6ople"
""  -->  ""
*/

//*algoritmasi: 
//* Kaç kelime olduğunu bul
//*char order = '1', '2' yaparak sürekli döngü içerisinde kaçı aradığını bul
//*üstteki döngü order <= Kelime sayısı iken çalışsın
//*içerideki döngüde stringin içerisinde sürekli gezin
//*o sayıyı görene kadar dizide ilerle
//*gördüğünde boşluk görene kadar geri ilerle
//*sonra ordered stringe yazdır ta ki diğer boşluğu görene kadar.


int word_counter (const char *words)
{
    int i = 0;
    int ret = 0;
    while (words[i])
    {
        if (words[i] == ' ')
            ret++;
        i++;
    }
    return (ret + 1);
}

char *order_words (char *ordered, const char *words)
{
    int i;
    int j = 0;
    char order = '1';
    char word_count = word_counter(words) + 48;
    
    while (order <= word_count)
    {
        i = 0;
        while (words[i])
        {
            if (words[i] == order)
            {
                while(words[i] != ' ' && i > 0)
                    i--;
                if(i != 0)
                    i++;
                while (words[i] != ' ' && words[i] != '\0')
                {
                    ordered[j] = words[i];
                    j++;
                    i++;
                }
                if (order != word_count)
                {
                    ordered[j] = ' ';
                    j++;
                }
                break;
            }
            i++;
        }
        order++;
    }
    ordered[j] = '\0';
    return (ordered);
}
