#include "get_next_line.h"

static void	*free_leftovers(char **leftovers)
{
	if (*leftovers)
	{
		free(*leftovers);
		*leftovers = NULL;
	}
	return (NULL);
}

static char	*read_and_update_leftovers(int fd, char **leftovers)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	char	*new_leftovers;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		new_leftovers = ft_strjoin(*leftovers, buffer);
		if (!new_leftovers)
		{
			free_leftovers(leftovers);
			return (NULL);
		}
		free_leftovers(leftovers);
		*leftovers = new_leftovers;
		if (ft_strchr(*leftovers, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read < 0)
	{
		return (free_leftovers(leftovers));
	}
	return (*leftovers);
}

static char	*extract_line(char **leftovers)
{
	char	*line;
	int		i;

	if (!*leftovers || **leftovers == '\0')
		return (NULL);
	i = 0;
	while ((*leftovers)[i] && (*leftovers)[i] != '\n')
		i++;
	if ((*leftovers)[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (free_leftovers(leftovers));
	ft_strlcpy(line, *leftovers, i + 1);
	return (line);
}

static char	*update_leftovers_after_line_extracting(char **leftovers)
{
	char	*new_leftovers;
	int		i;
	int		len;

	if (!*leftovers)
		return (NULL);
	i = 0;
	while ((*leftovers)[i] && (*leftovers)[i] != '\n')
		i++;
	if (!(*leftovers)[i])
		return (free_leftovers(leftovers));
	len = ft_strlen(*leftovers) - i;
	new_leftovers = (char *)malloc((len + 1) * sizeof(char));
	if (!new_leftovers)
		return (free_leftovers(leftovers));
	ft_strlcpy(new_leftovers, &(*leftovers)[i + 1], len + 1);
	free_leftovers(leftovers);
	return (new_leftovers);
}

char	*get_next_line(int fd)
{
	static char	*leftovers;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!read_and_update_leftovers(fd, &leftovers))
		return (NULL);
	line = extract_line(&leftovers);
	leftovers = update_leftovers_after_line_extracting(&leftovers);
	return (line);
}

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// int main(void)
// {
//     int fd;
//     char *line;
// 	fd = open("test.txt", O_RDONLY);
    


//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line);
//     }

//     if (line == NULL)
//     {
//         printf("Function returned NULL as expected.\n");
//     }
//     else
//     {
//         printf("Function did not return NULL.\n");
//     }
// 	close(fd);
//     return (0);
// }

// int main(int count, char *args[]) {
// 	int fd;
		
// 	if (args[1])
// 		fd = open(args[1], O_RDONLY);
//  	else
//   		fd = STDIN_FILENO;
// 	char *line;
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	if (line == NULL)
// 	{
// 		printf("Function returned NULL as expected.\n");
// 	}
// 	else
// 	{
// 		printf("Function did not return NULL.\n");
// 		}
// 	close(fd);
// 	return (0);
// }

// cc get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=42 -o get_next_line
