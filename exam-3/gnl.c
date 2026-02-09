#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

#include <stdlib.h>
#include <unistd.h>

#endif

size_t ft_strlen(char *s)
{
	size_t len = 0;
	while (s[len])
		len++;
	return len;
}

char *ft_strjoin(const char *s1, const char *s2)
{
	size_t i = 0;
	size_t j = 0;
	char *str;

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return NULL;
	while(s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return str;
}

char *ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t size = ft_strlen(s);
	char *str;

	if (!s)
		return NULL;
	if (start > size)
		len = 0;
	if (size - start < len)
		len = size - start;
	str = malloc(sizeof(char) * (len +1));
	if (!str)
		return NULL;
	size_t i = 0;
	while(i < len)
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
	size_t i = 0;
	size_t len = ft_strlen(s);
	char *str;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return NULL;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return str;
}
