#include <stdlib.h>
#include <string.h>

/*
The goal of this exercise is to convert a string to a new string where each character in the new string is "(" if that character
appears only once in the original string, or ")" if that character appears more than once in the original string.
Ignore capitalization when determining if a character is a duplicate.

"din"      =>  "((("
"recede"   =>  "()()()"
"Success"  =>  ")())())"
"(( @"     =>  "))((" 

*/
char	*DuplicateEncoder (const char *string)
{
	int	i = 0;
	int	j;
	int checker;
	char *ret = (char *)calloc(strlen(string) + 1, sizeof(char));

	while (string[i])
	{
		j = 0;
		checker = 0;
		while(string[j])
		{
			if (string[i] >= 'A' && string[i] <= 'Z')
			{
				if (string[i] == string[j] || string[i] == string[j] - 32)
					checker++;
			}
			else if(string[i] >= 'a' && string[i] <= 'z')
			{
				if (string[i] == string[j] || string[i] == string[j] + 32)
					checker++;
			}
			else
			{
				if (string[i] == string[j])
					checker++;
			}
			j++;
		}
		if (checker > 1)
			ret[i] = ')';
		else
			ret[i] = '(';
		i++;
	}
	return (ret);
}