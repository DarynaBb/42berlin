#include <unistd.h>

int	ft_strlen(char *s)
{
	int	len = 0;
	while(s[len])
		len++;
	return len;
}

int count_unbalance(char *s)
{
	int i = 0;
	int open = 0;
	int close = 0;

	while(s[i])
	{
		if (s[i] == '(')
			open++;
		else if (s[i] == ')')
		{
			if (open > 0)
				open--;
			else
				close++;
		}
		i++;
	}
	return (open + close);
}
