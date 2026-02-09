#include <unistd.h>

int ft_strlen(char *s)
{
	int i = 0;
	while(s[i])
		i++;
	return i;
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
	return (close + open);
}

void print_solution(char *s, int *remove_pos, int remove_count)
{
	int i = 0;
	
	while(s[i])
	{
		int j = 0;
		int should_skip = 0;
		
		while(j < remove_count)
		{
			if (i == remove_pos[j])
			{
				should_skip = 1;
				break;
			}
			j++;
		}
		if (!should_skip)
			write(1, &s[i], 1);
		else
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

void check_combi(char *s, int *remove_pos, int remove_count)
{
	int i = 0;
	int j = 0;
	char temp[1000];

	while(s[i])
	{
		int k = 0;
		int should_skip = 0;
		
		while (k < remove_count)
		{
			if (i == remove_pos[k])
			{
				should_skip = 1;
				break;
			}
			k++;
		}
		if (!should_skip)
		{
			temp[j] = s[i];
			j++;
		}
		i++;
	}
	temp[j] = '\0';
	if (count_unbalance(temp) == 0)
		print_solution(s, remove_pos, remove_count);
}

void try_combi(char *s, int *remove_pos, int remove_count, int len, int selected_pos, int start)
{
	if (selected_pos == remove_count)
	{
		check_combi(s, remove_pos, remove_count);
		return;
	}
	
	int i = start;
	while (i < len)
	{
		remove_pos[selected_pos] = i;
		try_combi(s, remove_pos, remove_count, len, selected_pos + 1, i + 1);
		i++;
	}
}

void solve(char *s)
{
	int len = ft_strlen(s);
	int remove_count = count_unbalance(s);
	
	if (remove_count == len)
	{
		int i = 0;
		while(s[i])
		{
			write(1, " ", 1);
			i++;
		}
		write(1, "\n", 1);
		return;
	}
	int remove_pos[1000] = {0};
	try_combi(s, remove_pos, remove_count, len, 0, 0);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;	
	char *s = argv[1];
	
	if (count_unbalance(s) == 0)
	{
		int i = 0;
		while(s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
		write(1, "\n", 1);
		return 1;
	}
	solve(s);
	return 0;
}
