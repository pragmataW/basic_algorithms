/*Write a function that accepts an array of 10 integers (between 0 and 9), that returns a string of those numbers in the form of a phone number.

Example
create_phone_number(phnum, (const unsigned char[]){1,2,3,4,5,6,7,8,9,0});
    phnum <- "(123) 456-7890" 
The returned format must be correct in order to complete this challenge.*/

//Don't forget the space after the closing parentheses!

#include <stdio.h>
#include <stdlib.h>

char *create_phone_number(char phnum[15], const unsigned char nums[10])
{
    int i = 0;
    int j = 1;
    phnum[0] = '(';
    phnum[4] = ')';
    phnum[5] = ' ';
    phnum[9] = '-';

    while (i < 10)
    {
        if (j == 4 || j == 5 || j == 9)
        {
            j++;
            continue;
        }
        phnum[j] = nums[i] + 48;
        i++;
        j++;
        phnum[14] = '\0';
    }
    return (phnum);
}