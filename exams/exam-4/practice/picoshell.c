#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>

int picoshell(char **cmds[])
{
	int cmd_count = 0;
	int fd[2];
	int prev_fd = -1;
	pid_t pid;

	while(cmds[cmd_count] != NULL) cmd_count++;

	for(int i = 0; i < cmd_count; i++)
	{
		if (i < cmd_count - 1)
		{
			if (pipe(fd) == -1)
			{
				if (prev_fd != -1) close(prev_fd);
				return 1;
			}
		}

		pid = fork();

		if (pid == -1)
		{
			if (prev_fd != -1) close(prev_fd);
			if (i < cmd_count - 1)
			{
				close(fd[0]);
				close(fd[1]);
			}
			return 1;
		}

		else if (pid == 0)
		{
			if (i > 0)
			{
				dup2(prev_fd, 0);
				close(prev_fd);
			}
			if (i < cmd_count - 1)
			{
				close(fd[0]);
				dup2(fd[1], 1);
				close(fd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}

		else
		{
			if (i > 0)
			{
				close(prev_fd);
			}
			if (i < cmd_count - 1)
			{
				close(fd[1]);
				prev_fd = fd[0];
			}
		}
	}

	if (prev_fd != -1) close(prev_fd);

	for (int i = 0; i < cmd_count; i++)
	{
		if (wait(NULL) == -1)
			return 1;
	}
	return 0;
}

// int main(int argc, char **argv)
// {
// 	int cmds_size = 1;

// 	for (int i = 1; i < argc; i++)
// 	{
// 		if(!strcmp(argv[i], "|"))
// 			cmds_size++;
// 	}

// 	char *cmds = calloc(cmds_size + 1, sizeof(char **));
// 	if (!cmds)
// 	{
// 		dprintf(2, "Malloc error: \n");
// 		return 1;
// 	}

// 	cmds[0] = argv + 1;
// 	int cmds_i = 1;

// 	for (int i = 1; i < argc; i++)
// 	{
// 		if (!strcmp(argv[i], "|"))
// 		{
// 			cmds[cmds_i] = argv+i+1;
// 			argv[i] = NULL;
// 			cmds_i++;
// 		}
// 	}
// 	int ret = picoshell(cmds);
// 	if (ret)
// 		perror("picoshell");
// 	free(cmds);
// 	return ret;
// 	}



// int close_fd(int pipes[][2], int cmd_count)
// {
// 	for (int i = 0; i < cmd_count; i++)
// 	{
// 		if(close(pipes[i][0]) == -1)
// 			return -1;
// 		if(close(pipes[i][1]) == -1)
// 			return -1;
// 	}
// 	return 0;
// }

// int picoshell(char **cmds[])
// {
// 	int cmd_count = 0;
// 	pid_t pid;

// 	while(cmds[cmd_count] != NULL) cmd_count++;
	
// 	int pipes[cmd_count - 1][2];
// 	for (int i = 0; i < cmd_count - 1; i++)
// 	{
// 		if (pipe(pipes[i]) == -1)
// 			return 1;
// 	}

// 	for (int i = 0; i < cmd_count; i++)
// 	{
// 		pid = fork();

// 		if (pid == -1)
// 			return (1);
// 		if (pid == 0)
// 		{
// 			if (i > 0)
// 			{
// 				if (dup2(pipes[i - 1][0], STDIN_FILENO) == -1)
// 					exit (1);
// 			}
// 			if (i < cmd_count - 1)
// 			{
// 				if (dup2(pipes[i][1], STDOUT_FILENO) == -1)
// 					exit (1);
// 			}
// 			if (close_fd(pipes, cmd_count - 1) == -1)
// 				exit (1);
// 			if (execvp(*cmds[i], cmds[i]) == -1)
// 				exit (1);
// 		}
// 	}

// 	if (close_fd(pipes, cmd_count - 1) == -1)
// 		return 1;
// 	for (int i = 0; i < cmd_count; i++) 
// 	{
// 		if (wait(NULL) == -1)
// 			return (1);
// 	}
// 	return (0);
// }

// int picoshell(char **cmds[])
// {
// 	int i = 0;
// 	int nmb_cmds = 0;
// 	pid_t id;

// 	while (cmds[i] != NULL)
// 	{
// 		nmb_cmds++;
// 		i++;
// 	}
// 	int pipes[nmb_cmds - 1][2];
// 	i = 0;
// 	while (i < nmb_cmds - 1)
// 	{
// 		if (pipe(pipes[i]) == -1)
// 			return 1;
// 		i++;
// 	}
// 	i = 0;
// 	while (i < nmb_cmds)
// 	{
// 		if ((id = fork()) == -1)
// 			return (1);
// 		if (id == 0)
// 		{
// 			if (i > 0)
// 			{
// 				if (dup2(pipes[i - 1][0], STDIN_FILENO) == -1)
// 					exit (1);
// 			}
// 			if (i < nmb_cmds - 1)
// 			{
// 				if (dup2(pipes[i][1], STDOUT_FILENO) == -1)
// 					exit (1);
// 			}
// 			if (close_unused_fd(pipes, nmb_cmds - 1) == -1)
// 				exit (1);
// 			if (execvp(*cmds[i], cmds[i]) == -1)
// 				exit (1);
// 		}
// 		i++;
// 	}
// 	if (close_unused_fd(pipes, nmb_cmds - 1) == -1)
// 		return 1;
// 	for (i = 0; i < nmb_cmds; i++) 
// 	{
// 		if (wait(NULL) == -1)
// 			return (1);
// 	}
// 	return (0);
// }

int main(int argc, char **argv)
{
	int cmds_size = 1;
	char ***cmds = NULL;
	int ret;

	// count pipes to deduce how many ***cmds, then malloc
	for (int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], "|"))
			cmds_size++;
	}
	cmds = calloc(cmds_size + 1, sizeof(char **));
	if (!cmds)
	{
		dprintf(2, "Malloc error: %m\n");
		return 1;
	}
	cmds[cmds_size] = NULL;

	cmds[0] = argv + 1;
	int cmds_i = 1;
	for (int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], "|"))
		{
			cmds[cmds_i] = argv + i + 1;
			argv[i] = NULL;
			cmds_i++;
		}
	}
	ret = picoshell(cmds);
	if (ret)
		perror("picoshell");
	free(cmds);
	return ret;
}