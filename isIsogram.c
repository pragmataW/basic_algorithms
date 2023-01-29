#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
An isogram is a word that has no repeating letters, consecutive or non-consecutive. Implement a function that determines whether a string that contains only letters is an isogram. Assume the empty string is an isogram. Ignore letter case.

Example: (Input --> Output)

"Dermatoglyphics" --> true "aba" --> false "moOse" --> false (ignore letter case)
*/

char *upperCase(const char *str)
{
    int i = 0;
    char *ret = (char *)calloc(strlen(str) + 1, sizeof(char));

    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            ret[i] = ((char)str[i]) - 32;
        else
            ret[i] = str[i];
        i++;
    }
    return (ret);
}

bool IsIsogram (const char *string) 
{
    int i = 0;
    int j;
    int checker = 0;
    char *upStr;
    
    upStr = upperCase(string);
    while (upStr[i])
    {
        j = i + 1;
        while (upStr[j])
        {
            if (upStr[i] == upStr[j])
                checker++;
            j++;
        }
        i++;
    }
    if (checker > 0)
    {
        free(upStr);
        return (false);
    }
    free(upStr);
    return (true);
}