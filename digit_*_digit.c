#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

/*
Welcome. In this kata, you are asked to square every digit of a number and concatenate them.

For example, if we run 9119 through the function, 811181 will come out, because 92 is 81 and 12 is 1. (81-1-1-81)

Example #2: An input of 765 will/should return 493625 because 72 is 49, 62 is 36, and 52 is 25. (49-36-35)

Note: The function accepts an integer and returns an integer.
*/

static int	ft_numlen(unsigned long long num)
{
	int	i;

	if (num == 0)
		return (1);
	i = 0;
	while (num > 0 || num < 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(unsigned long long n)
{
	int		len;
	char	*dizi;
	long	nbr;

	nbr = n;
	len = ft_numlen(nbr);
	if (n < 0)
	{
		len++;
		nbr = -nbr;
	}
	dizi = malloc(sizeof(char) * len + 1);
	if (!dizi)
		return (NULL);
	dizi[len] = '\0';
	while (nbr > 0)
	{
		dizi[--len] = nbr % 10 + 48;
		nbr /= 10;
	}
	if (n < 0)
		dizi[0] = '-';
	if (n == 0)
		dizi[0] = '0';
	return (dizi);
}

unsigned long long square_digits (long long n)
{
	char *arr = ft_itoa(n);
  	unsigned long long ret = 0;
  	int i = 0;
	int multiply;
  	while (arr[i])
	{
		multiply = (arr[i] - 48) * (arr[i] - 48);
		if (multiply > 9)
			ret *= 100;
		else
			ret *= 10;
		ret += multiply;
		i++;
	}
	return (ret);
}