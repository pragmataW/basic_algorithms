#include <stddef.h>

/*
Given an array of integers, find the one that appears an odd number of times.

There will always be only one integer that appears an odd number of times.

Examples
[7] should return 7, because it occurs 1 time (which is odd).
[0] should return 0, because it occurs 1 time (which is odd).
[1,1,2] should return 2, because it occurs 1 time (which is odd).
[0,1,0,1,0] should return 0, because it occurs 3 times (which is odd).
[1,2,2,3,3,3,4,3,3,3,2,2,1] should return 4, because it appears 1 time (which is odd).
*/

int find_odd (size_t length, const int array[length])
{
    size_t i = 0;
    size_t j;
    int checker;

    while (i <= length)
    {
        j = 0;
        checker = 1;

        while(j < length)
        {
            if (i == j)
            {
                j++;
                continue;
            }
            if (array[j] == array[i])
                checker++;
            j++;
        }
        if (checker % 2 == 1)
            return (array[i]);
        i++;
    }
    return (0);
}
