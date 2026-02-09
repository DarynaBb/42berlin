#define _GNU_SOURCE
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 2048
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#endif

char *replace(size_t len)
{
	size_t i = 0;
	char *replace = malloc(len +1);
	if (!replace)
	{
		perror("Error");
		return NULL;
	}
	while (i < len)
	{
		replace[i] = '*';
		i++;
	}
	replace[i] = '\0';
	return replace;
}

char *read_data()
{
	char *buffer;
	ssize_t bytes_read = 0;
	ssize_t buffer_used = 0;
	ssize_t buffer_size = BUFFER_SIZE;

	buffer = malloc(buffer_size);
	if (!buffer)
	{
		perror("Error");
		return NULL;
	}
	while(1)
	{
		if (buffer_used >= buffer_size - 1)
		{
			buffer_size *= 2;
			buffer = realloc(buffer, buffer_size);
			if (!buffer)
			{
				perror("Error:");
				return NULL;
			}
		}
		bytes_read = read(0, buffer + buffer_used, buffer_size - buffer_used - 1);
		if (bytes_read == 0)
			break;
		if (bytes_read < 0)
		{
			perror("Error");
			return NULL;
		}
		buffer_used += bytes_read;
	}
	buffer[buffer_used] = '\0';
	return buffer;
}

void clean(char *buffer, char *replace)
{
	if (buffer)
		free(buffer);
	if(replace)
		free(replace);
}

int safe_write(char *data, size_t len)
{
	if (len == 0)
		return 0;
	if (write(1, data, len) < 0)
	{
		perror("Error");
		return 1;
	}
	return 0;
}

int print(char *buffer, char *filter, char *replace)
{
	char *found;
	char *current = buffer;
	
	while((found = memmem(current, strlen(current), filter, strlen(filter)))!= NULL)
	{
		if (safe_write(current, found - current))
			return 1;
		if (safe_write(replace, strlen(filter)))
			return 1;
		current = found + strlen(filter);
	}
	if (safe_write(current, strlen(current)))
		return 1;
	return 0;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage");
		return 1;
	}
	char *filter = argv[1];
	size_t len = strlen(argv[1]);
	char *replac = replace(len);
	if (!replac)
		return 1;
	char *buffer = read_data();
	if (!buffer)
	{
		clean(buffer, replac);
		return 1;
	}
	if (print(buffer, filter, replac))
	{
		clean(buffer, replac);
		return 1;
	}
	clean(buffer, replac);
	return 0;
	
}
