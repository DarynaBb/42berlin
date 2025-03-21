#include "pipex.h"

char	*get_path_from_env(char **envp)
{
	int	i;
	char	*path;

	i = 0;
	while(envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = envp[i] + 5;
			return(ft_strdup(path));
		}
		i++;
	}
	return (NULL);
}

char	*build_command_path(char *dir, char *cmd)
{
	char	*full_path;
	int		len;

	len = ft_strlen(dir) + 1 + ft_strlen(cmd) + 1;
	full_path = malloc(len * sizeof(char));
	if(!full_path)
		return (NULL);
	ft_strlcpy(full_path, dir, len);
	ft_strlcat(full_path, "/", len);
	ft_strlcat(full_path, cmd, len);
	return (full_path);
}

char	*find_command_path(char *cmd, char **envp)
{
	char	*path_env;
	char	**paths;
	char 	*full_path;
	int		i;

	i = 0;
	path_env = get_path_from_env(envp);
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	free(path_env);
	while(paths[i])
	{
		full_path = build_command_path(paths[i], cmd);
		if (full_path && access(full_path, X_OK) == 0)
			return(free(paths), full_path);
		free(full_path);
		i++;
	}
	free(paths);
	return(NULL);
}