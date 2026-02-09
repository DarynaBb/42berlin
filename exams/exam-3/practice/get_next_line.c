#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
	size_t i = 0;
	while(s[i])
		i++;
	return i;
}

char *ft_strjoin(const char *s1, const char *s2)
{
	char *str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return NULL;
	size_t i = 0;
	size_t j = 0;

	while(s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while(s2[j])
	{
		str[i+j] = s2[j];
		j++;
	}
	str[i+j] = '\0';
	return str;
}

char *ft_substr(char *s, unsigned int start, size_t len)
{
	if (!s)
		return NULL;
	size_t size = ft_strlen(s);
	size_t i = 0;

	if (start > size)
		len = 0;
	if (size - start < len)
		len = size - start;
	
	char *str = malloc(len + 1);
	if (!str)
		return NULL;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return str;
}

char *ft_strchr(const char *s, int c)
{
	c = (unsigned char)c;
	size_t i = 0;

	while(s[i])
	{
		if (s[i] == c)
			return (char *)&s[i];
		i++;
	}
	if (c == '\0')
		return (char *)&s[i];
	return NULL;
}

char *ft_strdup(const char *s)
{
	char *str = malloc(ft_strlen(s) + 1);
	if (!str)
		return NULL;
	size_t i = 0;
	while(s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return str;
}

char *read_data(char *buffer, char *str, int fd)
{
	char *temp;
	size_t bytes_read;

	while (!ft_strchr(str, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0 && str[0] == '\0')
		{
			free(str);
			return NULL;
		}
		if (bytes_read <= 0)
			return str;
		buffer[bytes_read] = '\0';
		temp = str;
		str = ft_strjoin(temp, buffer);
		free(temp);
	}
	return str;
}

char *get_line(char *str, size_t *line_init)
{
	char *line;
	size_t i = 0;

	while(str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		*line_init = i + 1;
	else
		*line_init = i;
	line = ft_substr(str, 0, *line_init);
	return line;
}

char *update_str(char *str, size_t line_init)
{
	char *new_str;
	size_t len = ft_strlen(str) - line_init;
	
	if (len <= 0)
	{
		free(str);
		return NULL;
	}

	new_str = ft_substr(str, line_init, len);
	free(str);
	return new_str;
}

char *get_next_line(int fd)
{
	char *buffer;
	char *line;
	static char *str;
	size_t line_init;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return NULL;
	if (!str)
		str = ft_strdup("");
	str = read_data(buffer, str, fd);
	if (!str)
	{
		free(buffer);
		return NULL;
	}
	line = get_line(str, &line_init);
	if (!line)
	{
		free(buffer);
		return NULL;
	}
	str = update_str(str, line_init);
	free(buffer);
	return line;
}
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd;
	char *line;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return 1;
	line = get_next_line(fd);
	while(line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return 0;

}