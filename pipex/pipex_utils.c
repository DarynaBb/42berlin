#include "pipex.h"

void handle_error(const char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(1);
}

void validate_args(int count)
{ 
	if (count != 5)
	{
		handle_error("Usage: ./pipex file1 cmd1 cmd2 file2");
	}
}