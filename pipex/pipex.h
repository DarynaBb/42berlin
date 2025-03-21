#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
// For open()
# include <fcntl.h>
// For close(), read(), write(), access(), dup(), dup2(), execve(), fork()
// pipe(), unlink()
# include <unistd.h>
// For malloc(), free(), exit()
# include <stdlib.h>
// For perror()
# include <stdio.h>
// For wait(), waitpid()
# include <sys/wait.h>
// For errno
// # include <errno.h>

//pipex_utils
void	handle_error(const char *msg);
void	validate_args(int count);

//path_utils
char	*find_command_path(char *cmd, char **env);

//execute
void	execute_command(char *cmd, char **env);

#endif