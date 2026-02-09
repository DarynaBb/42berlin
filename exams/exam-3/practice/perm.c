#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

int ft_strlen(char *s)
{
	int i = 0;
	while(s[i])
		i++;
	return i;
}

void bubble_sort(char *set, int size)
{
	char temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (set[j] > set[j+1])
			{
				temp = set[j];
				set[j] = set[j+1];
				set[j+1] = temp;
			}
		}
	}
}

void process(char *set, char *temp, bool *placed, int size, int index)
{
	if (size == index)
	{
		printf("%d\n", ft_strlen(temp));
		write(1, temp, ft_strlen(temp));
		write(1, "\n", 1);
		return;
	}
	for (int i = 0; i < size; i++)
	{
		if (placed[i])
			continue;
		temp[index] = set[i];
		placed[i] = true;
		process(set, temp, placed, size, index + 1);
		placed[i] = false;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;

	int size = ft_strlen(argv[1]);
	char set[size];
	char temp[size+1];
	bool placed[size];

	for (int i = 0; i < size; i++)
	{
		set[i] = argv[1][i];
		placed[i] = false;
	}
	bubble_sort(set, size);
	process(set, temp, placed, size, 0);
	return 0;
}
