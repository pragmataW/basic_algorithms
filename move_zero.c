#include <stddef.h>
#include <stdlib.h>

/*
Write an algorithm that takes an array and moves all of the zeros to the end, preserving the order of the other elements.

move_zeros(10, int [] {1, 2, 0, 1, 0, 1, 0, 3, 0, 1}); // -> int [] {1, 2, 1, 1, 3, 1, 0, 0, 0, 0}
*/

void move_zeros(size_t len, int arr[len])
{
	int *ret = malloc(sizeof(int) * len);
	int i = 0;
	int j = 0;
	int counter = 0;

	while (i < len)
	{
		if (arr[i] != 0)
			counter++;
		i++;
	}

	i = 0;
	while (i < len)
	{
		ret[i] = 0;
		i++;
	}

	i = 0;
	while (i < len)
	{
		if (arr[i] != 0)
		{
			ret[j] = arr[i];
			j++;
		}
		i++;
	}

	i = 0;
	while (i < len)
	{
		arr[i] = ret[i];
		i++;
	}

}
