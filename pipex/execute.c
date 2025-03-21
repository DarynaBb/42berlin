#include "pipex.h"

void	execute_command(char *cmd, char **envp)
{
	char	*cmd_path;
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args || !cmd_args[0])
	{
		ft_putstr_fd("Command not found\n", 2);
		exit(127);
	}
	cmd_path = find_command_path(cmd_args[0], envp);
	if (!cmd_path)
	{
		ft_putstr_fd("Command not found\n", 2);
		exit(127);
	}
	execve(cmd_path, cmd_args, envp);
	perror("execve failed");
	exit(1);
}